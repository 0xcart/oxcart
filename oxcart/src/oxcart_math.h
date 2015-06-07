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
#define OXCART_MAT3_00(mat) ((mat).d[0])
#define OXCART_MAT3_01(mat) ((mat).d[1])
#define OXCART_MAT3_02(mat) ((mat).d[2])
#define OXCART_MAT3_10(mat) ((mat).d[3])
#define OXCART_MAT3_11(mat) ((mat).d[4])
#define OXCART_MAT3_12(mat) ((mat).d[5])
#define OXCART_MAT3_20(mat) ((mat).d[6])
#define OXCART_MAT3_21(mat) ((mat).d[7])
#define OXCART_MAT3_22(mat) ((mat).d[8])
#define OXCART_MAT4_00(mat) ((mat).d[ 0])
#define OXCART_MAT4_01(mat) ((mat).d[ 1])
#define OXCART_MAT4_02(mat) ((mat).d[ 2])
#define OXCART_MAT4_03(mat) ((mat).d[ 3])
#define OXCART_MAT4_10(mat) ((mat).d[ 4])
#define OXCART_MAT4_11(mat) ((mat).d[ 5])
#define OXCART_MAT4_12(mat) ((mat).d[ 6])
#define OXCART_MAT4_13(mat) ((mat).d[ 7])
#define OXCART_MAT4_20(mat) ((mat).d[ 8])
#define OXCART_MAT4_21(mat) ((mat).d[ 9])
#define OXCART_MAT4_22(mat) ((mat).d[10])
#define OXCART_MAT4_23(mat) ((mat).d[11])
#define OXCART_MAT4_30(mat) ((mat).d[12])
#define OXCART_MAT4_31(mat) ((mat).d[13])
#define OXCART_MAT4_32(mat) ((mat).d[14])
#define OXCART_MAT4_33(mat) ((mat).d[15])

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

#define OXCART_PId 3.14159265358979323846
#define OXCART_2PId 6.28318530717958647692
#define OXCART_1DIVPId 0.318309886183790671538
#define OXCART_1DIV2PId 0.159154943091895335769
#define OXCART_PIDIV2d 1.57079632679489661923
#define OXCART_PIDIV4d 0.785398163397448309615
#define OXCART_DEG2RADd(deg) (deg * (OXCART_PId / 180.0))
#define OXCART_RAD2DEGd(rad) (rad * (180.0 / OXCART_PId))
#define OXCART_ISZEROd(val) (fabs(val) <= DBL_EPSILON)
#define OXCART_ISEQUALd(a, b, e) (oxcart_isequald(a, b, e))

typedef struct oxcart_vec2f_t oxcart_vec2f_t;
typedef struct oxcart_vec3f_t oxcart_vec3f_t;
typedef struct oxcart_vec4f_t oxcart_vec4f_t;
typedef struct oxcart_mat3f_t oxcart_mat3f_t;
typedef struct oxcart_mat4f_t oxcart_mat4f_t;

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

typedef struct oxcart_vec2d_t oxcart_vec2d_t;
typedef struct oxcart_vec3d_t oxcart_vec3d_t;
typedef struct oxcart_vec4d_t oxcart_vec4d_t;
typedef struct oxcart_mat3d_t oxcart_mat3d_t;
typedef struct oxcart_mat4d_t oxcart_mat4d_t;

struct oxcart_vec2d_t
{
  double d[2];
};

struct oxcart_vec3d_t
{
  double d[3];
};

struct oxcart_vec4d_t
{
  double d[4];
};

struct oxcart_mat3d_t
{
  double d[9];
};

