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

#ifndef OXCART_MATH_H
#define OXCART_MATH_H

#include <float.h>
#include <math.h>
#include "oxcart_assert.h"
#include "oxcart_util.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OXCART_VEC_X(vec) ((vec).d[0])
#define OXCART_VEC_Y(vec) ((vec).d[1])
#define OXCART_VEC_Z(vec) ((vec).d[2])
#define OXCART_VEC_W(vec) ((vec).d[3])
#define OXCART_VEC_R(vec) ((vec).d[0])
#define OXCART_VEC_G(vec) ((vec).d[1])
#define OXCART_VEC_B(vec) ((vec).d[2])
#define OXCART_VEC_A(vec) ((vec).d[3])
#define OXCART_MAT3_11(mat) ((mat).d[0])
#define OXCART_MAT3_12(mat) ((mat).d[1])
#define OXCART_MAT3_13(mat) ((mat).d[2])
#define OXCART_MAT3_21(mat) ((mat).d[3])
#define OXCART_MAT3_22(mat) ((mat).d[4])
#define OXCART_MAT3_23(mat) ((mat).d[5])
#define OXCART_MAT3_31(mat) ((mat).d[6])
#define OXCART_MAT3_32(mat) ((mat).d[7])
#define OXCART_MAT3_33(mat) ((mat).d[8])
#define OXCART_MAT4_11(mat) ((mat).d[ 0])
#define OXCART_MAT4_12(mat) ((mat).d[ 1])
#define OXCART_MAT4_13(mat) ((mat).d[ 2])
#define OXCART_MAT4_14(mat) ((mat).d[ 3])
#define OXCART_MAT4_21(mat) ((mat).d[ 4])
#define OXCART_MAT4_22(mat) ((mat).d[ 5])
#define OXCART_MAT4_23(mat) ((mat).d[ 6])
#define OXCART_MAT4_24(mat) ((mat).d[ 7])
#define OXCART_MAT4_31(mat) ((mat).d[ 8])
#define OXCART_MAT4_32(mat) ((mat).d[ 9])
#define OXCART_MAT4_33(mat) ((mat).d[10])
#define OXCART_MAT4_34(mat) ((mat).d[11])
#define OXCART_MAT4_41(mat) ((mat).d[12])
#define OXCART_MAT4_42(mat) ((mat).d[13])
#define OXCART_MAT4_43(mat) ((mat).d[14])
#define OXCART_MAT4_44(mat) ((mat).d[15])

#define OXCART_PIf 3.141592654f
#define OXCART_2PIf 6.283185307f
#define OXCART_1DIVPIf 0.318309886f
#define OXCART_1DIV2PIf 0.159154943f
#define OXCART_PIDIV2f 1.570796327f
#define OXCART_PIDIV4f 0.785398163f
#define OXCART_DEG2RADf(deg) (deg * (OXCART_PIf / 180.0f))
#define OXCART_RAD2DEGf(rad) (rad * (180.0f / OXCART_PIf))
#define OXCART_ISZEROf(val) (fabsf(val) <= FLT_EPSILON)
#define OXCART_ISEQUALf(a, b, e) (oxcart_isequalf(a, b, e))

typedef struct oxcart_vec2f_t oxcart_vec2f_t;
typedef struct oxcart_vec3f_t oxcart_vec3f_t;
typedef struct oxcart_vec4f_t oxcart_vec4f_t;
typedef struct oxcart_mat3f_t oxcart_mat3f_t;
typedef struct oxcart_mat4f_t oxcart_mat4f_t;
typedef struct oxcart_vec4f_t oxcart_quatf_t;

struct oxcart_vec2f_t
{
  float d[2];
};

struct oxcart_vec3f_t
{
  float d[3];
};

struct oxcart_vec4f_t
{
  float d[4];
};

struct oxcart_mat3f_t
{
  float d[9];
};

struct oxcart_mat4f_t
{
  float d[16];
};

OXCART_INLINE int oxcart_mini(int a, int b);
OXCART_INLINE int oxcart_maxi(int a, int b);
OXCART_INLINE int oxcart_clampi(int i, int min, int max);

