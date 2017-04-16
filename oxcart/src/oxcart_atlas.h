/**
 * Freetype GL - A C OpenGL Freetype engine
 * Platform:    Any
 * WWW:         http://code.google.com/p/freetype-gl/
 * ----------------------------------------------------------------------------
 * Copyright 2011,2012 Nicolas P. Rougier. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY NICOLAS P. ROUGIER ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL NICOLAS P. ROUGIER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of Nicolas P. Rougier.
 * 
 * ============================================================================
 * 
 * This source is based on the article by Jukka Jylanki :
 * "A Thousand Ways to Pack the Bin - A Practical Approach to
 * Two-Dimensional Rectangle Bin Packing", February 27, 2010.
 * 
 * More precisely, this is an implementation of the Skyline Bottom-Left
 * algorithm based on C++ sources provided by Jukka Jylanki at:
 * http://clb.demon.fi/files/RectangleBinPack/
 * 
 * ============================================================================
 * 
 * This source is derived from Freetype GL.  Its license, found above, has been
 * carried forward.  It has been refactored and now conforms with the oxcart
 * framework.
 */

#ifndef OXCART_ATLAS_H
#define OXCART_ATLAS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct oxcart_atlas_t oxcart_atlas_t;

oxcart_atlas_t *oxcart_atlas_create(int w, int h, int depth);
void oxcart_atlas_destroy(oxcart_atlas_t *atlas);
void oxcart_atlas_properties(oxcart_atlas_t *atlas, int *w, int *h, int *depth);
const unsigned char *oxcart_atlas_data(oxcart_atlas_t *atlas);
int oxcart_atlas_reserve(oxcart_atlas_t *atlas, int w, int h, int *x, int *y);
void oxcart_atlas_fill(oxcart_atlas_t *atlas, int x, int y, int w, int h, int stride, const unsigned char *data);
void oxcart_atlas_clear(oxcart_atlas_t *atlas);

#ifdef __cplusplus
}
#endif

#endif
