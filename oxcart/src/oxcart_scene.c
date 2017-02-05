/**
 * oxcart is licensed under the terms of the MIT license reproduced below.
 * 
 * Copyright © 2017 Thomas J. Schaefer
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

#include <stdio.h>
#include "oxcart_assert.h"
#include "oxcart_app.h"
#include "oxcart_camera.h"
#include "oxcart_cube.h"
#include "oxcart_gl.h"
#include "oxcart_math.h"
#include "oxcart_scene.h"
#include "oxcart_state.h"
#include "oxcart_text.h"
#include "oxcart_util.h"

typedef struct oxcart_scenemodule_t oxcart_scenemodule_t;

struct oxcart_scenemodule_t
{
  size_t past;
  size_t osec;
  size_t fps;
  size_t frames;
  oxcart_cube_t* cube;
  oxcart_text_t* text;
};

static oxcart_scenemodule_t _m = {0};

/**
 * 
 */
void oxcart_scene_initialize()
{
  int x, y, w, h;

  /* set these GL states once */
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_MULTISAMPLE);
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  /* camera must be initialized first */
  oxcart_camera_initialize();
  oxcart_window_rect(&x, &y, &w, &h);
  oxcart_scene_setviewport(w, h);

  /* initialize remaining scene elements */
  oxcart_text_initialize();
  oxcart_cube_initialize();

  _m.cube = oxcart_cube_create();
  _m.text = oxcart_text_create();
}

/**
 * 
 */
void oxcart_scene_terminate()
{
  oxcart_text_destroy(_m.text);
  oxcart_cube_destroy(_m.cube);

  oxcart_cube_terminate();
  oxcart_text_terminate();
  oxcart_camera_terminate();
}

/**
 * 
 */
void oxcart_scene_setviewport(int w, int h)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(w > 0);
  OXCART_ASSERT(h > 0);

  glViewport(0, 0, w, h);

  mat4 = oxcart_mat4f_orthographic((float)w, (float)h);
  oxcart_camera_setprojection(OXCART_CAMERA_ORTHO, &mat4);

  mat4 = oxcart_mat4f_perspective(OXCART_DEG2RADf(45.0f), (float)w / (float)h, 0.1f, 1000.0f);
  oxcart_camera_setprojection(OXCART_CAMERA_PERSP, &mat4);
}

/**
 * 
 */
void oxcart_scene_draw(float coeff)
{
  float angle;
  size_t now;
  size_t elapsed;
  oxcart_mat4f_t rotate;
  oxcart_mat4f_t translate;
  oxcart_mat4f_t model;
  oxcart_vec2f_t pen;
  oxcart_markup_t markup;
  oxcart_metrics_t metrics;
  char buffer[16];

  now = oxcart_time_tick();
  elapsed = now - _m.past;
  _m.past = now;
  _m.frames++;

  if ((now - _m.osec) >= 1000) {
    _m.osec = now;
    _m.fps = _m.frames;
    _m.frames = 0;
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  angle = (g_state.next_ang - g_state.prev_ang) * coeff;
  angle += g_state.prev_ang;
  rotate = oxcart_mat4f_rotate(0.5f, 1.0f, 0.0f, OXCART_DEG2RADf(angle));
  translate = oxcart_mat4f_translate(0.0f, 0.0f, -20.0f);
  model = oxcart_mat4f_multiply(&translate, &rotate);
  oxcart_cube_draw(_m.cube, &model);

  markup = oxcart_markup_defaults();
  sprintf_s(buffer, OXCART_ARRAY_SIZE(buffer), " dt: %ums", elapsed);
  pen = oxcart_vec2f_set(0.0f, 0.0f);
  oxcart_text_assign(_m.text, &markup, buffer, 0, &pen);
  oxcart_text_metrics(_m.text, &markup, buffer, 0, &metrics);
  sprintf_s(buffer, OXCART_ARRAY_SIZE(buffer), "fps: %u", _m.fps);
  pen = oxcart_vec2f_set(0.0f, metrics.baseline);
  oxcart_text_append(_m.text, &markup, buffer, 0, &pen);
  model = oxcart_mat4f_translate(-metrics.bearing, -metrics.ascent, 0.0f);
  oxcart_text_draw(_m.text, &model);

  oxcart_window_swap();
}
