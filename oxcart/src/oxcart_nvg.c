/**
 * NanoVG - Antialiased vector graphics rendering library for OpenGL
 *          https://github.com/memononen/nanovg/
 * 
 * Copyright (c) 2013 Mikko Mononen memon@inside.org
 * 
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source distribution.
 * 
 * ============================================================================
 * 
 * This source is derived from NanoVG.  Its license, found above, has been
 * carried forward.  It has been refactored and now conforms with the oxcart
 * framework.
 */

#include <stdlib.h>
#include "oxcart_assert.h"
#include "oxcart_gl.h"
#include "oxcart_math.h"
#include "oxcart_nvg.h"
#include "oxcart_shader.h"
#include "oxcart_util.h"
#include "oxcart_vector.h"

#define OXCART_NVG_COMMAND_MOVETO   0
#define OXCART_NVG_COMMAND_LINETO   1
#define OXCART_NVG_COMMAND_BEZIERTO 2
#define OXCART_NVG_COMMAND_CLOSE    3
#define OXCART_NVG_COMMAND_WINDING  4
#define OXCART_NVG_POINT_CORNER     0x01
#define OXCART_NVG_POINT_LEFT       0x02
#define OXCART_NVG_POINT_BEVEL      0x04
#define OXCART_NVG_POINT_INNERBEVEL 0x08

typedef struct oxcart_nvgclip_t oxcart_nvgclip_t;
typedef struct oxcart_nvgpath_t oxcart_nvgpath_t;
typedef struct oxcart_nvgpoint_t oxcart_nvgpoint_t;
typedef struct oxcart_nvgshader_t oxcart_nvgshader_t;
typedef struct oxcart_nvgstate_t oxcart_nvgstate_t;
typedef struct oxcart_nvguniform_t oxcart_nvguniform_t;
typedef struct oxcart_nvgvertex_t oxcart_nvgvertex_t;
typedef struct oxcart_nvgmodule_t oxcart_nvgmodule_t;

struct oxcart_nvgclip_t
{
  oxcart_vec2f_t extent;
  oxcart_mat3f_t transform;
};

struct oxcart_nvgpath_t
{
  int value;
};

struct oxcart_nvgpoint_t
{
  int value;
};

struct oxcart_nvgshader_t
{
  GLuint program;
  GLuint camera;
  GLuint nvg;
  GLint model;
  GLint sampler;
};

struct oxcart_nvgstate_t
{
  int linecap;
  int linejoin;
  float miterlimit;
  float globalalpha;
  float strokewidth;
  oxcart_vec4f_t strokecolor;
  oxcart_vec4f_t fillcolor;
  oxcart_nvgclip_t clip;
  oxcart_mat3f_t transform;
};

struct oxcart_nvguniform_t
{
  float value;
};

struct oxcart_nvgvertex_t
{
  oxcart_vec2f_t vertex;
  oxcart_vec2f_t texcoord;
};

struct oxcart_nvg_t
{
  oxcart_vector_t* states;
  oxcart_vector_t* commands;
  oxcart_vector_t* points;
  oxcart_vector_t* paths;
  oxcart_vector_t* vertices;
  oxcart_vec4f_t bounds;
};

struct oxcart_nvgmodule_t
{
  oxcart_nvgshader_t shader;
};

static void _nvg_appendcommand(oxcart_nvg_t* nvg, float* values, int count);
static void _nvg_reset(oxcart_nvg_t* nvg);
static void _nvg_loadshader();

static oxcart_nvgmodule_t _m = {0};

/**
 * 
 */
void oxcart_nvg_initialize()
{
  _nvg_loadshader();
}

/**
 * 
 */
void oxcart_nvg_terminate()
{
  oxcart_program_destroy(_m.shader.program);
}

/**
 * 
 */
oxcart_nvg_t* oxcart_nvg_create()
{
  oxcart_nvg_t* nvg;

  if (!(nvg = (oxcart_nvg_t*)malloc(sizeof(oxcart_nvg_t)))) {
    OXCART_ASSERT(!"malloc() failed");
  }

  nvg->states = oxcart_vector_create(sizeof(oxcart_nvgstate_t), 32);
  nvg->commands = oxcart_vector_create(sizeof(float), 256);
  nvg->points = oxcart_vector_create(sizeof(oxcart_nvgpoint_t), 128);
  nvg->paths = oxcart_vector_create(sizeof(oxcart_nvgpath_t), 16);
  nvg->vertices = oxcart_vector_create(sizeof(oxcart_nvgvertex_t), 256);

  _nvg_reset(nvg);

  return(nvg);
}

/**
 * 
 */
void oxcart_nvg_destroy(oxcart_nvg_t* nvg)
{
  OXCART_ASSERT(nvg);

  oxcart_vector_destroy(nvg->vertices);
  oxcart_vector_destroy(nvg->paths);
  oxcart_vector_destroy(nvg->points);
  oxcart_vector_destroy(nvg->commands);
  oxcart_vector_destroy(nvg->states);

  free(nvg);
}

/**
 * 
 */
void oxcart_nvg_save(oxcart_nvg_t* nvg)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);

  state = oxcart_vector_back(nvg->states);
  oxcart_vector_pushback(nvg->states, state);
}

/**
 * 
 */
void oxcart_nvg_restore(oxcart_nvg_t* nvg)
{
  OXCART_ASSERT(nvg);

  if (oxcart_vector_size(nvg->states) > 1) {
    oxcart_vector_popback(nvg->states);
  }
}

/**
 * 
 */
void oxcart_nvg_beginframe(oxcart_nvg_t* nvg)
{
  OXCART_ASSERT(nvg);

  _nvg_reset(nvg);
}

/**
 * 
 */
