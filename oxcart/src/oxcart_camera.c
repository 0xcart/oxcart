/**
 * oxcart is licensed under the terms of the MIT license reproduced below.
 * 
 * Copyright © 2014 Thomas J. Schaefer
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
#include "oxcart_camera.h"
#include "oxcart_gl.h"
#include "oxcart_math.h"
#include "oxcart_shader.h"
#include "oxcart_util.h"

typedef struct oxcart_camerauniform_t oxcart_camerauniform_t;
typedef struct oxcart_camera_t oxcart_camera_t;
typedef struct oxcart_cameramodule_t oxcart_cameramodule_t;

struct oxcart_camerauniform_t
{
  oxcart_mat4f_t view;
  oxcart_mat4f_t projection;
};

struct oxcart_camera_t
{
  /* TODO: position and quaternion */
  oxcart_camerauniform_t uniform;
  GLuint ubo;
};

struct oxcart_cameramodule_t
{
  oxcart_camera_t camera[2];
};

static oxcart_cameramodule_t _m = {0};

/**
 * 
 */
void oxcart_camera_initialize()
{
  oxcart_vec3f_t eye;
  oxcart_vec3f_t target;
  oxcart_vec3f_t up;

  /* setup orthographic uniform buffer */
  _m.camera[OXCART_CAMERA_ORTHO].uniform.view = oxcart_mat4f_identity();
  _m.camera[OXCART_CAMERA_ORTHO].uniform.projection = oxcart_mat4f_orthographic(800.0f, 600.0f);
  glGenBuffers(1, &_m.camera[OXCART_CAMERA_ORTHO].ubo);
  glBindBuffer(GL_UNIFORM_BUFFER, _m.camera[OXCART_CAMERA_ORTHO].ubo);
  glBufferData(GL_UNIFORM_BUFFER, sizeof(oxcart_camerauniform_t), &_m.camera[OXCART_CAMERA_ORTHO].uniform, GL_DYNAMIC_DRAW);
  glBindBufferBase(GL_UNIFORM_BUFFER, OXCART_SHADER_BINDPOINT_CAMERA_ORTHO, _m.camera[OXCART_CAMERA_ORTHO].ubo);

  /* setup perspective uniform buffer */
  eye = oxcart_vec3f_set(0.0f, 0.0f, 0.0f);
  target = oxcart_vec3f_set(0.0f, 0.0f, -1.0f);
  up = oxcart_vec3f_set(0.0f, 1.0f, 0.0f);
  _m.camera[OXCART_CAMERA_PERSP].uniform.view = oxcart_mat4f_lookat(&eye, &target, &up);
  _m.camera[OXCART_CAMERA_PERSP].uniform.projection = oxcart_mat4f_perspective(45.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
  glGenBuffers(1, &_m.camera[OXCART_CAMERA_PERSP].ubo);
  glBindBuffer(GL_UNIFORM_BUFFER, _m.camera[OXCART_CAMERA_PERSP].ubo);
  glBufferData(GL_UNIFORM_BUFFER, sizeof(oxcart_camerauniform_t), &_m.camera[OXCART_CAMERA_PERSP].uniform, GL_DYNAMIC_DRAW);
  glBindBufferBase(GL_UNIFORM_BUFFER, OXCART_SHADER_BINDPOINT_CAMERA_PERSP, _m.camera[OXCART_CAMERA_PERSP].ubo);
}

/**
 * 
 */
void oxcart_camera_terminate()
{
  glDeleteBuffers(1, &_m.camera[OXCART_CAMERA_PERSP].ubo);
  glDeleteBuffers(1, &_m.camera[OXCART_CAMERA_ORTHO].ubo);
}

/**
 * 
 */
void oxcart_camera_setview(int target, const oxcart_mat4f_t* view)
{
  OXCART_ASSERT((target == OXCART_CAMERA_ORTHO) || (target == OXCART_CAMERA_PERSP));
  OXCART_ASSERT(view);

  _m.camera[target].uniform.view = *view;
  glBindBuffer(GL_UNIFORM_BUFFER, _m.camera[target].ubo);
  glBufferSubData(GL_UNIFORM_BUFFER, OXCART_OFFSET(oxcart_camerauniform_t, view), sizeof(oxcart_mat4f_t), view->d);
}

/**
 * 
 */
void oxcart_camera_setprojection(int target, const oxcart_mat4f_t* projection)
{
  OXCART_ASSERT((target == OXCART_CAMERA_ORTHO) || (target == OXCART_CAMERA_PERSP));
  OXCART_ASSERT(projection);

  _m.camera[target].uniform.projection = *projection;
  glBindBuffer(GL_UNIFORM_BUFFER, _m.camera[target].ubo);
  glBufferSubData(GL_UNIFORM_BUFFER, OXCART_OFFSET(oxcart_camerauniform_t, projection), sizeof(oxcart_mat4f_t), projection->d);
}
