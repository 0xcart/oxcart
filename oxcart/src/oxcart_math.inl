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

/**
 * 
 */
OXCART_INLINE int oxcart_mini(int a, int b)
{
  return(a < b ? a : b);
}

/**
 * 
 */
OXCART_INLINE int oxcart_maxi(int a, int b)
{
  return(a > b ? a : b);
}

/**
 * 
 */
OXCART_INLINE int oxcart_clampi(int i, int min, int max)
{
  return(i < min ? min : (i > max ? max : i));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_minf(float a, float b)
{
  return(a < b ? a : b);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_maxf(float a, float b)
{
  return(a > b ? a : b);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_clampf(float f, float min, float max)
{
  return(f < min ? min : (f > max ? max : f));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_lerpf(float a, float b, float t)
{
  float omt;

  t = oxcart_clampf(t, 0.0f, 1.0f);
  omt = 1.0f - t;

  return((omt * a) + (t * b));
}

/**
 * 
 */
OXCART_INLINE int OXCART_VCALL oxcart_isequalf(float a, float b, float epsilon)
{
  float diff;
  float aa, ab;

  if (a == b) {
    return(1);
  }

  diff = fabsf(a - b);

  if ((a == 0.0f) || (b == 0.0f) || (diff < FLT_MIN)) {
    return(diff < (epsilon * FLT_MIN));
  }

  aa = fabsf(a);
  ab = fabsf(b);

  return((diff / (aa + ab)) < epsilon);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_zero()
{
  oxcart_vec2f_t vec2 = {0.0f, 0.0f};

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_set(float x, float y)
{
  oxcart_vec2f_t vec2;

  vec2.d[0] = x;
  vec2.d[1] = y;

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2f_cast(const oxcart_vec2f_t* v1)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = (double)v1->d[0];
  vec2.d[1] = (double)v1->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_add(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] + v2->d[0];
  vec2.d[1] = v1->d[1] + v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_subtract(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] - v2->d[0];
  vec2.d[1] = v1->d[1] - v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_multiply(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] * v2->d[0];
  vec2.d[1] = v1->d[1] * v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_divide(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] / v2->d[0];
  vec2.d[1] = v1->d[1] / v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_scale(const oxcart_vec2f_t* v1, float scale)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = v1->d[0] * scale;
  vec2.d[1] = v1->d[1] * scale;

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_negate(const oxcart_vec2f_t* v1)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = -v1->d[0];
  vec2.d[1] = -v1->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_sqrt(const oxcart_vec2f_t* v1)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = sqrtf(v1->d[0]);
  vec2.d[1] = sqrtf(v1->d[1]);

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_rsqrt(const oxcart_vec2f_t* v1)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = 1.0f / sqrtf(v1->d[0]);
  vec2.d[1] = 1.0f / sqrtf(v1->d[1]);

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_normalize(const oxcart_vec2f_t* v1)
{
  float length;
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);

  length = oxcart_vec2f_length(v1);

  if (length > 0.0f) {
    length = 1.0f / length;
  }

  vec2.d[0] = v1->d[0] * length;
  vec2.d[1] = v1->d[1] * length;

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2f_lerp(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2, float t)
{
  float omt;
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  t = oxcart_clampf(t, 0.0f, 1.0f);
  omt = 1.0f - t;

  vec2.d[0] = (omt * v1->d[0]) + (t * v2->d[0]);
  vec2.d[1] = (omt * v1->d[1]) + (t * v2->d[1]);

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_dot(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2)
{
  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  return((v1->d[0] * v2->d[0]) + (v1->d[1] * v2->d[1]));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_length(const oxcart_vec2f_t* v1)
{
  OXCART_ASSERT(v1);

  return(sqrtf(oxcart_vec2f_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_rlength(const oxcart_vec2f_t* v1)
{
  OXCART_ASSERT(v1);

  return(1.0f / sqrtf(oxcart_vec2f_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_lengthsq(const oxcart_vec2f_t* v1)
{
  OXCART_ASSERT(v1);

  return(oxcart_vec2f_dot(v1, v1));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec2f_angle(const oxcart_vec2f_t* v1, const oxcart_vec2f_t* v2)
{
  float angle;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  angle = oxcart_vec2f_dot(v1, v2) * oxcart_vec2f_rlength(v1) * oxcart_vec2f_rlength(v2);
  oxcart_clampf(angle, -1.0f, 1.0f);

  return(OXCART_RAD2DEGf(acosf(angle)));
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_zero()
{
  oxcart_vec3f_t vec3 = {0.0f, 0.0f, 0.0f};

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_set(float x, float y, float z)
{
  oxcart_vec3f_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_setv2(const oxcart_vec2f_t* v1, float z)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = v1->d[0];
  vec3.d[1] = v1->d[1];
  vec3.d[2] = z;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3f_cast(const oxcart_vec3f_t* v1)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = (double)v1->d[0];
  vec3.d[1] = (double)v1->d[1];
  vec3.d[2] = (double)v1->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_add(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] + v2->d[0];
  vec3.d[1] = v1->d[1] + v2->d[1];
  vec3.d[2] = v1->d[2] + v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_subtract(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] - v2->d[0];
  vec3.d[1] = v1->d[1] - v2->d[1];
  vec3.d[2] = v1->d[2] - v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_multiply(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] * v2->d[0];
  vec3.d[1] = v1->d[1] * v2->d[1];
  vec3.d[2] = v1->d[2] * v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_divide(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] / v2->d[0];
  vec3.d[1] = v1->d[1] / v2->d[1];
  vec3.d[2] = v1->d[2] / v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_scale(const oxcart_vec3f_t* v1, float scale)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = v1->d[0] * scale;
  vec3.d[1] = v1->d[1] * scale;
  vec3.d[2] = v1->d[2] * scale;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_negate(const oxcart_vec3f_t* v1)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = -v1->d[0];
  vec3.d[1] = -v1->d[1];
  vec3.d[2] = -v1->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_sqrt(const oxcart_vec3f_t* v1)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = sqrtf(v1->d[0]);
  vec3.d[1] = sqrtf(v1->d[1]);
  vec3.d[2] = sqrtf(v1->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_rsqrt(const oxcart_vec3f_t* v1)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = 1.0f / sqrtf(v1->d[0]);
  vec3.d[1] = 1.0f / sqrtf(v1->d[1]);
  vec3.d[2] = 1.0f / sqrtf(v1->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_normalize(const oxcart_vec3f_t* v1)
{
  float length;
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  length = oxcart_vec3f_length(v1);

  if (length > 0.0f) {
    length = 1.0f / length;
  }

  vec3.d[0] = v1->d[0] * length;
  vec3.d[1] = v1->d[1] * length;
  vec3.d[2] = v1->d[2] * length;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_lerp(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2, float t)
{
  float omt;
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  t = oxcart_clampf(t, 0.0f, 1.0f);
  omt = 1.0f - t;

  vec3.d[0] = (omt * v1->d[0]) + (t * v2->d[0]);
  vec3.d[1] = (omt * v1->d[1]) + (t * v2->d[1]);
  vec3.d[2] = (omt * v1->d[2]) + (t * v2->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_cross(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = (v1->d[1] * v2->d[2]) - (v1->d[2] * v2->d[1]);
  vec3.d[1] = (v1->d[2] * v2->d[0]) - (v1->d[0] * v2->d[2]);
  vec3.d[2] = (v1->d[0] * v2->d[1]) - (v1->d[1] * v2->d[0]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3f_transform(const oxcart_vec3f_t* v1, const oxcart_mat3f_t* m1)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(m1);

  vec3.d[0] = (m1->d[0] * v1->d[0]) + (m1->d[3] * v1->d[1]) + (m1->d[6] * v1->d[2]);
  vec3.d[1] = (m1->d[1] * v1->d[0]) + (m1->d[4] * v1->d[1]) + (m1->d[7] * v1->d[2]);
  vec3.d[2] = (m1->d[2] * v1->d[0]) + (m1->d[5] * v1->d[1]) + (m1->d[8] * v1->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_dot(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  return((v1->d[0] * v2->d[0]) + (v1->d[1] * v2->d[1]) + (v1->d[2] * v2->d[2]));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_length(const oxcart_vec3f_t* v1)
{
  OXCART_ASSERT(v1);

  return(sqrtf(oxcart_vec3f_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_rlength(const oxcart_vec3f_t* v1)
{
  OXCART_ASSERT(v1);

  return(1.0f / sqrtf(oxcart_vec3f_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_lengthsq(const oxcart_vec3f_t* v1)
{
  OXCART_ASSERT(v1);

  return(oxcart_vec3f_dot(v1, v1));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec3f_angle(const oxcart_vec3f_t* v1, const oxcart_vec3f_t* v2)
{
  float angle;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  angle = oxcart_vec3f_dot(v1, v2) * oxcart_vec3f_rlength(v1) * oxcart_vec3f_rlength(v2);
  oxcart_clampf(angle, -1.0f, 1.0f);

  return(OXCART_RAD2DEGf(acosf(angle)));
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_zero()
{
  oxcart_vec4f_t vec4 = {0.0f, 0.0f, 0.0f, 0.0f};

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_set(float x, float y, float z, float w)
{
  oxcart_vec4f_t vec4;

  vec4.d[0] = x;
  vec4.d[1] = y;
  vec4.d[2] = z;
  vec4.d[3] = w;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_setv2(const oxcart_vec2f_t* v1, float z, float w)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = v1->d[0];
  vec4.d[1] = v1->d[1];
  vec4.d[2] = z;
  vec4.d[3] = w;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_setv3(const oxcart_vec3f_t* v1, float w)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = v1->d[0];
  vec4.d[1] = v1->d[1];
  vec4.d[2] = v1->d[2];
  vec4.d[3] = w;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
  oxcart_vec4f_t vec4;

  vec4.d[0] = r / 255.0f;
  vec4.d[1] = g / 255.0f;
  vec4.d[2] = b / 255.0f;
  vec4.d[3] = a / 255.0f;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4f_cast(const oxcart_vec4f_t* v1)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = (double)v1->d[0];
  vec4.d[1] = (double)v1->d[1];
  vec4.d[2] = (double)v1->d[2];
  vec4.d[3] = (double)v1->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_add(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] + v2->d[0];
  vec4.d[1] = v1->d[1] + v2->d[1];
  vec4.d[2] = v1->d[2] + v2->d[2];
  vec4.d[3] = v1->d[3] + v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_subtract(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] - v2->d[0];
  vec4.d[1] = v1->d[1] - v2->d[1];
  vec4.d[2] = v1->d[2] - v2->d[2];
  vec4.d[3] = v1->d[3] - v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_multiply(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] * v2->d[0];
  vec4.d[1] = v1->d[1] * v2->d[1];
  vec4.d[2] = v1->d[2] * v2->d[2];
  vec4.d[3] = v1->d[3] * v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_divide(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] / v2->d[0];
  vec4.d[1] = v1->d[1] / v2->d[1];
  vec4.d[2] = v1->d[2] / v2->d[2];
  vec4.d[3] = v1->d[3] / v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_scale(const oxcart_vec4f_t* v1, float scale)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = v1->d[0] * scale;
  vec4.d[1] = v1->d[1] * scale;
  vec4.d[2] = v1->d[2] * scale;
  vec4.d[3] = v1->d[3] * scale;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_negate(const oxcart_vec4f_t* v1)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = -v1->d[0];
  vec4.d[1] = -v1->d[1];
  vec4.d[2] = -v1->d[2];
  vec4.d[3] = -v1->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_sqrt(const oxcart_vec4f_t* v1)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = sqrtf(v1->d[0]);
  vec4.d[1] = sqrtf(v1->d[1]);
  vec4.d[2] = sqrtf(v1->d[2]);
  vec4.d[3] = sqrtf(v1->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_rsqrt(const oxcart_vec4f_t* v1)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = 1.0f / sqrtf(v1->d[0]);
  vec4.d[1] = 1.0f / sqrtf(v1->d[1]);
  vec4.d[2] = 1.0f / sqrtf(v1->d[2]);
  vec4.d[3] = 1.0f / sqrtf(v1->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_normalize(const oxcart_vec4f_t* v1)
{
  float length;
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  length = oxcart_vec4f_length(v1);

  if (length > 0.0f) {
    length = 1.0f / length;
  }

  vec4.d[0] = v1->d[0] * length;
  vec4.d[1] = v1->d[1] * length;
  vec4.d[2] = v1->d[2] * length;
  vec4.d[3] = v1->d[3] * length;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_lerp(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2, float t)
{
  float omt;
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  t = oxcart_clampf(t, 0.0f, 1.0f);
  omt = 1.0f - t;

  vec4.d[0] = (omt * v1->d[0]) + (t * v2->d[0]);
  vec4.d[1] = (omt * v1->d[1]) + (t * v2->d[1]);
  vec4.d[2] = (omt * v1->d[2]) + (t * v2->d[2]);
  vec4.d[3] = (omt * v1->d[3]) + (t * v2->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_cross(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = (v1->d[1] * v2->d[2]) - (v1->d[2] * v2->d[1]);
  vec4.d[1] = (v1->d[2] * v2->d[0]) - (v1->d[0] * v2->d[2]);
  vec4.d[2] = (v1->d[0] * v2->d[1]) - (v1->d[1] * v2->d[0]);
  vec4.d[3] = 0.0f;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4f_transform(const oxcart_vec4f_t* v1, const oxcart_mat4f_t* m1)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(m1);

  vec4.d[0] = (m1->d[ 0] * v1->d[0]) + (m1->d[ 4] * v1->d[1]) + (m1->d[ 8] * v1->d[2]) + (m1->d[12] * v1->d[3]);
  vec4.d[1] = (m1->d[ 1] * v1->d[0]) + (m1->d[ 5] * v1->d[1]) + (m1->d[ 9] * v1->d[2]) + (m1->d[13] * v1->d[3]);
  vec4.d[2] = (m1->d[ 2] * v1->d[0]) + (m1->d[ 6] * v1->d[1]) + (m1->d[10] * v1->d[2]) + (m1->d[14] * v1->d[3]);
  vec4.d[3] = (m1->d[ 3] * v1->d[0]) + (m1->d[ 7] * v1->d[1]) + (m1->d[11] * v1->d[2]) + (m1->d[15] * v1->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_dot(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  return((v1->d[0] * v2->d[0]) + (v1->d[1] * v2->d[1]) + (v1->d[2] * v2->d[2]) + (v1->d[3] * v2->d[3]));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_length(const oxcart_vec4f_t* v1)
{
  OXCART_ASSERT(v1);

  return(sqrtf(oxcart_vec4f_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_rlength(const oxcart_vec4f_t* v1)
{
  OXCART_ASSERT(v1);

  return(1.0f / sqrtf(oxcart_vec4f_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_lengthsq(const oxcart_vec4f_t* v1)
{
  OXCART_ASSERT(v1);

  return(oxcart_vec4f_dot(v1, v1));
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_vec4f_angle(const oxcart_vec4f_t* v1, const oxcart_vec4f_t* v2)
{
  float angle;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  angle = oxcart_vec4f_dot(v1, v2) * oxcart_vec4f_rlength(v1) * oxcart_vec4f_rlength(v2);
  oxcart_clampf(angle, -1.0f, 1.0f);

  return(OXCART_RAD2DEGf(acosf(angle)));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_identity()
{
  oxcart_mat3f_t mat3 = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3f_cast(const oxcart_mat3f_t* m1)
{
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(m1);

  mat3.d[0] = (double)m1->d[0];
  mat3.d[1] = (double)m1->d[1];
  mat3.d[2] = (double)m1->d[2];
  mat3.d[3] = (double)m1->d[3];
  mat3.d[4] = (double)m1->d[4];
  mat3.d[5] = (double)m1->d[5];
  mat3.d[6] = (double)m1->d[6];
  mat3.d[7] = (double)m1->d[7];
  mat3.d[8] = (double)m1->d[8];

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_rotate(float angle)
{
  float rad;
  float s, c;
  oxcart_mat3f_t mat3;

  rad = OXCART_DEG2RADf(angle);
  s = sinf(rad);
  c = cosf(rad);

  if (OXCART_ISZEROf(s)) {
    s = 0.0f;
  }

  if (OXCART_ISZEROf(c)) {
    c = 0.0f;
  }

  mat3.d[0] = c;
  mat3.d[1] = s;
  mat3.d[2] = 0.0f;
  mat3.d[3] = -s;
  mat3.d[4] = c;
  mat3.d[5] = 0.0f;
  mat3.d[6] = 0.0f;
  mat3.d[7] = 0.0f;
  mat3.d[8] = 1.0f;

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_translate(float x, float y)
{
  oxcart_vec2f_t vec2;

  vec2.d[0] = x;
  vec2.d[1] = y;

  return(oxcart_mat3f_translatev(&vec2));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_translatev(const oxcart_vec2f_t* v1)
{
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(v1);

  mat3.d[0] = 1.0f;
  mat3.d[1] = 0.0f;
  mat3.d[2] = 0.0f;
  mat3.d[3] = 0.0f;
  mat3.d[4] = 1.0f;
  mat3.d[5] = 0.0f;
  mat3.d[6] = v1->d[0];
  mat3.d[7] = v1->d[1];
  mat3.d[8] = 1.0f;

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_scale(float x, float y)
{
  oxcart_vec2f_t vec2;

  vec2.d[0] = x;
  vec2.d[1] = y;

  return(oxcart_mat3f_scalev(&vec2));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_scalev(const oxcart_vec2f_t* v1)
{
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(v1);

  mat3.d[0] = v1->d[0];
  mat3.d[1] = 0.0f;
  mat3.d[2] = 0.0f;
  mat3.d[3] = 0.0f;
  mat3.d[4] = v1->d[1];
  mat3.d[5] = 0.0f;
  mat3.d[6] = 0.0f;
  mat3.d[7] = 0.0f;
  mat3.d[8] = 1.0f;

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_multiply(const oxcart_mat3f_t* m1, const oxcart_mat3f_t* m2)
{
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(m2);

  mat3.d[0] = (m1->d[0] * m2->d[0]) + (m1->d[3] * m2->d[1]) + (m1->d[6] * m2->d[2]);
  mat3.d[1] = (m1->d[1] * m2->d[0]) + (m1->d[4] * m2->d[1]) + (m1->d[7] * m2->d[2]);
  mat3.d[2] = (m1->d[2] * m2->d[0]) + (m1->d[5] * m2->d[1]) + (m1->d[8] * m2->d[2]);
  mat3.d[3] = (m1->d[0] * m2->d[3]) + (m1->d[3] * m2->d[4]) + (m1->d[6] * m2->d[5]);
  mat3.d[4] = (m1->d[1] * m2->d[3]) + (m1->d[4] * m2->d[4]) + (m1->d[7] * m2->d[5]);
  mat3.d[5] = (m1->d[2] * m2->d[3]) + (m1->d[5] * m2->d[4]) + (m1->d[8] * m2->d[5]);
  mat3.d[6] = (m1->d[0] * m2->d[6]) + (m1->d[3] * m2->d[7]) + (m1->d[6] * m2->d[8]);
  mat3.d[7] = (m1->d[1] * m2->d[6]) + (m1->d[4] * m2->d[7]) + (m1->d[7] * m2->d[8]);
  mat3.d[8] = (m1->d[2] * m2->d[6]) + (m1->d[5] * m2->d[7]) + (m1->d[8] * m2->d[8]);

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_transpose(const oxcart_mat3f_t* m1)
{
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(m1);

  mat3.d[0] = m1->d[0];
  mat3.d[1] = m1->d[3];
  mat3.d[2] = m1->d[6];
  mat3.d[3] = m1->d[1];
  mat3.d[4] = m1->d[4];
  mat3.d[5] = m1->d[7];
  mat3.d[6] = m1->d[2];
  mat3.d[7] = m1->d[5];
  mat3.d[8] = m1->d[8];

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_mat3f_determinant(const oxcart_mat3f_t* m1)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(m1);

  vec3.d[0] =  ((m1->d[4] * m1->d[8]) - (m1->d[7] * m1->d[5]));
  vec3.d[1] = -((m1->d[1] * m1->d[8]) - (m1->d[7] * m1->d[2]));
  vec3.d[2] =  ((m1->d[1] * m1->d[5]) - (m1->d[4] * m1->d[2]));

  return((m1->d[0] * vec3.d[0]) + (m1->d[3] * vec3.d[1]) + (m1->d[6] * vec3.d[2]));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_inverse(const oxcart_mat3f_t* m1, float* d)
{
  int i;
  float odd;
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(d);

  mat3.d[0] =  ((m1->d[4] * m1->d[8]) - (m1->d[7] * m1->d[5]));
  mat3.d[1] = -((m1->d[1] * m1->d[8]) - (m1->d[7] * m1->d[2]));
  mat3.d[2] =  ((m1->d[1] * m1->d[5]) - (m1->d[4] * m1->d[2]));
  mat3.d[3] = -((m1->d[3] * m1->d[8]) - (m1->d[6] * m1->d[5]));
  mat3.d[4] =  ((m1->d[0] * m1->d[8]) - (m1->d[6] * m1->d[2]));
  mat3.d[5] = -((m1->d[0] * m1->d[5]) - (m1->d[3] * m1->d[2]));
  mat3.d[6] =  ((m1->d[3] * m1->d[7]) - (m1->d[6] * m1->d[4]));
  mat3.d[7] = -((m1->d[0] * m1->d[7]) - (m1->d[6] * m1->d[1]));
  mat3.d[8] =  ((m1->d[0] * m1->d[4]) - (m1->d[3] * m1->d[1]));

  if (0.0f == (*d = ((m1->d[0] * mat3.d[0]) + (m1->d[3] * mat3.d[1]) + (m1->d[6] * mat3.d[2])))) {
    return(mat3);
  }

  odd = 1.0f / *d;

  for (i = 0; i < 9; i++) {
    mat3.d[i] *= odd;
  }

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_affineinverse(const oxcart_mat3f_t* m1)
{
  oxcart_vec3f_t tran;
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(m1);

  mat3 = *m1;
  mat3.d[6] = 0.0f;
  mat3.d[7] = 0.0f;
  mat3.d[8] = 1.0f;
  mat3 = oxcart_mat3f_transpose(&mat3);

  tran = oxcart_vec3f_set(-m1->d[6], -m1->d[7], m1->d[8]);
  tran = oxcart_vec3f_transform(&tran, &mat3);

  mat3.d[6] = tran.d[0];
  mat3.d[7] = tran.d[1];
  mat3.d[8] = tran.d[2];

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_identity()
{
  oxcart_mat4f_t mat4 = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_setm3(const oxcart_mat3f_t* m1)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(m1);

  mat4.d[ 0] = m1->d[0];
  mat4.d[ 1] = m1->d[1];
  mat4.d[ 2] = m1->d[2];
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = m1->d[3];
  mat4.d[ 5] = m1->d[4];
  mat4.d[ 6] = m1->d[5];
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = m1->d[6];
  mat4.d[ 9] = m1->d[7];
  mat4.d[10] = m1->d[8];
  mat4.d[11] = 0.0f;
  mat4.d[12] = 0.0f;
  mat4.d[13] = 0.0f;
  mat4.d[14] = 0.0f;
  mat4.d[15] = 1.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4f_cast(const oxcart_mat4f_t* m1)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(m1);

  mat4.d[ 0] = (double)m1->d[ 0];
  mat4.d[ 1] = (double)m1->d[ 1];
  mat4.d[ 2] = (double)m1->d[ 2];
  mat4.d[ 3] = (double)m1->d[ 3];
  mat4.d[ 4] = (double)m1->d[ 4];
  mat4.d[ 5] = (double)m1->d[ 5];
  mat4.d[ 6] = (double)m1->d[ 6];
  mat4.d[ 7] = (double)m1->d[ 7];
  mat4.d[ 8] = (double)m1->d[ 8];
  mat4.d[ 9] = (double)m1->d[ 9];
  mat4.d[10] = (double)m1->d[10];
  mat4.d[11] = (double)m1->d[11];
  mat4.d[12] = (double)m1->d[12];
  mat4.d[13] = (double)m1->d[13];
  mat4.d[14] = (double)m1->d[14];
  mat4.d[15] = (double)m1->d[15];

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_rotate(float x, float y, float z, float angle)
{
  oxcart_vec3f_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;
  vec3 = oxcart_vec3f_normalize(&vec3);

  return(oxcart_mat4f_rotatev(&vec3, angle));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_rotatev(const oxcart_vec3f_t* v1, float angle)
{
  float rad;
  float s, c, omc;
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(v1);

  rad = OXCART_DEG2RADf(angle);
  s = sinf(rad);
  c = cosf(rad);

  if (OXCART_ISZEROf(s)) {
    s = 0.0f;
  }

  if (OXCART_ISZEROf(c)) {
    c = 0.0f;
  }

  omc = 1.0f - c;

  mat4.d[ 0] = (v1->d[0] * v1->d[0] * omc) + c;
  mat4.d[ 1] = (v1->d[0] * v1->d[1] * omc) + (v1->d[2] * s);
  mat4.d[ 2] = (v1->d[0] * v1->d[2] * omc) - (v1->d[1] * s);
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = (v1->d[1] * v1->d[0] * omc) - (v1->d[2] * s);
  mat4.d[ 5] = (v1->d[1] * v1->d[1] * omc) + c;
  mat4.d[ 6] = (v1->d[1] * v1->d[2] * omc) + (v1->d[0] * s);
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = (v1->d[2] * v1->d[0] * omc) + (v1->d[1] * s);
  mat4.d[ 9] = (v1->d[2] * v1->d[1] * omc) - (v1->d[0] * s);
  mat4.d[10] = (v1->d[2] * v1->d[2] * omc) + c;
  mat4.d[11] = 0.0f;
  mat4.d[12] = 0.0f;
  mat4.d[13] = 0.0f;
  mat4.d[14] = 0.0f;
  mat4.d[15] = 1.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_translate(float x, float y, float z)
{
  oxcart_vec3f_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(oxcart_mat4f_translatev(&vec3));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_translatev(const oxcart_vec3f_t* v1)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(v1);

  mat4.d[ 0] = 1.0f;
  mat4.d[ 1] = 0.0f;
  mat4.d[ 2] = 0.0f;
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = 0.0f;
  mat4.d[ 5] = 1.0f;
  mat4.d[ 6] = 0.0f;
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = 0.0f;
  mat4.d[ 9] = 0.0f;
  mat4.d[10] = 1.0f;
  mat4.d[11] = 0.0f;
  mat4.d[12] = v1->d[0];
  mat4.d[13] = v1->d[1];
  mat4.d[14] = v1->d[2];
  mat4.d[15] = 1.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_scale(float x, float y, float z)
{
  oxcart_vec3f_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(oxcart_mat4f_scalev(&vec3));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_scalev(const oxcart_vec3f_t* v1)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(v1);

  mat4.d[ 0] = v1->d[0];
  mat4.d[ 1] = 0.0f;
  mat4.d[ 2] = 0.0f;
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = 0.0f;
  mat4.d[ 5] = v1->d[1];
  mat4.d[ 6] = 0.0f;
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = 0.0f;
  mat4.d[ 9] = 0.0f;
  mat4.d[10] = v1->d[2];
  mat4.d[11] = 0.0f;
  mat4.d[12] = 0.0f;
  mat4.d[13] = 0.0f;
  mat4.d[14] = 0.0f;
  mat4.d[15] = 1.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_multiply(const oxcart_mat4f_t* m1, const oxcart_mat4f_t* m2)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(m2);

  mat4.d[ 0] = (m1->d[ 0] * m2->d[ 0]) + (m1->d[ 4] * m2->d[ 1]) + (m1->d[ 8] * m2->d[ 2]) + (m1->d[12] * m2->d[ 3]);
  mat4.d[ 1] = (m1->d[ 1] * m2->d[ 0]) + (m1->d[ 5] * m2->d[ 1]) + (m1->d[ 9] * m2->d[ 2]) + (m1->d[13] * m2->d[ 3]);
  mat4.d[ 2] = (m1->d[ 2] * m2->d[ 0]) + (m1->d[ 6] * m2->d[ 1]) + (m1->d[10] * m2->d[ 2]) + (m1->d[14] * m2->d[ 3]);
  mat4.d[ 3] = (m1->d[ 3] * m2->d[ 0]) + (m1->d[ 7] * m2->d[ 1]) + (m1->d[11] * m2->d[ 2]) + (m1->d[15] * m2->d[ 3]);
  mat4.d[ 4] = (m1->d[ 0] * m2->d[ 4]) + (m1->d[ 4] * m2->d[ 5]) + (m1->d[ 8] * m2->d[ 6]) + (m1->d[12] * m2->d[ 7]);
  mat4.d[ 5] = (m1->d[ 1] * m2->d[ 4]) + (m1->d[ 5] * m2->d[ 5]) + (m1->d[ 9] * m2->d[ 6]) + (m1->d[13] * m2->d[ 7]);
  mat4.d[ 6] = (m1->d[ 2] * m2->d[ 4]) + (m1->d[ 6] * m2->d[ 5]) + (m1->d[10] * m2->d[ 6]) + (m1->d[14] * m2->d[ 7]);
  mat4.d[ 7] = (m1->d[ 3] * m2->d[ 4]) + (m1->d[ 7] * m2->d[ 5]) + (m1->d[11] * m2->d[ 6]) + (m1->d[15] * m2->d[ 7]);
  mat4.d[ 8] = (m1->d[ 0] * m2->d[ 8]) + (m1->d[ 4] * m2->d[ 9]) + (m1->d[ 8] * m2->d[10]) + (m1->d[12] * m2->d[11]);
  mat4.d[ 9] = (m1->d[ 1] * m2->d[ 8]) + (m1->d[ 5] * m2->d[ 9]) + (m1->d[ 9] * m2->d[10]) + (m1->d[13] * m2->d[11]);
  mat4.d[10] = (m1->d[ 2] * m2->d[ 8]) + (m1->d[ 6] * m2->d[ 9]) + (m1->d[10] * m2->d[10]) + (m1->d[14] * m2->d[11]);
  mat4.d[11] = (m1->d[ 3] * m2->d[ 8]) + (m1->d[ 7] * m2->d[ 9]) + (m1->d[11] * m2->d[10]) + (m1->d[15] * m2->d[11]);
  mat4.d[12] = (m1->d[ 0] * m2->d[12]) + (m1->d[ 4] * m2->d[13]) + (m1->d[ 8] * m2->d[14]) + (m1->d[12] * m2->d[15]);
  mat4.d[13] = (m1->d[ 1] * m2->d[12]) + (m1->d[ 5] * m2->d[13]) + (m1->d[ 9] * m2->d[14]) + (m1->d[13] * m2->d[15]);
  mat4.d[14] = (m1->d[ 2] * m2->d[12]) + (m1->d[ 6] * m2->d[13]) + (m1->d[10] * m2->d[14]) + (m1->d[14] * m2->d[15]);
  mat4.d[15] = (m1->d[ 3] * m2->d[12]) + (m1->d[ 7] * m2->d[13]) + (m1->d[11] * m2->d[14]) + (m1->d[15] * m2->d[15]);

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_transpose(const oxcart_mat4f_t* m1)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(m1);

  mat4.d[ 0] = m1->d[ 0];
  mat4.d[ 1] = m1->d[ 4];
  mat4.d[ 2] = m1->d[ 8];
  mat4.d[ 3] = m1->d[12];
  mat4.d[ 4] = m1->d[ 1];
  mat4.d[ 5] = m1->d[ 5];
  mat4.d[ 6] = m1->d[ 9];
  mat4.d[ 7] = m1->d[13];
  mat4.d[ 8] = m1->d[ 2];
  mat4.d[ 9] = m1->d[ 6];
  mat4.d[10] = m1->d[10];
  mat4.d[11] = m1->d[14];
  mat4.d[12] = m1->d[ 3];
  mat4.d[13] = m1->d[ 7];
  mat4.d[14] = m1->d[11];
  mat4.d[15] = m1->d[15];

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE float OXCART_VCALL oxcart_mat4f_determinant(const oxcart_mat4f_t* m1)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(m1);

  vec4.d[0] = (m1->d[ 5] * ((m1->d[10] * m1->d[15]) - (m1->d[11] * m1->d[14]))) - (m1->d[ 9] * ((m1->d[ 6] * m1->d[15]) - (m1->d[ 7] * m1->d[14]))) - (m1->d[13] * ((m1->d[ 7] * m1->d[10]) - (m1->d[ 6] * m1->d[11])));
  vec4.d[1] = (m1->d[ 4] * ((m1->d[11] * m1->d[14]) - (m1->d[10] * m1->d[15]))) - (m1->d[ 8] * ((m1->d[ 7] * m1->d[14]) - (m1->d[ 6] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 6] * m1->d[11]) - (m1->d[ 7] * m1->d[10])));
  vec4.d[2] = (m1->d[ 4] * ((m1->d[ 9] * m1->d[15]) - (m1->d[11] * m1->d[13]))) - (m1->d[ 8] * ((m1->d[ 5] * m1->d[15]) - (m1->d[ 7] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 7] * m1->d[ 9]) - (m1->d[ 5] * m1->d[11])));
  vec4.d[3] = (m1->d[ 4] * ((m1->d[10] * m1->d[13]) - (m1->d[ 9] * m1->d[14]))) - (m1->d[ 8] * ((m1->d[ 6] * m1->d[13]) - (m1->d[ 5] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 5] * m1->d[10]) - (m1->d[ 6] * m1->d[ 9])));

  return((m1->d[0] * vec4.d[0]) + (m1->d[1] * vec4.d[1]) + (m1->d[2] * vec4.d[2]) + (m1->d[3] * vec4.d[3]));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_inverse(const oxcart_mat4f_t* m1, float* d)
{
  int i;
  float odd;
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(d);

  mat4.d[ 0] = (m1->d[ 5] * ((m1->d[10] * m1->d[15]) - (m1->d[11] * m1->d[14]))) - (m1->d[ 9] * ((m1->d[ 6] * m1->d[15]) - (m1->d[ 7] * m1->d[14]))) - (m1->d[13] * ((m1->d[ 7] * m1->d[10]) - (m1->d[ 6] * m1->d[11])));
  mat4.d[ 1] = (m1->d[ 1] * ((m1->d[11] * m1->d[14]) - (m1->d[10] * m1->d[15]))) - (m1->d[ 9] * ((m1->d[ 3] * m1->d[14]) - (m1->d[ 2] * m1->d[15]))) - (m1->d[13] * ((m1->d[ 2] * m1->d[11]) - (m1->d[ 3] * m1->d[10])));
  mat4.d[ 2] = (m1->d[ 1] * ((m1->d[ 6] * m1->d[15]) - (m1->d[ 7] * m1->d[14]))) - (m1->d[ 5] * ((m1->d[ 2] * m1->d[15]) - (m1->d[ 3] * m1->d[14]))) - (m1->d[13] * ((m1->d[ 3] * m1->d[ 6]) - (m1->d[ 2] * m1->d[ 7])));
  mat4.d[ 3] = (m1->d[ 1] * ((m1->d[ 7] * m1->d[10]) - (m1->d[ 6] * m1->d[11]))) - (m1->d[ 5] * ((m1->d[ 3] * m1->d[10]) - (m1->d[ 2] * m1->d[11]))) - (m1->d[ 9] * ((m1->d[ 2] * m1->d[ 7]) - (m1->d[ 3] * m1->d[ 6])));
  mat4.d[ 4] = (m1->d[ 4] * ((m1->d[11] * m1->d[14]) - (m1->d[10] * m1->d[15]))) - (m1->d[ 8] * ((m1->d[ 7] * m1->d[14]) - (m1->d[ 6] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 6] * m1->d[11]) - (m1->d[ 7] * m1->d[10])));
  mat4.d[ 5] = (m1->d[ 0] * ((m1->d[10] * m1->d[15]) - (m1->d[11] * m1->d[14]))) - (m1->d[ 8] * ((m1->d[ 2] * m1->d[15]) - (m1->d[ 3] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 3] * m1->d[10]) - (m1->d[ 2] * m1->d[11])));
  mat4.d[ 6] = (m1->d[ 0] * ((m1->d[ 7] * m1->d[14]) - (m1->d[ 6] * m1->d[15]))) - (m1->d[ 4] * ((m1->d[ 3] * m1->d[14]) - (m1->d[ 2] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 2] * m1->d[ 7]) - (m1->d[ 3] * m1->d[ 6])));
  mat4.d[ 7] = (m1->d[ 0] * ((m1->d[ 6] * m1->d[11]) - (m1->d[ 7] * m1->d[10]))) - (m1->d[ 4] * ((m1->d[ 2] * m1->d[11]) - (m1->d[ 3] * m1->d[10]))) - (m1->d[ 8] * ((m1->d[ 3] * m1->d[ 6]) - (m1->d[ 2] * m1->d[ 7])));
  mat4.d[ 8] = (m1->d[ 4] * ((m1->d[ 9] * m1->d[15]) - (m1->d[11] * m1->d[13]))) - (m1->d[ 8] * ((m1->d[ 5] * m1->d[15]) - (m1->d[ 7] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 7] * m1->d[ 9]) - (m1->d[ 5] * m1->d[11])));
  mat4.d[ 9] = (m1->d[ 0] * ((m1->d[11] * m1->d[13]) - (m1->d[ 9] * m1->d[15]))) - (m1->d[ 8] * ((m1->d[ 3] * m1->d[13]) - (m1->d[ 1] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 1] * m1->d[11]) - (m1->d[ 3] * m1->d[ 9])));
  mat4.d[10] = (m1->d[ 0] * ((m1->d[ 5] * m1->d[15]) - (m1->d[ 7] * m1->d[13]))) - (m1->d[ 4] * ((m1->d[ 1] * m1->d[15]) - (m1->d[ 3] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 3] * m1->d[ 5]) - (m1->d[ 1] * m1->d[ 7])));
  mat4.d[11] = (m1->d[ 0] * ((m1->d[ 7] * m1->d[ 9]) - (m1->d[ 5] * m1->d[11]))) - (m1->d[ 4] * ((m1->d[ 3] * m1->d[ 9]) - (m1->d[ 1] * m1->d[11]))) - (m1->d[ 8] * ((m1->d[ 1] * m1->d[ 7]) - (m1->d[ 3] * m1->d[ 5])));
  mat4.d[12] = (m1->d[ 4] * ((m1->d[10] * m1->d[13]) - (m1->d[ 9] * m1->d[14]))) - (m1->d[ 8] * ((m1->d[ 6] * m1->d[13]) - (m1->d[ 5] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 5] * m1->d[10]) - (m1->d[ 6] * m1->d[ 9])));
  mat4.d[13] = (m1->d[ 0] * ((m1->d[ 9] * m1->d[14]) - (m1->d[10] * m1->d[13]))) - (m1->d[ 8] * ((m1->d[ 1] * m1->d[14]) - (m1->d[ 2] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 2] * m1->d[ 9]) - (m1->d[ 1] * m1->d[10])));
  mat4.d[14] = (m1->d[ 0] * ((m1->d[ 6] * m1->d[13]) - (m1->d[ 5] * m1->d[14]))) - (m1->d[ 4] * ((m1->d[ 2] * m1->d[13]) - (m1->d[ 1] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 1] * m1->d[ 6]) - (m1->d[ 2] * m1->d[ 5])));
  mat4.d[15] = (m1->d[ 0] * ((m1->d[ 5] * m1->d[10]) - (m1->d[ 6] * m1->d[ 9]))) - (m1->d[ 4] * ((m1->d[ 1] * m1->d[10]) - (m1->d[ 2] * m1->d[ 9]))) - (m1->d[ 8] * ((m1->d[ 2] * m1->d[ 5]) - (m1->d[ 1] * m1->d[ 6])));

  if (0.0f == (*d = ((m1->d[0] * mat4.d[0]) + (m1->d[1] * mat4.d[4]) + (m1->d[2] * mat4.d[8]) + (m1->d[3] * mat4.d[12])))) {
    return(mat4);
  }

  odd = 1.0f / *d;

  for (i = 0; i < 16; i++) {
    mat4.d[i] *= odd;
  }

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_affineinverse(const oxcart_mat4f_t* m1)
{
  oxcart_vec4f_t tran;
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(m1);

  mat4 = *m1;
  mat4.d[12] = 0.0f;
  mat4.d[13] = 0.0f;
  mat4.d[14] = 0.0f;
  mat4.d[15] = 1.0f;
  mat4 = oxcart_mat4f_transpose(&mat4);

  tran = oxcart_vec4f_set(-m1->d[12], -m1->d[13], -m1->d[14], m1->d[15]);
  tran = oxcart_vec4f_transform(&tran, &mat4);

  mat4.d[12] = tran.d[0];
  mat4.d[13] = tran.d[1];
  mat4.d[14] = tran.d[2];
  mat4.d[15] = tran.d[3];

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_orthographic(float w, float h)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(w > 0.0f);
  OXCART_ASSERT(h > 0.0f);

  mat4.d[ 0] = 2.0f / w;
  mat4.d[ 1] = 0.0f;
  mat4.d[ 2] = 0.0f;
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = 0.0f;
  mat4.d[ 5] = 2.0f / -h;
  mat4.d[ 6] = 0.0f;
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = 0.0f;
  mat4.d[ 9] = 0.0f;
  mat4.d[10] = -1.0f;
  mat4.d[11] = 0.0f;
  mat4.d[12] = -1.0f;
  mat4.d[13] = 1.0f;
  mat4.d[14] = 0.0f;
  mat4.d[15] = 1.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_perspective(float fovy, float aspect, float n, float f)
{
  float w, h;
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(fovy > 0.0f);
  OXCART_ASSERT(aspect > 0.0f);
  OXCART_ASSERT(f > n);

  h = n * tanf(OXCART_DEG2RADf(fovy * 0.5f));
  w = h * aspect;

  mat4.d[ 0] = n / w;
  mat4.d[ 1] = 0.0f;
  mat4.d[ 2] = 0.0f;
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = 0.0f;
  mat4.d[ 5] = n / h;
  mat4.d[ 6] = 0.0f;
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = 0.0f;
  mat4.d[ 9] = 0.0f;
  mat4.d[10] = (n + f) / (n - f);
  mat4.d[11] = -1.0f;
  mat4.d[12] = 0.0f;
  mat4.d[13] = 0.0f;
  mat4.d[14] = (2.0f * n * f) / (n - f);
  mat4.d[15] = 0.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4f_lookat(const oxcart_vec3f_t* eye, const oxcart_vec3f_t* target, const oxcart_vec3f_t* up)
{
  oxcart_vec3f_t x;
  oxcart_vec3f_t y;
  oxcart_vec3f_t z;
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(eye);
  OXCART_ASSERT(target);
  OXCART_ASSERT(up);

  z = oxcart_vec3f_subtract(eye, target);
  z = oxcart_vec3f_normalize(&z);
  x = oxcart_vec3f_cross(up, &z);
  x = oxcart_vec3f_normalize(&x);
  y = oxcart_vec3f_cross(&z, &x);

  mat4.d[ 0] = x.d[0];
  mat4.d[ 1] = y.d[0];
  mat4.d[ 2] = z.d[0];
  mat4.d[ 3] = 0.0f;
  mat4.d[ 4] = x.d[1];
  mat4.d[ 5] = y.d[1];
  mat4.d[ 6] = z.d[1];
  mat4.d[ 7] = 0.0f;
  mat4.d[ 8] = x.d[2];
  mat4.d[ 9] = y.d[2];
  mat4.d[10] = z.d[2];
  mat4.d[11] = 0.0f;
  mat4.d[12] = -oxcart_vec3f_dot(&x, eye);
  mat4.d[13] = -oxcart_vec3f_dot(&y, eye);
  mat4.d[14] = -oxcart_vec3f_dot(&z, eye);
  mat4.d[15] = 1.0f;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_mind(double a, double b)
{
  return(a < b ? a : b);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_maxd(double a, double b)
{
  return(a > b ? a : b);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_clampd(double d, double min, double max)
{
  return(d < min ? min : (d > max ? max : d));
}

/**
*
*/
OXCART_INLINE double OXCART_VCALL oxcart_lerpd(double a, double b, double t)
{
  double omt;

  t = oxcart_clampd(t, 0.0, 1.0);
  omt = 1.0 - t;

  return((omt * a) + (t * b));
}

/**
 * 
 */
OXCART_INLINE int OXCART_VCALL oxcart_isequald(double a, double b, double epsilon)
{
  double diff;
  double aa, ab;

  if (a == b) {
    return(1);
  }

  diff = fabs(a - b);

  if ((a == 0.0) || (b == 0.0) || (diff < DBL_MIN)) {
    return(diff < (epsilon * DBL_MIN));
  }

  aa = fabs(a);
  ab = fabs(b);

  return((diff / (aa + ab)) < epsilon);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_zero()
{
  oxcart_vec2d_t vec2 = {0.0, 0.0};

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_set(double x, double y)
{
  oxcart_vec2d_t vec2;

  vec2.d[0] = x;
  vec2.d[1] = y;

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2f_t OXCART_VCALL oxcart_vec2d_cast(const oxcart_vec2d_t* v1)
{
  oxcart_vec2f_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = (float)v1->d[0];
  vec2.d[1] = (float)v1->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_add(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] + v2->d[0];
  vec2.d[1] = v1->d[1] + v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_subtract(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] - v2->d[0];
  vec2.d[1] = v1->d[1] - v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_multiply(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] * v2->d[0];
  vec2.d[1] = v1->d[1] * v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_divide(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec2.d[0] = v1->d[0] / v2->d[0];
  vec2.d[1] = v1->d[1] / v2->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_scale(const oxcart_vec2d_t* v1, double scale)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = v1->d[0] * scale;
  vec2.d[1] = v1->d[1] * scale;

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_negate(const oxcart_vec2d_t* v1)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = -v1->d[0];
  vec2.d[1] = -v1->d[1];

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_sqrt(const oxcart_vec2d_t* v1)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = sqrt(v1->d[0]);
  vec2.d[1] = sqrt(v1->d[1]);

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_rsqrt(const oxcart_vec2d_t* v1)
{
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);

  vec2.d[0] = 1.0 / sqrt(v1->d[0]);
  vec2.d[1] = 1.0 / sqrt(v1->d[1]);

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_normalize(const oxcart_vec2d_t* v1)
{
  double length;
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);

  length = oxcart_vec2d_length(v1);

  if (length > 0.0) {
    length = 1.0 / length;
  }

  vec2.d[0] = v1->d[0] * length;
  vec2.d[1] = v1->d[1] * length;

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec2d_t OXCART_VCALL oxcart_vec2d_lerp(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2, double t)
{
  double omt;
  oxcart_vec2d_t vec2;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  t = oxcart_clampd(t, 0.0, 1.0);
  omt = 1.0 - t;

  vec2.d[0] = (omt * v1->d[0]) + (t * v2->d[0]);
  vec2.d[1] = (omt * v1->d[1]) + (t * v2->d[1]);

  return(vec2);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_dot(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2)
{
  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  return((v1->d[0] * v2->d[0]) + (v1->d[1] * v2->d[1]));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_length(const oxcart_vec2d_t* v1)
{
  OXCART_ASSERT(v1);

  return(sqrt(oxcart_vec2d_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_rlength(const oxcart_vec2d_t* v1)
{
  OXCART_ASSERT(v1);

  return(1.0 / sqrt(oxcart_vec2d_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_lengthsq(const oxcart_vec2d_t* v1)
{
  OXCART_ASSERT(v1);

  return(oxcart_vec2d_dot(v1, v1));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec2d_angle(const oxcart_vec2d_t* v1, const oxcart_vec2d_t* v2)
{
  double angle;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  angle = oxcart_vec2d_dot(v1, v2) * oxcart_vec2d_rlength(v1) * oxcart_vec2d_rlength(v2);
  oxcart_clampd(angle, -1.0, 1.0);

  return(OXCART_RAD2DEGd(acos(angle)));
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_zero()
{
  oxcart_vec3d_t vec3 = {0.0, 0.0, 0.0};

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_set(double x, double y, double z)
{
  oxcart_vec3d_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_setv2(const oxcart_vec2d_t* v1, double z)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = v1->d[0];
  vec3.d[1] = v1->d[1];
  vec3.d[2] = z;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3f_t OXCART_VCALL oxcart_vec3d_cast(const oxcart_vec3d_t* v1)
{
  oxcart_vec3f_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = (float)v1->d[0];
  vec3.d[1] = (float)v1->d[1];
  vec3.d[2] = (float)v1->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_add(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] + v2->d[0];
  vec3.d[1] = v1->d[1] + v2->d[1];
  vec3.d[2] = v1->d[2] + v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_subtract(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] - v2->d[0];
  vec3.d[1] = v1->d[1] - v2->d[1];
  vec3.d[2] = v1->d[2] - v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_multiply(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] * v2->d[0];
  vec3.d[1] = v1->d[1] * v2->d[1];
  vec3.d[2] = v1->d[2] * v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_divide(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = v1->d[0] / v2->d[0];
  vec3.d[1] = v1->d[1] / v2->d[1];
  vec3.d[2] = v1->d[2] / v2->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_scale(const oxcart_vec3d_t* v1, double scale)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = v1->d[0] * scale;
  vec3.d[1] = v1->d[1] * scale;
  vec3.d[2] = v1->d[2] * scale;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_negate(const oxcart_vec3d_t* v1)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = -v1->d[0];
  vec3.d[1] = -v1->d[1];
  vec3.d[2] = -v1->d[2];

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_sqrt(const oxcart_vec3d_t* v1)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = sqrt(v1->d[0]);
  vec3.d[1] = sqrt(v1->d[1]);
  vec3.d[2] = sqrt(v1->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_rsqrt(const oxcart_vec3d_t* v1)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  vec3.d[0] = 1.0 / sqrt(v1->d[0]);
  vec3.d[1] = 1.0 / sqrt(v1->d[1]);
  vec3.d[2] = 1.0 / sqrt(v1->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_normalize(const oxcart_vec3d_t* v1)
{
  double length;
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);

  length = oxcart_vec3d_length(v1);

  if (length > 0.) {
    length = 1.0 / length;
  }

  vec3.d[0] = v1->d[0] * length;
  vec3.d[1] = v1->d[1] * length;
  vec3.d[2] = v1->d[2] * length;

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_lerp(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2, double t)
{
  double omt;
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  t = oxcart_clampd(t, 0.0, 1.0);
  omt = 1.0 - t;

  vec3.d[0] = (omt * v1->d[0]) + (t * v2->d[0]);
  vec3.d[1] = (omt * v1->d[1]) + (t * v2->d[1]);
  vec3.d[2] = (omt * v1->d[2]) + (t * v2->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_cross(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec3.d[0] = (v1->d[1] * v2->d[2]) - (v1->d[2] * v2->d[1]);
  vec3.d[1] = (v1->d[2] * v2->d[0]) - (v1->d[0] * v2->d[2]);
  vec3.d[2] = (v1->d[0] * v2->d[1]) - (v1->d[1] * v2->d[0]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec3d_t OXCART_VCALL oxcart_vec3d_transform(const oxcart_vec3d_t* v1, const oxcart_mat3d_t* m1)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(m1);

  vec3.d[0] = (m1->d[0] * v1->d[0]) + (m1->d[3] * v1->d[1]) + (m1->d[6] * v1->d[2]);
  vec3.d[1] = (m1->d[1] * v1->d[0]) + (m1->d[4] * v1->d[1]) + (m1->d[7] * v1->d[2]);
  vec3.d[2] = (m1->d[2] * v1->d[0]) + (m1->d[5] * v1->d[1]) + (m1->d[8] * v1->d[2]);

  return(vec3);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_dot(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  return((v1->d[0] * v2->d[0]) + (v1->d[1] * v2->d[1]) + (v1->d[2] * v2->d[2]));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_length(const oxcart_vec3d_t* v1)
{
  OXCART_ASSERT(v1);

  return(sqrt(oxcart_vec3d_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_rlength(const oxcart_vec3d_t* v1)
{
  OXCART_ASSERT(v1);

  return(1.0 / sqrt(oxcart_vec3d_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_lengthsq(const oxcart_vec3d_t* v1)
{
  OXCART_ASSERT(v1);

  return(oxcart_vec3d_dot(v1, v1));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec3d_angle(const oxcart_vec3d_t* v1, const oxcart_vec3d_t* v2)
{
  double angle;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  angle = oxcart_vec3d_dot(v1, v2) * oxcart_vec3d_rlength(v1) * oxcart_vec3d_rlength(v2);
  oxcart_clampd(angle, -1.0, 1.0);

  return(OXCART_RAD2DEGd(acos(angle)));
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_zero()
{
  oxcart_vec4d_t vec4 = {0.0, 0.0, 0.0, 0.0};

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_set(double x, double y, double z, double w)
{
  oxcart_vec4d_t vec4;

  vec4.d[0] = x;
  vec4.d[1] = y;
  vec4.d[2] = z;
  vec4.d[3] = w;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_setv2(const oxcart_vec2d_t* v1, double z, double w)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = v1->d[0];
  vec4.d[1] = v1->d[1];
  vec4.d[2] = z;
  vec4.d[3] = w;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_setv3(const oxcart_vec3d_t* v1, double w)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = v1->d[0];
  vec4.d[1] = v1->d[1];
  vec4.d[2] = v1->d[2];
  vec4.d[3] = w;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
  oxcart_vec4d_t vec4;

  vec4.d[0] = r / 255.0;
  vec4.d[1] = g / 255.0;
  vec4.d[2] = b / 255.0;
  vec4.d[3] = a / 255.0;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4f_t OXCART_VCALL oxcart_vec4d_cast(const oxcart_vec4d_t* v1)
{
  oxcart_vec4f_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = (float)v1->d[0];
  vec4.d[1] = (float)v1->d[1];
  vec4.d[2] = (float)v1->d[2];
  vec4.d[3] = (float)v1->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_add(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] + v2->d[0];
  vec4.d[1] = v1->d[1] + v2->d[1];
  vec4.d[2] = v1->d[2] + v2->d[2];
  vec4.d[3] = v1->d[3] + v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_subtract(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] - v2->d[0];
  vec4.d[1] = v1->d[1] - v2->d[1];
  vec4.d[2] = v1->d[2] - v2->d[2];
  vec4.d[3] = v1->d[3] - v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_multiply(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] * v2->d[0];
  vec4.d[1] = v1->d[1] * v2->d[1];
  vec4.d[2] = v1->d[2] * v2->d[2];
  vec4.d[3] = v1->d[3] * v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_divide(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = v1->d[0] / v2->d[0];
  vec4.d[1] = v1->d[1] / v2->d[1];
  vec4.d[2] = v1->d[2] / v2->d[2];
  vec4.d[3] = v1->d[3] / v2->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_scale(const oxcart_vec4d_t* v1, double scale)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = v1->d[0] * scale;
  vec4.d[1] = v1->d[1] * scale;
  vec4.d[2] = v1->d[2] * scale;
  vec4.d[3] = v1->d[3] * scale;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_negate(const oxcart_vec4d_t* v1)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = -v1->d[0];
  vec4.d[1] = -v1->d[1];
  vec4.d[2] = -v1->d[2];
  vec4.d[3] = -v1->d[3];

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_sqrt(const oxcart_vec4d_t* v1)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = sqrt(v1->d[0]);
  vec4.d[1] = sqrt(v1->d[1]);
  vec4.d[2] = sqrt(v1->d[2]);
  vec4.d[3] = sqrt(v1->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_rsqrt(const oxcart_vec4d_t* v1)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  vec4.d[0] = 1.0 / sqrt(v1->d[0]);
  vec4.d[1] = 1.0 / sqrt(v1->d[1]);
  vec4.d[2] = 1.0 / sqrt(v1->d[2]);
  vec4.d[3] = 1.0 / sqrt(v1->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_normalize(const oxcart_vec4d_t* v1)
{
  double length;
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);

  length = oxcart_vec4d_length(v1);

  if (length > 0.0) {
    length = 1.0 / length;
  }

  vec4.d[0] = v1->d[0] * length;
  vec4.d[1] = v1->d[1] * length;
  vec4.d[2] = v1->d[2] * length;
  vec4.d[3] = v1->d[3] * length;

  return(vec4);
}

/**
 * 
 */
/**
*
*/
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_lerp(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2, double t)
{
  double omt;
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  t = oxcart_clampd(t, 0.0, 1.0);
  omt = 1.0 - t;

  vec4.d[0] = (omt * v1->d[0]) + (t * v2->d[0]);
  vec4.d[1] = (omt * v1->d[1]) + (t * v2->d[1]);
  vec4.d[2] = (omt * v1->d[2]) + (t * v2->d[2]);
  vec4.d[3] = (omt * v1->d[3]) + (t * v2->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_cross(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  vec4.d[0] = (v1->d[1] * v2->d[2]) - (v1->d[2] * v2->d[1]);
  vec4.d[1] = (v1->d[2] * v2->d[0]) - (v1->d[0] * v2->d[2]);
  vec4.d[2] = (v1->d[0] * v2->d[1]) - (v1->d[1] * v2->d[0]);
  vec4.d[3] = 0.0;

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE oxcart_vec4d_t OXCART_VCALL oxcart_vec4d_transform(const oxcart_vec4d_t* v1, const oxcart_mat4d_t* m1)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(m1);

  vec4.d[0] = (m1->d[0] * v1->d[0]) + (m1->d[4] * v1->d[1]) + (m1->d[8] * v1->d[2]) + (m1->d[12] * v1->d[3]);
  vec4.d[1] = (m1->d[1] * v1->d[0]) + (m1->d[5] * v1->d[1]) + (m1->d[9] * v1->d[2]) + (m1->d[13] * v1->d[3]);
  vec4.d[2] = (m1->d[2] * v1->d[0]) + (m1->d[6] * v1->d[1]) + (m1->d[10] * v1->d[2]) + (m1->d[14] * v1->d[3]);
  vec4.d[3] = (m1->d[3] * v1->d[0]) + (m1->d[7] * v1->d[1]) + (m1->d[11] * v1->d[2]) + (m1->d[15] * v1->d[3]);

  return(vec4);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_dot(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  return((v1->d[0] * v2->d[0]) + (v1->d[1] * v2->d[1]) + (v1->d[2] * v2->d[2]) + (v1->d[3] * v2->d[3]));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_length(const oxcart_vec4d_t* v1)
{
  OXCART_ASSERT(v1);

  return(sqrt(oxcart_vec4d_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_rlength(const oxcart_vec4d_t* v1)
{
  OXCART_ASSERT(v1);

  return(1.0 / sqrt(oxcart_vec4d_dot(v1, v1)));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_lengthsq(const oxcart_vec4d_t* v1)
{
  OXCART_ASSERT(v1);

  return(oxcart_vec4d_dot(v1, v1));
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_vec4d_angle(const oxcart_vec4d_t* v1, const oxcart_vec4d_t* v2)
{
  double angle;

  OXCART_ASSERT(v1);
  OXCART_ASSERT(v2);

  angle = oxcart_vec4d_dot(v1, v2) * oxcart_vec4d_rlength(v1) * oxcart_vec4d_rlength(v2);
  oxcart_clampd(angle, -1.0, 1.0);

  return(OXCART_RAD2DEGd(acos(angle)));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_identity()
{
  oxcart_mat3d_t mat3 = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3d_cast(const oxcart_mat3d_t* m1)
{
  oxcart_mat3f_t mat3;

  OXCART_ASSERT(m1);

  mat3.d[0] = (float)m1->d[0];
  mat3.d[1] = (float)m1->d[1];
  mat3.d[2] = (float)m1->d[2];
  mat3.d[3] = (float)m1->d[3];
  mat3.d[4] = (float)m1->d[4];
  mat3.d[5] = (float)m1->d[5];
  mat3.d[6] = (float)m1->d[6];
  mat3.d[7] = (float)m1->d[7];
  mat3.d[8] = (float)m1->d[8];

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_rotate(double angle)
{
  double rad;
  double s, c;
  oxcart_mat3d_t mat3;

  rad = OXCART_DEG2RADd(angle);
  s = sin(rad);
  c = cos(rad);

  if (OXCART_ISZEROd(s)) {
    s = 0.0;
  }

  if (OXCART_ISZEROd(c)) {
    c = 0.0;
  }

  mat3.d[0] = c;
  mat3.d[1] = s;
  mat3.d[2] = 0.0;
  mat3.d[3] = -s;
  mat3.d[4] = c;
  mat3.d[5] = 0.0;
  mat3.d[6] = 0.0;
  mat3.d[7] = 0.0;
  mat3.d[8] = 1.0;

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_translate(double x, double y)
{
  oxcart_vec2d_t vec2;

  vec2.d[0] = x;
  vec2.d[1] = y;

  return(oxcart_mat3d_translatev(&vec2));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_translatev(const oxcart_vec2d_t* v1)
{
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(v1);

  mat3.d[0] = 1.0;
  mat3.d[1] = 0.0;
  mat3.d[2] = 0.0;
  mat3.d[3] = 0.0;
  mat3.d[4] = 1.0;
  mat3.d[5] = 0.0;
  mat3.d[6] = v1->d[0];
  mat3.d[7] = v1->d[1];
  mat3.d[8] = 1.0;

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_scale(double x, double y)
{
  oxcart_vec2d_t vec2;

  vec2.d[0] = x;
  vec2.d[1] = y;

  return(oxcart_mat3d_scalev(&vec2));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_scalev(const oxcart_vec2d_t* v1)
{
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(v1);

  mat3.d[0] = v1->d[0];
  mat3.d[1] = 0.0;
  mat3.d[2] = 0.0;
  mat3.d[3] = 0.0;
  mat3.d[4] = v1->d[1];
  mat3.d[5] = 0.0;
  mat3.d[6] = 0.0;
  mat3.d[7] = 0.0;
  mat3.d[8] = 1.0;

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_multiply(const oxcart_mat3d_t* m1, const oxcart_mat3d_t* m2)
{
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(m2);

  mat3.d[0] = (m1->d[0] * m2->d[0]) + (m1->d[3] * m2->d[1]) + (m1->d[6] * m2->d[2]);
  mat3.d[1] = (m1->d[1] * m2->d[0]) + (m1->d[4] * m2->d[1]) + (m1->d[7] * m2->d[2]);
  mat3.d[2] = (m1->d[2] * m2->d[0]) + (m1->d[5] * m2->d[1]) + (m1->d[8] * m2->d[2]);
  mat3.d[3] = (m1->d[0] * m2->d[3]) + (m1->d[3] * m2->d[4]) + (m1->d[6] * m2->d[5]);
  mat3.d[4] = (m1->d[1] * m2->d[3]) + (m1->d[4] * m2->d[4]) + (m1->d[7] * m2->d[5]);
  mat3.d[5] = (m1->d[2] * m2->d[3]) + (m1->d[5] * m2->d[4]) + (m1->d[8] * m2->d[5]);
  mat3.d[6] = (m1->d[0] * m2->d[6]) + (m1->d[3] * m2->d[7]) + (m1->d[6] * m2->d[8]);
  mat3.d[7] = (m1->d[1] * m2->d[6]) + (m1->d[4] * m2->d[7]) + (m1->d[7] * m2->d[8]);
  mat3.d[8] = (m1->d[2] * m2->d[6]) + (m1->d[5] * m2->d[7]) + (m1->d[8] * m2->d[8]);

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_transpose(const oxcart_mat3d_t* m1)
{
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(m1);

  mat3.d[0] = m1->d[0];
  mat3.d[1] = m1->d[3];
  mat3.d[2] = m1->d[6];
  mat3.d[3] = m1->d[1];
  mat3.d[4] = m1->d[4];
  mat3.d[5] = m1->d[7];
  mat3.d[6] = m1->d[2];
  mat3.d[7] = m1->d[5];
  mat3.d[8] = m1->d[8];

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_mat3d_determinant(const oxcart_mat3d_t* m1)
{
  oxcart_vec3d_t vec3;

  OXCART_ASSERT(m1);

  vec3.d[0] =  ((m1->d[4] * m1->d[8]) - (m1->d[7] * m1->d[5]));
  vec3.d[1] = -((m1->d[1] * m1->d[8]) - (m1->d[7] * m1->d[2]));
  vec3.d[2] =  ((m1->d[1] * m1->d[5]) - (m1->d[4] * m1->d[2]));

  return((m1->d[0] * vec3.d[0]) + (m1->d[3] * vec3.d[1]) + (m1->d[6] * vec3.d[2]));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_inverse(const oxcart_mat3d_t* m1, double* d)
{
  int i;
  double odd;
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(d);

  mat3.d[0] =  ((m1->d[4] * m1->d[8]) - (m1->d[7] * m1->d[5]));
  mat3.d[1] = -((m1->d[1] * m1->d[8]) - (m1->d[7] * m1->d[2]));
  mat3.d[2] =  ((m1->d[1] * m1->d[5]) - (m1->d[4] * m1->d[2]));
  mat3.d[3] = -((m1->d[3] * m1->d[8]) - (m1->d[6] * m1->d[5]));
  mat3.d[4] =  ((m1->d[0] * m1->d[8]) - (m1->d[6] * m1->d[2]));
  mat3.d[5] = -((m1->d[0] * m1->d[5]) - (m1->d[3] * m1->d[2]));
  mat3.d[6] =  ((m1->d[3] * m1->d[7]) - (m1->d[6] * m1->d[4]));
  mat3.d[7] = -((m1->d[0] * m1->d[7]) - (m1->d[6] * m1->d[1]));
  mat3.d[8] =  ((m1->d[0] * m1->d[4]) - (m1->d[3] * m1->d[1]));

  if (0.0 == (*d = ((m1->d[0] * mat3.d[0]) + (m1->d[3] * mat3.d[1]) + (m1->d[6] * mat3.d[2])))) {
    return(mat3);
  }

  odd = 1.0 / *d;

  for (i = 0; i < 9; i++) {
    mat3.d[i] *= odd;
  }

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat3d_t OXCART_VCALL oxcart_mat3d_affineinverse(const oxcart_mat3d_t* m1)
{
  oxcart_vec3d_t tran;
  oxcart_mat3d_t mat3;

  OXCART_ASSERT(m1);

  mat3 = *m1;
  mat3.d[6] = 0.0;
  mat3.d[7] = 0.0;
  mat3.d[8] = 1.0;
  mat3 = oxcart_mat3d_transpose(&mat3);

  tran = oxcart_vec3d_set(-m1->d[6], -m1->d[7], m1->d[8]);
  tran = oxcart_vec3d_transform(&tran, &mat3);

  mat3.d[6] = tran.d[0];
  mat3.d[7] = tran.d[1];
  mat3.d[8] = tran.d[2];

  return(mat3);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_identity()
{
  oxcart_mat4d_t mat4 = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0};

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_setm3(const oxcart_mat3d_t* m1)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(m1);

  mat4.d[ 0] = m1->d[0];
  mat4.d[ 1] = m1->d[1];
  mat4.d[ 2] = m1->d[2];
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = m1->d[3];
  mat4.d[ 5] = m1->d[4];
  mat4.d[ 6] = m1->d[5];
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = m1->d[6];
  mat4.d[ 9] = m1->d[7];
  mat4.d[10] = m1->d[8];
  mat4.d[11] = 0.0;
  mat4.d[12] = 0.0;
  mat4.d[13] = 0.0;
  mat4.d[14] = 0.0;
  mat4.d[15] = 1.0;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_mat4d_cast(const oxcart_mat4d_t* m1)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(m1);

  mat4.d[ 0] = (float)m1->d[ 0];
  mat4.d[ 1] = (float)m1->d[ 1];
  mat4.d[ 2] = (float)m1->d[ 2];
  mat4.d[ 3] = (float)m1->d[ 3];
  mat4.d[ 4] = (float)m1->d[ 4];
  mat4.d[ 5] = (float)m1->d[ 5];
  mat4.d[ 6] = (float)m1->d[ 6];
  mat4.d[ 7] = (float)m1->d[ 7];
  mat4.d[ 8] = (float)m1->d[ 8];
  mat4.d[ 9] = (float)m1->d[ 9];
  mat4.d[10] = (float)m1->d[10];
  mat4.d[11] = (float)m1->d[11];
  mat4.d[12] = (float)m1->d[12];
  mat4.d[13] = (float)m1->d[13];
  mat4.d[14] = (float)m1->d[14];
  mat4.d[15] = (float)m1->d[15];

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_rotate(double x, double y, double z, double angle)
{
  oxcart_vec3d_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;
  vec3 = oxcart_vec3d_normalize(&vec3);

  return(oxcart_mat4d_rotatev(&vec3, angle));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_rotatev(const oxcart_vec3d_t* v1, double angle)
{
  double rad;
  double s, c, omc;
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(v1);

  rad = OXCART_DEG2RADd(angle);
  s = sin(rad);
  c = cos(rad);

  if (OXCART_ISZEROd(s)) {
    s = 0.0;
  }

  if (OXCART_ISZEROd(c)) {
    c = 0.0;
  }

  omc = 1.0 - c;

  mat4.d[ 0] = (v1->d[0] * v1->d[0] * omc) + c;
  mat4.d[ 1] = (v1->d[0] * v1->d[1] * omc) + (v1->d[2] * s);
  mat4.d[ 2] = (v1->d[0] * v1->d[2] * omc) - (v1->d[1] * s);
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = (v1->d[1] * v1->d[0] * omc) - (v1->d[2] * s);
  mat4.d[ 5] = (v1->d[1] * v1->d[1] * omc) + c;
  mat4.d[ 6] = (v1->d[1] * v1->d[2] * omc) + (v1->d[0] * s);
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = (v1->d[2] * v1->d[0] * omc) + (v1->d[1] * s);
  mat4.d[ 9] = (v1->d[2] * v1->d[1] * omc) - (v1->d[0] * s);
  mat4.d[10] = (v1->d[2] * v1->d[2] * omc) + c;
  mat4.d[11] = 0.0;
  mat4.d[12] = 0.0;
  mat4.d[13] = 0.0;
  mat4.d[14] = 0.0;
  mat4.d[15] = 1.0;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_translate(double x, double y, double z)
{
  oxcart_vec3d_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(oxcart_mat4d_translatev(&vec3));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_translatev(const oxcart_vec3d_t* v1)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(v1);

  mat4.d[ 0] = 1.0;
  mat4.d[ 1] = 0.0;
  mat4.d[ 2] = 0.0;
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = 0.0;
  mat4.d[ 5] = 1.0;
  mat4.d[ 6] = 0.0;
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = 0.0;
  mat4.d[ 9] = 0.0;
  mat4.d[10] = 1.0;
  mat4.d[11] = 0.0;
  mat4.d[12] = v1->d[0];
  mat4.d[13] = v1->d[1];
  mat4.d[14] = v1->d[2];
  mat4.d[15] = 1.0;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_scale(double x, double y, double z)
{
  oxcart_vec3d_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(oxcart_mat4d_scalev(&vec3));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_scalev(const oxcart_vec3d_t* v1)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(v1);

  mat4.d[ 0] = v1->d[0];
  mat4.d[ 1] = 0.0;
  mat4.d[ 2] = 0.0;
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = 0.0;
  mat4.d[ 5] = v1->d[1];
  mat4.d[ 6] = 0.0;
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = 0.0;
  mat4.d[ 9] = 0.0;
  mat4.d[10] = v1->d[2];
  mat4.d[11] = 0.0;
  mat4.d[12] = 0.0;
  mat4.d[13] = 0.0;
  mat4.d[14] = 0.0;
  mat4.d[15] = 1.0;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_multiply(const oxcart_mat4d_t* m1, const oxcart_mat4d_t* m2)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(m2);

  mat4.d[ 0] = (m1->d[ 0] * m2->d[ 0]) + (m1->d[ 4] * m2->d[ 1]) + (m1->d[ 8] * m2->d[ 2]) + (m1->d[12] * m2->d[ 3]);
  mat4.d[ 1] = (m1->d[ 1] * m2->d[ 0]) + (m1->d[ 5] * m2->d[ 1]) + (m1->d[ 9] * m2->d[ 2]) + (m1->d[13] * m2->d[ 3]);
  mat4.d[ 2] = (m1->d[ 2] * m2->d[ 0]) + (m1->d[ 6] * m2->d[ 1]) + (m1->d[10] * m2->d[ 2]) + (m1->d[14] * m2->d[ 3]);
  mat4.d[ 3] = (m1->d[ 3] * m2->d[ 0]) + (m1->d[ 7] * m2->d[ 1]) + (m1->d[11] * m2->d[ 2]) + (m1->d[15] * m2->d[ 3]);
  mat4.d[ 4] = (m1->d[ 0] * m2->d[ 4]) + (m1->d[ 4] * m2->d[ 5]) + (m1->d[ 8] * m2->d[ 6]) + (m1->d[12] * m2->d[ 7]);
  mat4.d[ 5] = (m1->d[ 1] * m2->d[ 4]) + (m1->d[ 5] * m2->d[ 5]) + (m1->d[ 9] * m2->d[ 6]) + (m1->d[13] * m2->d[ 7]);
  mat4.d[ 6] = (m1->d[ 2] * m2->d[ 4]) + (m1->d[ 6] * m2->d[ 5]) + (m1->d[10] * m2->d[ 6]) + (m1->d[14] * m2->d[ 7]);
  mat4.d[ 7] = (m1->d[ 3] * m2->d[ 4]) + (m1->d[ 7] * m2->d[ 5]) + (m1->d[11] * m2->d[ 6]) + (m1->d[15] * m2->d[ 7]);
  mat4.d[ 8] = (m1->d[ 0] * m2->d[ 8]) + (m1->d[ 4] * m2->d[ 9]) + (m1->d[ 8] * m2->d[10]) + (m1->d[12] * m2->d[11]);
  mat4.d[ 9] = (m1->d[ 1] * m2->d[ 8]) + (m1->d[ 5] * m2->d[ 9]) + (m1->d[ 9] * m2->d[10]) + (m1->d[13] * m2->d[11]);
  mat4.d[10] = (m1->d[ 2] * m2->d[ 8]) + (m1->d[ 6] * m2->d[ 9]) + (m1->d[10] * m2->d[10]) + (m1->d[14] * m2->d[11]);
  mat4.d[11] = (m1->d[ 3] * m2->d[ 8]) + (m1->d[ 7] * m2->d[ 9]) + (m1->d[11] * m2->d[10]) + (m1->d[15] * m2->d[11]);
  mat4.d[12] = (m1->d[ 0] * m2->d[12]) + (m1->d[ 4] * m2->d[13]) + (m1->d[ 8] * m2->d[14]) + (m1->d[12] * m2->d[15]);
  mat4.d[13] = (m1->d[ 1] * m2->d[12]) + (m1->d[ 5] * m2->d[13]) + (m1->d[ 9] * m2->d[14]) + (m1->d[13] * m2->d[15]);
  mat4.d[14] = (m1->d[ 2] * m2->d[12]) + (m1->d[ 6] * m2->d[13]) + (m1->d[10] * m2->d[14]) + (m1->d[14] * m2->d[15]);
  mat4.d[15] = (m1->d[ 3] * m2->d[12]) + (m1->d[ 7] * m2->d[13]) + (m1->d[11] * m2->d[14]) + (m1->d[15] * m2->d[15]);

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_transpose(const oxcart_mat4d_t* m1)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(m1);

  mat4.d[ 0] = m1->d[ 0];
  mat4.d[ 1] = m1->d[ 4];
  mat4.d[ 2] = m1->d[ 8];
  mat4.d[ 3] = m1->d[12];
  mat4.d[ 4] = m1->d[ 1];
  mat4.d[ 5] = m1->d[ 5];
  mat4.d[ 6] = m1->d[ 9];
  mat4.d[ 7] = m1->d[13];
  mat4.d[ 8] = m1->d[ 2];
  mat4.d[ 9] = m1->d[ 6];
  mat4.d[10] = m1->d[10];
  mat4.d[11] = m1->d[14];
  mat4.d[12] = m1->d[ 3];
  mat4.d[13] = m1->d[ 7];
  mat4.d[14] = m1->d[11];
  mat4.d[15] = m1->d[15];

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE double OXCART_VCALL oxcart_mat4d_determinant(const oxcart_mat4d_t* m1)
{
  oxcart_vec4d_t vec4;

  OXCART_ASSERT(m1);

  vec4.d[0] = (m1->d[ 5] * ((m1->d[10] * m1->d[15]) - (m1->d[11] * m1->d[14]))) - (m1->d[ 9] * ((m1->d[ 6] * m1->d[15]) - (m1->d[ 7] * m1->d[14]))) - (m1->d[13] * ((m1->d[ 7] * m1->d[10]) - (m1->d[ 6] * m1->d[11])));
  vec4.d[1] = (m1->d[ 4] * ((m1->d[11] * m1->d[14]) - (m1->d[10] * m1->d[15]))) - (m1->d[ 8] * ((m1->d[ 7] * m1->d[14]) - (m1->d[ 6] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 6] * m1->d[11]) - (m1->d[ 7] * m1->d[10])));
  vec4.d[2] = (m1->d[ 4] * ((m1->d[ 9] * m1->d[15]) - (m1->d[11] * m1->d[13]))) - (m1->d[ 8] * ((m1->d[ 5] * m1->d[15]) - (m1->d[ 7] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 7] * m1->d[ 9]) - (m1->d[ 5] * m1->d[11])));
  vec4.d[3] = (m1->d[ 4] * ((m1->d[10] * m1->d[13]) - (m1->d[ 9] * m1->d[14]))) - (m1->d[ 8] * ((m1->d[ 6] * m1->d[13]) - (m1->d[ 5] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 5] * m1->d[10]) - (m1->d[ 6] * m1->d[ 9])));

  return((m1->d[0] * vec4.d[0]) + (m1->d[1] * vec4.d[1]) + (m1->d[2] * vec4.d[2]) + (m1->d[3] * vec4.d[3]));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_inverse(const oxcart_mat4d_t* m1, double* d)
{
  int i;
  double odd;
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(m1);
  OXCART_ASSERT(d);

  mat4.d[ 0] = (m1->d[ 5] * ((m1->d[10] * m1->d[15]) - (m1->d[11] * m1->d[14]))) - (m1->d[ 9] * ((m1->d[ 6] * m1->d[15]) - (m1->d[ 7] * m1->d[14]))) - (m1->d[13] * ((m1->d[ 7] * m1->d[10]) - (m1->d[ 6] * m1->d[11])));
  mat4.d[ 1] = (m1->d[ 1] * ((m1->d[11] * m1->d[14]) - (m1->d[10] * m1->d[15]))) - (m1->d[ 9] * ((m1->d[ 3] * m1->d[14]) - (m1->d[ 2] * m1->d[15]))) - (m1->d[13] * ((m1->d[ 2] * m1->d[11]) - (m1->d[ 3] * m1->d[10])));
  mat4.d[ 2] = (m1->d[ 1] * ((m1->d[ 6] * m1->d[15]) - (m1->d[ 7] * m1->d[14]))) - (m1->d[ 5] * ((m1->d[ 2] * m1->d[15]) - (m1->d[ 3] * m1->d[14]))) - (m1->d[13] * ((m1->d[ 3] * m1->d[ 6]) - (m1->d[ 2] * m1->d[ 7])));
  mat4.d[ 3] = (m1->d[ 1] * ((m1->d[ 7] * m1->d[10]) - (m1->d[ 6] * m1->d[11]))) - (m1->d[ 5] * ((m1->d[ 3] * m1->d[10]) - (m1->d[ 2] * m1->d[11]))) - (m1->d[ 9] * ((m1->d[ 2] * m1->d[ 7]) - (m1->d[ 3] * m1->d[ 6])));
  mat4.d[ 4] = (m1->d[ 4] * ((m1->d[11] * m1->d[14]) - (m1->d[10] * m1->d[15]))) - (m1->d[ 8] * ((m1->d[ 7] * m1->d[14]) - (m1->d[ 6] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 6] * m1->d[11]) - (m1->d[ 7] * m1->d[10])));
  mat4.d[ 5] = (m1->d[ 0] * ((m1->d[10] * m1->d[15]) - (m1->d[11] * m1->d[14]))) - (m1->d[ 8] * ((m1->d[ 2] * m1->d[15]) - (m1->d[ 3] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 3] * m1->d[10]) - (m1->d[ 2] * m1->d[11])));
  mat4.d[ 6] = (m1->d[ 0] * ((m1->d[ 7] * m1->d[14]) - (m1->d[ 6] * m1->d[15]))) - (m1->d[ 4] * ((m1->d[ 3] * m1->d[14]) - (m1->d[ 2] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 2] * m1->d[ 7]) - (m1->d[ 3] * m1->d[ 6])));
  mat4.d[ 7] = (m1->d[ 0] * ((m1->d[ 6] * m1->d[11]) - (m1->d[ 7] * m1->d[10]))) - (m1->d[ 4] * ((m1->d[ 2] * m1->d[11]) - (m1->d[ 3] * m1->d[10]))) - (m1->d[ 8] * ((m1->d[ 3] * m1->d[ 6]) - (m1->d[ 2] * m1->d[ 7])));
  mat4.d[ 8] = (m1->d[ 4] * ((m1->d[ 9] * m1->d[15]) - (m1->d[11] * m1->d[13]))) - (m1->d[ 8] * ((m1->d[ 5] * m1->d[15]) - (m1->d[ 7] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 7] * m1->d[ 9]) - (m1->d[ 5] * m1->d[11])));
  mat4.d[ 9] = (m1->d[ 0] * ((m1->d[11] * m1->d[13]) - (m1->d[ 9] * m1->d[15]))) - (m1->d[ 8] * ((m1->d[ 3] * m1->d[13]) - (m1->d[ 1] * m1->d[15]))) - (m1->d[12] * ((m1->d[ 1] * m1->d[11]) - (m1->d[ 3] * m1->d[ 9])));
  mat4.d[10] = (m1->d[ 0] * ((m1->d[ 5] * m1->d[15]) - (m1->d[ 7] * m1->d[13]))) - (m1->d[ 4] * ((m1->d[ 1] * m1->d[15]) - (m1->d[ 3] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 3] * m1->d[ 5]) - (m1->d[ 1] * m1->d[ 7])));
  mat4.d[11] = (m1->d[ 0] * ((m1->d[ 7] * m1->d[ 9]) - (m1->d[ 5] * m1->d[11]))) - (m1->d[ 4] * ((m1->d[ 3] * m1->d[ 9]) - (m1->d[ 1] * m1->d[11]))) - (m1->d[ 8] * ((m1->d[ 1] * m1->d[ 7]) - (m1->d[ 3] * m1->d[ 5])));
  mat4.d[12] = (m1->d[ 4] * ((m1->d[10] * m1->d[13]) - (m1->d[ 9] * m1->d[14]))) - (m1->d[ 8] * ((m1->d[ 6] * m1->d[13]) - (m1->d[ 5] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 5] * m1->d[10]) - (m1->d[ 6] * m1->d[ 9])));
  mat4.d[13] = (m1->d[ 0] * ((m1->d[ 9] * m1->d[14]) - (m1->d[10] * m1->d[13]))) - (m1->d[ 8] * ((m1->d[ 1] * m1->d[14]) - (m1->d[ 2] * m1->d[13]))) - (m1->d[12] * ((m1->d[ 2] * m1->d[ 9]) - (m1->d[ 1] * m1->d[10])));
  mat4.d[14] = (m1->d[ 0] * ((m1->d[ 6] * m1->d[13]) - (m1->d[ 5] * m1->d[14]))) - (m1->d[ 4] * ((m1->d[ 2] * m1->d[13]) - (m1->d[ 1] * m1->d[14]))) - (m1->d[12] * ((m1->d[ 1] * m1->d[ 6]) - (m1->d[ 2] * m1->d[ 5])));
  mat4.d[15] = (m1->d[ 0] * ((m1->d[ 5] * m1->d[10]) - (m1->d[ 6] * m1->d[ 9]))) - (m1->d[ 4] * ((m1->d[ 1] * m1->d[10]) - (m1->d[ 2] * m1->d[ 9]))) - (m1->d[ 8] * ((m1->d[ 2] * m1->d[ 5]) - (m1->d[ 1] * m1->d[ 6])));

  if (0.0 == (*d = ((m1->d[0] * mat4.d[0]) + (m1->d[1] * mat4.d[4]) + (m1->d[2] * mat4.d[8]) + (m1->d[3] * mat4.d[12])))) {
    return(mat4);
  }

  odd = 1.0 / *d;

  for (i = 0; i < 16; i++) {
    mat4.d[i] *= odd;
  }

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_affineinverse(const oxcart_mat4d_t* m1)
{
  oxcart_vec4d_t tran;
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(m1);

  mat4 = *m1;
  mat4.d[12] = 0.0;
  mat4.d[13] = 0.0;
  mat4.d[14] = 0.0;
  mat4.d[15] = 1.0;
  mat4 = oxcart_mat4d_transpose(&mat4);

  tran = oxcart_vec4d_set(-m1->d[12], -m1->d[13], -m1->d[14], m1->d[15]);
  tran = oxcart_vec4d_transform(&tran, &mat4);

  mat4.d[12] = tran.d[0];
  mat4.d[13] = tran.d[1];
  mat4.d[14] = tran.d[2];
  mat4.d[15] = tran.d[3];

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_orthographic(double w, double h)
{
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(w > 0.0);
  OXCART_ASSERT(h > 0.0);

  mat4.d[ 0] = 2.0 / w;
  mat4.d[ 1] = 0.0;
  mat4.d[ 2] = 0.0;
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = 0.0;
  mat4.d[ 5] = 2.0 / -h;
  mat4.d[ 6] = 0.0;
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = 0.0;
  mat4.d[ 9] = 0.0;
  mat4.d[10] = -1.0;
  mat4.d[11] = 0.0;
  mat4.d[12] = -1.0;
  mat4.d[13] = 1.0;
  mat4.d[14] = 0.0;
  mat4.d[15] = 1.0;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_perspective(double fovy, double aspect, double n, double f)
{
  double w, h;
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(fovy > 0.0);
  OXCART_ASSERT(aspect > 0.0);
  OXCART_ASSERT(f > n);

  h = n * tan(OXCART_DEG2RADd(fovy * 0.5));
  w = h * aspect;

  mat4.d[ 0] = n / w;
  mat4.d[ 1] = 0.0;
  mat4.d[ 2] = 0.0;
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = 0.0;
  mat4.d[ 5] = n / h;
  mat4.d[ 6] = 0.0;
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = 0.0;
  mat4.d[ 9] = 0.0;
  mat4.d[10] = (n + f) / (n - f);
  mat4.d[11] = -1.0;
  mat4.d[12] = 0.0;
  mat4.d[13] = 0.0;
  mat4.d[14] = (2.0 * n * f) / (n - f);
  mat4.d[15] = 0.0;

  return(mat4);
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4d_t OXCART_VCALL oxcart_mat4d_lookat(const oxcart_vec3d_t* eye, const oxcart_vec3d_t* target, const oxcart_vec3d_t* up)
{
  oxcart_vec3d_t x;
  oxcart_vec3d_t y;
  oxcart_vec3d_t z;
  oxcart_mat4d_t mat4;

  OXCART_ASSERT(eye);
  OXCART_ASSERT(target);
  OXCART_ASSERT(up);

  z = oxcart_vec3d_subtract(eye, target);
  z = oxcart_vec3d_normalize(&z);
  x = oxcart_vec3d_cross(up, &z);
  x = oxcart_vec3d_normalize(&x);
  y = oxcart_vec3d_cross(&z, &x);

  mat4.d[ 0] = x.d[0];
  mat4.d[ 1] = y.d[0];
  mat4.d[ 2] = z.d[0];
  mat4.d[ 3] = 0.0;
  mat4.d[ 4] = x.d[1];
  mat4.d[ 5] = y.d[1];
  mat4.d[ 6] = z.d[1];
  mat4.d[ 7] = 0.0;
  mat4.d[ 8] = x.d[2];
  mat4.d[ 9] = y.d[2];
  mat4.d[10] = z.d[2];
  mat4.d[11] = 0.0;
  mat4.d[12] = -oxcart_vec3d_dot(&x, eye);
  mat4.d[13] = -oxcart_vec3d_dot(&y, eye);
  mat4.d[14] = -oxcart_vec3d_dot(&z, eye);
  mat4.d[15] = 1.0;

  return(mat4);
}