void oxcart_nvg_endframe(oxcart_nvg_t* nvg)
{
  OXCART_ASSERT(nvg);
}

/**
 * 
 */
void oxcart_nvg_setlinecap(oxcart_nvg_t* nvg, int linecap)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT((linecap == OXCART_NVG_LINECAP_BUTT) || (linecap == OXCART_NVG_LINECAP_ROUND) || (linecap == OXCART_NVG_LINECAP_SQUARE));

  state = oxcart_vector_back(nvg->states);
  state->linecap = linecap;
}

/**
 * 
 */
void oxcart_nvg_setlinejoin(oxcart_nvg_t* nvg, int linejoin)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT((linejoin == OXCART_NVG_LINEJOIN_MITER) || (linejoin == OXCART_NVG_LINEJOIN_ROUND) || (linejoin == OXCART_NVG_LINEJOIN_BEVEL));

  state = oxcart_vector_back(nvg->states);
  state->linejoin = linejoin;
}

/**
 * 
 */
void oxcart_nvg_setmiterlimit(oxcart_nvg_t* nvg, float limit)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT(limit > 0.0f);

  state = oxcart_vector_back(nvg->states);
  state->miterlimit = limit;
}

/**
 * 
 */
void oxcart_nvg_setglobalalpha(oxcart_nvg_t* nvg, float alpha)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);

  alpha = oxcart_clampf(alpha, 0.0f, 1.0f);

  state = oxcart_vector_back(nvg->states);
  state->globalalpha = alpha;
}

/**
 * 
 */
void oxcart_nvg_setstrokewidth(oxcart_nvg_t* nvg, float width)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT(width > 0.0f);

  state = oxcart_vector_back(nvg->states);
  state->strokewidth = width;
}

/**
 * 
 */
void oxcart_nvg_setstrokecolor(oxcart_nvg_t* nvg, const oxcart_vec4f_t* color)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT(color);

  state = oxcart_vector_back(nvg->states);
  state->strokecolor = *color;
}

/**
 * 
 */
void oxcart_nvg_setfillcolor(oxcart_nvg_t* nvg, const oxcart_vec4f_t* color)
{
  oxcart_nvgstate_t* state;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT(color);

  state = oxcart_vector_back(nvg->states);
  state->fillcolor = *color;
}

/**
 * 
 */
void oxcart_nvg_beginpath(oxcart_nvg_t* nvg)
{
  OXCART_ASSERT(nvg);

  oxcart_vector_clear(nvg->commands);
  oxcart_vector_clear(nvg->points);
  oxcart_vector_clear(nvg->paths);
}

/**
 * 
 */
void oxcart_nvg_closepath(oxcart_nvg_t* nvg)
{
  OXCART_ASSERT(nvg);
}

/**
 * 
 */
static void _nvg_appendcommand(oxcart_nvg_t* nvg, float* values, int count)
{
  int i = 0;

  OXCART_ASSERT(nvg);
  OXCART_ASSERT(values);
  OXCART_ASSERT(count > 0);

  while (i < count) {
    switch ((int)values[i])
    {
      case OXCART_NVG_COMMAND_MOVETO:
        break;
      case OXCART_NVG_COMMAND_LINETO:
        break;
      case OXCART_NVG_COMMAND_BEZIERTO:
        break;
      default:
        break;
    }
  }
}

/**
 * 
 */
static void _nvg_reset(oxcart_nvg_t* nvg)
{
  oxcart_nvgstate_t state;

  OXCART_ASSERT(nvg);

  state.linecap = OXCART_NVG_LINECAP_BUTT;
  state.linejoin = OXCART_NVG_LINEJOIN_MITER;
  state.miterlimit = 10.0f;
  state.globalalpha = 1.0f;
  state.strokewidth = 1.0f;
  state.strokecolor = oxcart_vec4f_rgba(0, 0, 0, 255);
  state.fillcolor = oxcart_vec4f_rgba(255, 255, 255, 255);
  state.clip.extent = oxcart_vec2f_set(-1.0f, -1.0f);
  state.clip.transform = oxcart_mat3f_identity();
  state.transform = oxcart_mat3f_identity();

  oxcart_vector_clear(nvg->states);
  oxcart_vector_pushback(nvg->states, &state);
}

/**
 * 
 */
static void _nvg_loadshader()
{
  GLuint shader[2];

  shader[0] = oxcart_shader_createwithfile("/shader/oxcart_nvg.vert", GL_VERTEX_SHADER);
  shader[1] = oxcart_shader_createwithfile("/shader/oxcart_nvg.frag", GL_FRAGMENT_SHADER);
  _m.shader.program = oxcart_program_create(shader, OXCART_ARRAY_SIZE(shader));
  oxcart_shader_destroy(shader, OXCART_ARRAY_SIZE(shader));

  glBindAttribLocation(_m.shader.program, OXCART_SHADER_ATTRIB_LOCATION_VERTEX, "vertex");
  glBindAttribLocation(_m.shader.program, OXCART_SHADER_ATTRIB_LOCATION_TEXCOORD, "texcoord");

  oxcart_program_link(_m.shader.program);

  _m.shader.camera = glGetUniformBlockIndex(_m.shader.program, "camera");
  _m.shader.nvg = glGetUniformBlockIndex(_m.shader.program, "nvg");
  _m.shader.model = glGetUniformLocation(_m.shader.program, "model");
  _m.shader.sampler = glGetUniformLocation(_m.shader.program, "sampler");

  glUniformBlockBinding(_m.shader.program, _m.shader.camera, OXCART_SHADER_BINDPOINT_CAMERA_ORTHO);
  glUniformBlockBinding(_m.shader.program, _m.shader.nvg, OXCART_SHADER_BINDPOINT_NVG_FRAGMENT);
  glUniform1i(_m.shader.sampler, 0);
}
