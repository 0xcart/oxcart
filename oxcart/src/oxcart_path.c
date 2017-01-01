/**
 * oxcart is licensed under the terms of the MIT license reproduced below.
 * 
 * Copyright © 2016 Thomas J. Schaefer
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the "Software"), to deal in 
 * the Software without restriction, including without limitation the rights to 
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdlib.h>
#include "oxcart_assert.h"
#include "oxcart_gl.h"
#include "oxcart_math.h"
#include "oxcart_path.h"
#include "oxcart_shader.h"
#include "oxcart_util.h"
#include "oxcart_vector.h"

#define OXCART_PATH_COMMAND_MOVETO   0
#define OXCART_PATH_COMMAND_LINETO   1
#define OXCART_PATH_COMMAND_BEZIERTO 2
#define OXCART_PATH_COMMAND_CLOSE    3
#define OXCART_PATH_COMMAND_WINDING  4
#define OXCART_PATH_POINT_CORNER     0x01
#define OXCART_PATH_POINT_LEFT       0x02
#define OXCART_PATH_POINT_BEVEL      0x04
#define OXCART_PATH_POINT_INNERBEVEL 0x08

typedef struct oxcart_pathclip_t oxcart_pathclip_t;
typedef struct oxcart_pathpath_t oxcart_pathpath_t;
typedef struct oxcart_pathpoint_t oxcart_pathpoint_t;
typedef struct oxcart_pathshader_t oxcart_pathshader_t;
typedef struct oxcart_pathstate_t oxcart_pathstate_t;
typedef struct oxcart_pathuniform_t oxcart_pathuniform_t;
typedef struct oxcart_pathvertex_t oxcart_pathvertex_t;
typedef struct oxcart_pathmodule_t oxcart_pathmodule_t;

struct oxcart_pathclip_t
{
  oxcart_vec2f_t extent;
  oxcart_mat3f_t transform;
};

struct oxcart_pathpath_t
{
  int value;
};

struct oxcart_pathpoint_t
{
  int value;
};

struct oxcart_pathshader_t
{
  GLuint program;
  GLuint camera;
  GLuint path;
  GLint model;
  GLint sampler;
};

struct oxcart_pathstate_t
{
  int linecap;
  int linejoin;
  float miterlimit;
  float globalalpha;
  float strokewidth;
  oxcart_vec4f_t strokecolor;
  oxcart_vec4f_t fillcolor;
  oxcart_pathclip_t clip;
  oxcart_mat3f_t transform;
};

struct oxcart_pathuniform_t
{
  float value;
};

struct oxcart_pathvertex_t
{
  oxcart_vec2f_t vertex;
  oxcart_vec2f_t texcoord;
};

struct oxcart_path_t
{
  oxcart_vector_t* states;
  oxcart_vector_t* commands;
  oxcart_vector_t* points;
  oxcart_vector_t* paths;
  oxcart_vector_t* vertices;
  oxcart_vec4f_t bounds;
};

struct oxcart_pathmodule_t
{
  oxcart_pathshader_t shader;
};

static void _path_appendcommand(oxcart_path_t* path, float* values, int count);
static void _path_reset(oxcart_path_t* path);
static void _path_transformpoint(oxcart_path_t* path, float x, float y, float* tx, float* ty);
static void _path_loadshader();

static oxcart_pathmodule_t _m = {0};

/**
 * 
 */
void oxcart_path_initialize()
{
  _path_loadshader();
}

/**
 * 
 */
void oxcart_path_terminate()
{
  oxcart_program_destroy(_m.shader.program);
}

/**
 * 
 */
oxcart_path_t* oxcart_path_create()
{
  oxcart_path_t* path;

  if (!(path = (oxcart_path_t*)malloc(sizeof(oxcart_path_t)))) {
    OXCART_ASSERT(!"malloc() failed");
  }

  path->states = oxcart_vector_create(sizeof(oxcart_pathstate_t), 32);
  path->commands = oxcart_vector_create(sizeof(float), 256);
  path->points = oxcart_vector_create(sizeof(oxcart_pathpoint_t), 128);
  path->paths = oxcart_vector_create(sizeof(oxcart_pathpath_t), 16);
  path->vertices = oxcart_vector_create(sizeof(oxcart_pathvertex_t), 256);

  _path_reset(path);

  return(path);
}

/**
 * 
 */
void oxcart_path_destroy(oxcart_path_t* path)
{
  OXCART_ASSERT(path);

  oxcart_vector_destroy(path->vertices);
  oxcart_vector_destroy(path->paths);
  oxcart_vector_destroy(path->points);
  oxcart_vector_destroy(path->commands);
  oxcart_vector_destroy(path->states);

  free(path);
}

