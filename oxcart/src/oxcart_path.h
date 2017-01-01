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

#ifndef OXCART_PATH_H
#define OXCART_PATH_H

#ifdef __cplusplus
extern "C" {
#endif

#define OXCART_PATH_LINECAP_BUTT   0x00
#define OXCART_PATH_LINECAP_ROUND  0x01
#define OXCART_PATH_LINECAP_SQUARE 0x02
#define OXCART_PATH_LINEJOIN_MITER 0x00
#define OXCART_PATH_LINEJOIN_ROUND 0x01
#define OXCART_PATH_LINEJOIN_BEVEL 0x02
#define OXCART_PATH_WINDING_CCW    0x00
#define OXCART_PATH_WINDING_CW     0x01

typedef struct oxcart_path_t oxcart_path_t;

void oxcart_path_initialize();
void oxcart_path_terminate();
oxcart_path_t* oxcart_path_create();
void oxcart_path_destroy(oxcart_path_t* path);
void oxcart_path_beginframe(oxcart_path_t* path);
void oxcart_path_endframe(oxcart_path_t* path);
void oxcart_path_save(oxcart_path_t* path);
void oxcart_path_restore(oxcart_path_t* path);
void oxcart_path_setlinecap(oxcart_path_t* path, int linecap);
void oxcart_path_setlinejoin(oxcart_path_t* path, int linejoin);
void oxcart_path_setmiterlimit(oxcart_path_t* path, float limit);
void oxcart_path_setglobalalpha(oxcart_path_t* path, float alpha);
void oxcart_path_setstrokewidth(oxcart_path_t* path, float width);
void oxcart_path_setstrokecolor(oxcart_path_t* path, const oxcart_vec4f_t* color);
void oxcart_path_setfillcolor(oxcart_path_t* path, const oxcart_vec4f_t* color);
void oxcart_path_setclip(oxcart_path_t* path, float x, float y, float w, float h);
int oxcart_path_inclip(oxcart_path_t* path, float x, float y);
void oxcart_path_resetclip(oxcart_path_t* path);
void oxcart_path_beginpath(oxcart_path_t* path);
void oxcart_path_closepath(oxcart_path_t* path);
void oxcart_path_setpathwinding(oxcart_path_t* path, int winding);
void oxcart_path_moveto(oxcart_path_t* path, float x, float y);
void oxcart_path_lineto(oxcart_path_t* path, float x, float y);
void oxcart_path_bezierto(oxcart_path_t* path, float cx1, float cy1, float cx2, float cy2, float x, float y);
void oxcart_path_quadto(oxcart_path_t* path, float cx, float cy, float x, float y);
void oxcart_path_arcto(oxcart_path_t* path, float x1, float y1, float x2, float y2, float radius);
void oxcart_path_arc(oxcart_path_t* path, float cx, float cy, float r, float a0, float a1, int dir);
void oxcart_path_rect(oxcart_path_t* path, float x, float y, float w, float h);
void oxcart_path_roundedrect(oxcart_path_t* path, float x, float y, float w, float h, float r);
void oxcart_path_ellipse(oxcart_path_t* path, float cx, float cy, float rx, float ry);
void oxcart_path_circle(oxcart_path_t* path, float cx, float cy, float r);
void oxcart_path_fill(oxcart_path_t* path);
void oxcart_path_stroke(oxcart_path_t* path);
void oxcart_path_identity(oxcart_path_t* path);
void oxcart_path_rotate(oxcart_path_t* path, float angle);
void oxcart_path_translate(oxcart_path_t* path, float x, float y);
void oxcart_path_scale(oxcart_path_t* path, float x, float y);
void oxcart_path_transform(oxcart_path_t* path, const oxcart_mat3f_t* m1);
void oxcart_path_setmatrix(oxcart_path_t* path, const oxcart_mat3f_t* m1);

#ifdef __cplusplus
}
#endif

#endif
