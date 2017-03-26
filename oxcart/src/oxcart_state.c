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

#include "oxcart_assert.h"
#include "oxcart_state.h"

static oxcart_state_t _m = {0};

/**
 * 
 */
void oxcart_state_initialize()
{
}

/**
 * 
 */
void oxcart_state_terminate()
{
}

/**
 * 
 */
void oxcart_state_update(size_t now, size_t timestep)
{
  if (_m.next_ang > 360.0f) {
    _m.next_ang -= 360.0f;
  }

  _m.prev_ang = _m.next_ang;
  _m.next_ang += 360.0f / (4000.0f / timestep);
}

/**
 * 
 */
oxcart_state_t* oxcart_state_reference()
{
  return(&_m);
}