/**
 * 
 */
void oxcart_path_beginframe(oxcart_path_t* path)
{
  OXCART_ASSERT(path);

  _path_reset(path);
}

/**
 * 
 */
void oxcart_path_endframe(oxcart_path_t* path)
{
  OXCART_ASSERT(path);
}

/**
 * 
 */
void oxcart_path_save(oxcart_path_t* path)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  oxcart_vector_pushback(path->states, state);
}

/**
 * 
 */
void oxcart_path_restore(oxcart_path_t* path)
{
  OXCART_ASSERT(path);

  if (oxcart_vector_size(path->states) > 1) {
    oxcart_vector_popback(path->states);
  }
}

/**
 * 
 */
void oxcart_path_setlinecap(oxcart_path_t* path, int linecap)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT((linecap == OXCART_PATH_LINECAP_BUTT) || (linecap == OXCART_PATH_LINECAP_ROUND) || (linecap == OXCART_PATH_LINECAP_SQUARE));

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->linecap = linecap;
}

/**
 * 
 */
void oxcart_path_setlinejoin(oxcart_path_t* path, int linejoin)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT((linejoin == OXCART_PATH_LINEJOIN_MITER) || (linejoin == OXCART_PATH_LINEJOIN_ROUND) || (linejoin == OXCART_PATH_LINEJOIN_BEVEL));

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->linejoin = linejoin;
}

/**
 * 
 */
void oxcart_path_setmiterlimit(oxcart_path_t* path, float limit)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT(limit > 0.0f);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->miterlimit = limit;
}

/**
 * 
 */
void oxcart_path_setglobalalpha(oxcart_path_t* path, float alpha)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);

  alpha = oxcart_clampf(alpha, 0.0f, 1.0f);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->globalalpha = alpha;
}

/**
 * 
 */
void oxcart_path_setstrokewidth(oxcart_path_t* path, float width)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT(width > 0.0f);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->strokewidth = width;
}

/**
 * 
 */
void oxcart_path_setstrokecolor(oxcart_path_t* path, const oxcart_vec4f_t* color)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT(color);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->strokecolor = *color;
}

/**
 * 
 */
void oxcart_path_setfillcolor(oxcart_path_t* path, const oxcart_vec4f_t* color)
{
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT(color);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);
  state->fillcolor = *color;
}

/**
 * 
 */
void oxcart_path_beginpath(oxcart_path_t* path)
{
  OXCART_ASSERT(path);

  oxcart_vector_clear(path->commands);
  oxcart_vector_clear(path->points);
  oxcart_vector_clear(path->paths);
}

/**
 * 
 */
void oxcart_path_closepath(oxcart_path_t* path)
{
  float command[1];

  OXCART_ASSERT(path);

  command[0] = OXCART_PATH_COMMAND_CLOSE;

  _path_appendcommand(path, command, OXCART_ARRAY_SIZE(command));
}

/**
 * 
 */
void oxcart_path_setpathwinding(oxcart_path_t* path, int winding)
{
  float command[2];

  OXCART_ASSERT(path);
  OXCART_ASSERT((winding == OXCART_PATH_WINDING_CCW) || (winding == OXCART_PATH_WINDING_CW));

  command[0] = OXCART_PATH_COMMAND_WINDING;
  command[1] = (float)winding;

  _path_appendcommand(path, command, OXCART_ARRAY_SIZE(command));
}

/**
 * 
 */
void oxcart_path_moveto(oxcart_path_t* path, float x, float y)
{
  float command[3];

  OXCART_ASSERT(path);

  command[0] = OXCART_PATH_COMMAND_MOVETO;
  command[1] = x;
  command[2] = y;

  _path_appendcommand(path, command, OXCART_ARRAY_SIZE(command));
}

/**
 * 
 */
void oxcart_path_lineto(oxcart_path_t* path, float x, float y)
{
  float command[3];

  OXCART_ASSERT(path);

  command[0] = OXCART_PATH_COMMAND_LINETO;
  command[1] = x;
  command[2] = y;

  _path_appendcommand(path, command, OXCART_ARRAY_SIZE(command));
}

/**
 * 
 */
void oxcart_path_bezierto(oxcart_path_t* path, float cx1, float cy1, float cx2, float cy2, float x, float y)
{
  float command[7];

  OXCART_ASSERT(path);

  command[0] = OXCART_PATH_COMMAND_BEZIERTO;
  command[1] = cx1;
  command[2] = cy1;
  command[3] = cx2;
  command[4] = cy2;
  command[5] = x;
  command[6] = y;

  _path_appendcommand(path, command, OXCART_ARRAY_SIZE(command));
}