OXCART_INLINE float OXCART_VCALL oxcart_minf(float a, float b);
OXCART_INLINE float OXCART_VCALL oxcart_maxf(float a, float b);
OXCART_INLINE float OXCART_VCALL oxcart_clampf(float f, float min, float max);
OXCART_INLINE float OXCART_VCALL oxcart_lerpf(float a, float b, float t);
OXCART_INLINE int OXCART_VCALL oxcart_isequalf(float a, float b, float epsilon);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_zero();
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_set(float x, float y);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_add(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_subtract(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_multiply(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_divide(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_scale(const oxcart_vec2f_t* v1, float scale);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_negate(const oxcart_vec2f_t* v1);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_sqrt(const oxcart_vec2f_t* v1);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_rsqrt(const oxcart_vec2f_t* v1);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_normalize(const oxcart_vec2f_t* v1);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_lerp(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2, float t);
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_dot(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2);
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_length(const oxcart_vec2f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_rlength(const oxcart_vec2f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_lengthsq(const oxcart_vec2f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_angle(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_zero();
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_set(float x, float y, float z);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_setv2(const oxcart_vec2f_t* v1, float z);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_add(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_subtract(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_multiply(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_divide(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_scale(const oxcart_vec3f_t* v1, float scale);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_negate(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_sqrt(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_rsqrt(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_normalize(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_lerp(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2, float t);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_cross(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_transform(const oxcart_vec3f_t* v1, const oxcart_mat3f_t* m1);
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_dot(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_length(const oxcart_vec3f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_rlength(const oxcart_vec3f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_lengthsq(const oxcart_vec3f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_angle(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_zero();
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_set(float x, float y, float z, float w);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_setv2(const oxcart_vec2f_t* v1, float z, float w);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_setv3(const oxcart_vec3f_t* v1, float w);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_add(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_subtract(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_multiply(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_divide(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_scale(const oxcart_vec4f_t* v1, float scale);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_negate(const oxcart_vec4f_t* v1);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_sqrt(const oxcart_vec4f_t* v1);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_rsqrt(const oxcart_vec4f_t* v1);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_normalize(const oxcart_vec4f_t* v1);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_lerp(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2, float t);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_cross(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_transform(const oxcart_vec4f_t* v1, const oxcart_mat4f_t* m1);
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_dot(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_length(const oxcart_vec4f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_rlength(const oxcart_vec4f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_lengthsq(const oxcart_vec4f_t* v1);
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_angle(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_identity();
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_rotate(float angle);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_translate(float x, float y);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_translatev(const oxcart_vec2f_t* v1);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_scale(float x, float y);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_scalev(const oxcart_vec2f_t* v1);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_multiply(const oxcart_mat3f_t* m1, const oxcart_mat3f_t* m2);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_transpose(const oxcart_mat3f_t* m1);
OXCART_INLINE float OXCART_VCALL oxcart_mat3f_determinant(const oxcart_mat3f_t* m1);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_inverse(const oxcart_mat3f_t* m1, float* d);
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_affineinverse(const oxcart_mat3f_t* m1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_identity();
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_setm3(const oxcart_mat3f_t* m1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_rotate(float x, float y, float z, float angle);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_rotatev(const oxcart_vec3f_t* v1, float angle);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_translate(float x, float y, float z);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_translatev(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_scale(float x, float y, float z);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_scalev(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_multiply(const oxcart_mat4f_t* m1, const oxcart_mat4f_t* m2);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_transpose(const oxcart_mat4f_t* m1);
OXCART_INLINE float OXCART_VCALL oxcart_mat4f_determinant(const oxcart_mat4f_t* m1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_inverse(const oxcart_mat4f_t* m1, float* d);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_affineinverse(const oxcart_mat4f_t* m1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_orthographic(float w, float h);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_perspective(float fovy, float aspect, float n, float f);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_lookat(const oxcart_vec3f_t* eye, const oxcart_vec3f_t* target, const oxcart_vec3f_t* up);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_identity();
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_multiply(const oxcart_quatf_t* q1, const oxcart_quatf_t* q2);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_multiplyscalar(const oxcart_quatf_t* q1, float s);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_conjugate(const oxcart_quatf_t* q1);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_inverse(const oxcart_quatf_t* q1);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_euler(float x, float y, float z);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_eulerv(const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_angleaxis(float angle, float x, float y, float z);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_angleaxisv(float angle, const oxcart_vec3f_t* v1);
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_slerp(const oxcart_quatf_t* q1, const oxcart_quatf_t* q2, float t);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_quatf_matrix(const oxcart_quatf_t* q1);

#include "oxcart_math.inl"

#ifdef __cplusplus
}
#endif

#endif
