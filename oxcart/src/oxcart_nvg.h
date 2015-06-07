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

#ifndef OXCART_NVG_H
#define OXCART_NVG_H

#include "oxcart_math.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OXCART_NVG_LINECAP_BUTT   0x00
#define OXCART_NVG_LINECAP_ROUND  0x01
#define OXCART_NVG_LINECAP_SQUARE 0x02
#define OXCART_NVG_LINEJOIN_MITER 0x00
#define OXCART_NVG_LINEJOIN_ROUND 0x01
#define OXCART_NVG_LINEJOIN_BEVEL 0x02

typedef struct oxcart_nvg_t oxcart_nvg_t;

void oxcart_nvg_initialize();
void oxcart_nvg_terminate();
oxcart_nvg_t* oxcart_nvg_create();
void oxcart_nvg_destroy(oxcart_nvg_t* nvg);
void oxcart_nvg_save(oxcart_nvg_t* nvg);
void oxcart_nvg_restore(oxcart_nvg_t* nvg);
void oxcart_nvg_beginframe(oxcart_nvg_t* nvg);
void oxcart_nvg_endframe(oxcart_nvg_t* nvg);
void oxcart_nvg_setlinecap(oxcart_nvg_t* nvg, int linecap);
void oxcart_nvg_setlinejoin(oxcart_nvg_t* nvg, int linejoin);
void oxcart_nvg_setmiterlimit(oxcart_nvg_t* nvg, float limit);
void oxcart_nvg_setglobalalpha(oxcart_nvg_t* nvg, float alpha);
void oxcart_nvg_setstrokewidth(oxcart_nvg_t* nvg, float width);
void oxcart_nvg_setstrokecolor(oxcart_nvg_t* nvg, const oxcart_vec4f_t* color);
void oxcart_nvg_setfillcolor(oxcart_nvg_t* nvg, const oxcart_vec4f_t* color);
void oxcart_nvg_setclip(oxcart_nvg_t* nvg, float x, float y, float w, float h);
int oxcart_nvg_inclip(oxcart_nvg_t* nvg, float x, float y);
void oxcart_nvg_resetclip(oxcart_nvg_t* nvg);
void oxcart_nvg_beginpath(oxcart_nvg_t* nvg);
void oxcart_nvg_closepath(oxcart_nvg_t* nvg);
void oxcart_nvg_moveto(oxcart_nvg_t* nvg, float x, float y);
void oxcart_nvg_lineto(oxcart_nvg_t* nvg, float x, float y);
void oxcart_nvg_bezierto(oxcart_nvg_t* nvg, float cx1, float cy1, float cx2, float cy2, float x, float y);
void oxcart_nvg_quadto(oxcart_nvg_t* nvg, float cx, float cy, float x, float y);
void oxcart_nvg_arcto(oxcart_nvg_t* nvg, float x1, float y1, float x2, float y2, float radius);
void oxcart_nvg_arc(oxcart_nvg_t* nvg, float cx, float cy, float r, float a0, float a1, int dir);
void oxcart_nvg_rect(oxcart_nvg_t* nvg, float x, float y, float w, float h);
void oxcart_nvg_roundedrect(oxcart_nvg_t* nvg, float x, float y, float w, float h, float r);
void oxcart_nvg_ellipse(oxcart_nvg_t* nvg, float cx, float cy, float rx, float ry);
void oxcart_nvg_circle(oxcart_nvg_t* nvg, float cx, float cy, float r);
void oxcart_nvg_fill(oxcart_nvg_t* nvg);
void oxcart_nvg_stroke(oxcart_nvg_t* nvg);
void oxcart_nvg_identity(oxcart_nvg_t* nvg);
void oxcart_nvg_rotate(oxcart_nvg_t* nvg, float angle);
void oxcart_nvg_translate(oxcart_nvg_t* nvg, float x, float y);
void oxcart_nvg_scale(oxcart_nvg_t* nvg, float x, float y);
void oxcart_nvg_transform(oxcart_nvg_t* nvg, const oxcart_mat3f_t* m1);
void oxcart_nvg_setmatrix(oxcart_nvg_t* nvg, const oxcart_mat3f_t* m1);

#ifdef __cplusplus
}
#endif

#endif
