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

#include "oxcart_delegate.h"
#include "oxcart_main.h"
#include "oxcart_scene.h"
#include "oxcart_state.h"

#define OXCART_DELEGATE_UPDATE_MAXCNT 10
#define OXCART_DELEGATE_UPDATE_TIMESTEP 10

typedef struct oxcart_delegatemodule_t oxcart_delegatemodule_t;

struct oxcart_delegatemodule_t
{
  size_t accum;
  size_t now;
};

static oxcart_delegatemodule_t _m = {0};

/**
 *
 */
void oxcart_delegate_update(size_t elapsed)
{
  int count;

  _m.accum += elapsed;

  for (count = 0; ((_m.accum >= OXCART_DELEGATE_UPDATE_TIMESTEP) && (count < OXCART_DELEGATE_UPDATE_MAXCNT)); count++) {
    _m.accum -= OXCART_DELEGATE_UPDATE_TIMESTEP;
    _m.now += OXCART_DELEGATE_UPDATE_TIMESTEP;
    oxcart_state_update(_m.now, OXCART_DELEGATE_UPDATE_TIMESTEP);
  }

  oxcart_scene_draw((float)_m.accum / OXCART_DELEGATE_UPDATE_TIMESTEP);
}

/**
 *
 */
int oxcart_delegate_windowcommand(int command)
{
  return(0);
}

/**
 *
 */
void oxcart_delegate_windowevent(int event)
{
  int x, y, w, h;

  switch (event)
  {
    case OXCART_WINDOW_EVENT_CREATED:
      oxcart_state_initialize();
      oxcart_scene_initialize();
      break;

    case OXCART_WINDOW_EVENT_DESTROYED:
      oxcart_scene_terminate();
      oxcart_state_terminate();
      break;

    case OXCART_WINDOW_EVENT_MAXIMIZED:
    case OXCART_WINDOW_EVENT_RESIZED:
      oxcart_window_rect(&x, &y, &w, &h);
      oxcart_scene_setviewport(w, h);
      break;
  }
}

/**
 *
 */
void oxcart_delegate_char(char c)
{
}

/**
 *
 */
void oxcart_delegate_keydown(int key, int repeat, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_keyup(int key, int alt, int ctrl, int shift)
{
  switch (key)
  {
    case OXCART_KEYBOARD_KEY_ESCAPE:
      oxcart_window_close();
      break;
  }
}

/**
 *
 */
void oxcart_delegate_mouseenter()
{
}

/**
 *
 */
void oxcart_delegate_mouseexit()
{
}

/**
 *
 */
void oxcart_delegate_mousemove(int x, int y, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_mousemoveraw(int x, int y, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_mousebuttondblclick(int button, int x, int y, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_mousebuttondown(int button, int x, int y, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_mousebuttonup(int button, int x, int y, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_mousewheelscroll(int delta, int step, int x, int y, int alt, int ctrl, int shift)
{
}

/**
 *
 */
void oxcart_delegate_gamepadbuttondown(int button, int repeat)
{
}

/**
 *
 */
void oxcart_delegate_gamepadbuttonup(int button)
{
}

/**
 *
 */
void oxcart_delegate_gamepadtrigger(int button, int z)
{
}

/**
 *
 */
void oxcart_delegate_gamepadthumb(int button, int x, int y)
{
}