struct oxcart_mat4d_t
{
  double d[16];
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
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2f_cast(const oxcart_vec2f_t* v1);
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
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3f_cast(const oxcart_vec3f_t* v1);
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
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4f_cast(const oxcart_vec4f_t* v1);
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
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3f_cast(const oxcart_mat3f_t* m1);
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
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4f_cast(const oxcart_mat4f_t* m1);
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

OXCART_INLINE double OXCART_VCALL oxcart_mind(double a, double b);
OXCART_INLINE double OXCART_VCALL oxcart_maxd(double a, double b);
OXCART_INLINE double OXCART_VCALL oxcart_clampd(double d, double min, double max);
OXCART_INLINE double OXCART_VCALL oxcart_lerpd(double a, double b, double t);
OXCART_INLINE int OXCART_VCALL oxcart_isequald(double a, double b, double epsilon);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_zero();
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_set(double x, double y);
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2d_cast(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_add(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_subtract(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_multiply(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_divide(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_scale(const oxcart_vec2d_t* v1, double scale);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_negate(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_sqrt(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_rsqrt(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_normalize(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_lerp(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2, double t);
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_dot(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2);
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_length(const oxcart_vec2d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_rlength(const oxcart_vec2d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_lengthsq(const oxcart_vec2d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_angle(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_zero();
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_set(double x, double y, double z);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_setv2(const oxcart_vec2d_t* v1, double z);
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3d_cast(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_add(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_subtract(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_multiply(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_divide(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_scale(const oxcart_vec3d_t* v1, double scale);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_negate(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_sqrt(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_rsqrt(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_normalize(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_lerp(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2, double t);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_cross(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_transform(const oxcart_vec3d_t* v1, const oxcart_mat3d_t* m1);
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_dot(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_length(const oxcart_vec3d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_rlength(const oxcart_vec3d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_lengthsq(const oxcart_vec3d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_angle(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_zero();
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_set(double x, double y, double z, double w);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_setv2(const oxcart_vec2d_t* v1, double z, double w);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_setv3(const oxcart_vec3d_t* v1, double w);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4d_cast(const oxcart_vec4d_t* v1);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_add(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_subtract(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_multiply(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_divide(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_scale(const oxcart_vec4d_t* v1, double scale);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_negate(const oxcart_vec4d_t* v1);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_sqrt(const oxcart_vec4d_t* v1);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_rsqrt(const oxcart_vec4d_t* v1);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_normalize(const oxcart_vec4d_t* v1);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_lerp(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2, double t);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_cross(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_transform(const oxcart_vec4d_t* v1, const oxcart_mat4d_t* m1);
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_dot(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_length(const oxcart_vec4d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_rlength(const oxcart_vec4d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_lengthsq(const oxcart_vec4d_t* v1);
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_angle(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_identity();
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3d_cast(const oxcart_mat3d_t* m1);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_rotate(double angle);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_translate(double x, double y);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_translatev(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_scale(double x, double y);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_scalev(const oxcart_vec2d_t* v1);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_multiply(const oxcart_mat3d_t* m1, const oxcart_mat3d_t* m2);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_transpose(const oxcart_mat3d_t* m1);
OXCART_INLINE double OXCART_VCALL oxcart_mat3d_determinant(const oxcart_mat3d_t* m1);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_inverse(const oxcart_mat3d_t* m1, double* d);
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_affineinverse(const oxcart_mat3d_t* m1);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_identity();
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_setm3(const oxcart_mat3d_t* m1);
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4d_cast(const oxcart_mat4d_t* m1);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_rotate(double x, double y, double z, double angle);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_rotatev(const oxcart_vec3d_t* v1, double angle);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_translate(double x, double y, double z);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_translatev(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_scale(double x, double y, double z);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_scalev(const oxcart_vec3d_t* v1);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_multiply(const oxcart_mat4d_t* m1, const oxcart_mat4d_t* m2);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_transpose(const oxcart_mat4d_t* m1);
OXCART_INLINE double OXCART_VCALL oxcart_mat4d_determinant(const oxcart_mat4d_t* m1);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_inverse(const oxcart_mat4d_t* m1, double* d);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_affineinverse(const oxcart_mat4d_t* m1);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_orthographic(double w, double h);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_perspective(double fovy, double aspect, double n, double f);
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_lookat(const oxcart_vec3d_t* eye, const oxcart_vec3d_t* target, const oxcart_vec3d_t* up);

#include "oxcart_math.inl"

#ifdef __cplusplus
}
#endif

#endif