/**
 * 
 */
static void _path_appendcommand(oxcart_path_t* path, float* values, int count)
{
  int i = 0;

  OXCART_ASSERT(path);
  OXCART_ASSERT(values);
  OXCART_ASSERT(count > 0);

  while (i < count) {
    switch ((int)values[i])
    {
      case OXCART_PATH_COMMAND_MOVETO:
      case OXCART_PATH_COMMAND_LINETO:
        OXCART_ASSERT((count - i) >= 3);
        _path_transformpoint(path, values[i + 1], values[i + 2], &values[i + 1], &values[i + 2]);
        i += 3;
        break;
      case OXCART_PATH_COMMAND_BEZIERTO:
        OXCART_ASSERT((count - i) >= 7);
        _path_transformpoint(path, values[i + 1], values[i + 2], &values[i + 1], &values[i + 2]);
        _path_transformpoint(path, values[i + 3], values[i + 4], &values[i + 3], &values[i + 4]);
        _path_transformpoint(path, values[i + 5], values[i + 6], &values[i + 5], &values[i + 6]);
        i += 7;
        break;
      case OXCART_PATH_COMMAND_CLOSE:
        OXCART_ASSERT((count - i) >= 1);
        i += 1;
        break;
      case OXCART_PATH_COMMAND_WINDING:
        OXCART_ASSERT((count - i) >= 2);
        i += 2;
        break;
      default:
        OXCART_ASSERT(!"Invalid path command");
        break;
    }
  }

  oxcart_vector_pushbackv(path->commands, values, count);
}

/**
 * 
 */
static void _path_reset(oxcart_path_t* path)
{
  oxcart_pathstate_t state;

  OXCART_ASSERT(path);

  state.linecap = OXCART_PATH_LINECAP_BUTT;
  state.linejoin = OXCART_PATH_LINEJOIN_MITER;
  state.miterlimit = 10.0f;
  state.globalalpha = 1.0f;
  state.strokewidth = 1.0f;
  state.strokecolor = oxcart_vec4f_rgba(0, 0, 0, 255);
  state.fillcolor = oxcart_vec4f_rgba(255, 255, 255, 255);
  state.clip.extent = oxcart_vec2f_set(-1.0f, -1.0f);
  state.clip.transform = oxcart_mat3f_identity();
  state.transform = oxcart_mat3f_identity();

  oxcart_vector_clear(path->states);
  oxcart_vector_pushback(path->states, &state);
}

/**
 * 
 */
static void _path_transformpoint(oxcart_path_t* path, float x, float y, float* tx, float* ty)
{
  oxcart_vec3f_t vec3;
  oxcart_pathstate_t* state;

  OXCART_ASSERT(path);
  OXCART_ASSERT(tx);
  OXCART_ASSERT(ty);

  state = (oxcart_pathstate_t*)oxcart_vector_back(path->states);

  vec3 = oxcart_vec3f_set(x, y, 1.0f);
  vec3 = oxcart_vec3f_transform(&vec3, &state->transform);
  *tx = OXCART_VEC_X(vec3);
  *ty = OXCART_VEC_Y(vec3);
}

/**
 * 
 */
static void _path_loadshader()
{
  GLuint shader[2];

  shader[0] = oxcart_shader_createwithfile("/shader/oxcart_path.vert", GL_VERTEX_SHADER);
  shader[1] = oxcart_shader_createwithfile("/shader/oxcart_path.frag", GL_FRAGMENT_SHADER);
  _m.shader.program = oxcart_program_create(shader, OXCART_ARRAY_SIZE(shader));
  oxcart_shader_destroy(shader, OXCART_ARRAY_SIZE(shader));

  glBindAttribLocation(_m.shader.program, OXCART_SHADER_ATTRIB_LOCATION_VERTEX, "vertex");
  glBindAttribLocation(_m.shader.program, OXCART_SHADER_ATTRIB_LOCATION_TEXCOORD, "texcoord");

  oxcart_program_link(_m.shader.program);

  _m.shader.camera = glGetUniformBlockIndex(_m.shader.program, "camera");
  _m.shader.path = glGetUniformBlockIndex(_m.shader.program, "path");
  _m.shader.model = glGetUniformLocation(_m.shader.program, "model");
  _m.shader.sampler = glGetUniformLocation(_m.shader.program, "sampler");

  glUniformBlockBinding(_m.shader.program, _m.shader.camera, OXCART_SHADER_BINDPOINT_CAMERA_ORTHO);
  glUniformBlockBinding(_m.shader.program, _m.shader.path, OXCART_SHADER_BINDPOINT_PATH_FRAGMENT);
  glUniform1i(_m.shader.sampler, 0);
}
