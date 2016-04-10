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

  return((a * omt) + (b * t));
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

  vec2.d[0] = (v1->d[0] * omt) + (v2->d[0] * t);
  vec2.d[1] = (v1->d[1] * omt) + (v2->d[1] * t);

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

  return(acosf(angle));
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

  vec3.d[0] = (v1->d[0] * omt) + (v2->d[0] * t);
  vec3.d[1] = (v1->d[1] * omt) + (v2->d[1] * t);
  vec3.d[2] = (v1->d[2] * omt) + (v2->d[2] * t);

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

  return(acosf(angle));
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

  vec4.d[0] = (v1->d[0] * omt) + (v2->d[0] * t);
  vec4.d[1] = (v1->d[1] * omt) + (v2->d[1] * t);
  vec4.d[2] = (v1->d[2] * omt) + (v2->d[2] * t);
  vec4.d[3] = (v1->d[3] * omt) + (v2->d[3] * t);

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

  return(acosf(angle));
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
OXCART_INLINE oxcart_mat3f_t OXCART_VCALL oxcart_mat3f_rotate(float angle)
{
  float s, c;
  oxcart_mat3f_t mat3;

  s = sinf(angle);
  c = cosf(angle);

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
  float rd;
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

  rd = 1.0f / *d;

  for (i = 0; i < 9; i++) {
    mat3.d[i] *= rd;
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
  float s, c, omc;
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(v1);

  s = sinf(angle);
  c = cosf(angle);

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
  float rd;
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

  rd = 1.0f / *d;

  for (i = 0; i < 16; i++) {
    mat4.d[i] *= rd;
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

  h = n * tanf(fovy * 0.5f);
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
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_identity()
{
  oxcart_quatf_t quat = {0.0f, 0.0f, 0.0f, 1.0f};

  return(quat);
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_multiply(const oxcart_quatf_t* q1, const oxcart_quatf_t* q2)
{
  oxcart_quatf_t quat;

  OXCART_ASSERT(q1);
  OXCART_ASSERT(q2);

  quat.d[0] = (q1->d[1] * q2->d[2]) - (q1->d[2] * q2->d[1]) + (q1->d[0] * q2->d[3]) + (q1->d[3] * q2->d[0]);
  quat.d[1] = (q1->d[2] * q2->d[0]) - (q1->d[0] * q2->d[2]) + (q1->d[1] * q2->d[3]) + (q1->d[3] * q2->d[1]);
  quat.d[2] = (q1->d[0] * q2->d[1]) - (q1->d[1] * q2->d[0]) + (q1->d[2] * q2->d[3]) + (q1->d[3] * q2->d[2]);
  quat.d[3] = (q1->d[3] * q2->d[3]) - (q1->d[0] * q2->d[0]) - (q1->d[1] * q2->d[1]) - (q1->d[2] * q2->d[2]);

  return(quat);
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_multiplyscalar(const oxcart_quatf_t* q1, float s)
{
  oxcart_quatf_t quat;

  OXCART_ASSERT(q1);

  quat.d[0] = q1->d[0] * s;
  quat.d[1] = q1->d[1] * s;
  quat.d[2] = q1->d[2] * s;
  quat.d[3] = q1->d[3] * s;

  return(quat);
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_conjugate(const oxcart_quatf_t* q1)
{
  oxcart_quatf_t quat;

  OXCART_ASSERT(q1);

  quat.d[0] = -q1->d[0];
  quat.d[1] = -q1->d[1];
  quat.d[2] = -q1->d[2];
  quat.d[3] = q1->d[3];

  return(quat);
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_inverse(const oxcart_quatf_t* q1)
{
  float rls;
  oxcart_quatf_t quat;

  OXCART_ASSERT(q1);

  rls = oxcart_vec4f_lengthsq(q1);

  if (rls > 0.0f) {
    rls = 1.0f / rls;
  }

  quat = oxcart_quatf_conjugate(q1);
  quat = oxcart_quatf_multiplyscalar(&quat, rls);

  return(quat);
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_euler(float x, float y, float z)
{
  oxcart_vec3f_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;

  return(oxcart_quatf_eulerv(&vec3));
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_eulerv(const oxcart_vec3f_t* v1)
{
  float s1, s2, s3;
  float c1, c2, c3;
  oxcart_quatf_t quat;

  OXCART_ASSERT(v1);

  s1 = sinf(v1->d[0] * 0.5f);
  c1 = cosf(v1->d[0] * 0.5f);
  s2 = sinf(v1->d[1] * 0.5f);
  c2 = cosf(v1->d[1] * 0.5f);
  s3 = sinf(v1->d[2] * 0.5f);
  c3 = cosf(v1->d[2] * 0.5f);

  quat.d[0] = (s1 * c2 * c3) - (c1 * s2 * s3);
  quat.d[1] = (c1 * s2 * c3) + (s1 * c2 * s3);
  quat.d[2] = (c1 * c2 * s3) - (s1 * s2 * c3);
  quat.d[3] = (c1 * c2 * c3) + (s1 * s2 * s3);

  return(oxcart_vec4f_normalize(&quat));
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_angleaxis(float angle, float x, float y, float z)
{
  oxcart_vec3f_t vec3;

  vec3.d[0] = x;
  vec3.d[1] = y;
  vec3.d[2] = z;
  vec3 = oxcart_vec3f_normalize(&vec3);

  return(oxcart_quatf_angleaxisv(angle, &vec3));
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_angleaxisv(float angle, const oxcart_vec3f_t* v1)
{
  float s, c;
  oxcart_quatf_t quat;

  OXCART_ASSERT(v1);

  s = sinf(angle * 0.5f);
  c = cosf(angle * 0.5f);

  quat.d[0] = v1->d[0] * s;
  quat.d[1] = v1->d[1] * s;
  quat.d[2] = v1->d[2] * s;
  quat.d[3] = c;

  return(quat);
}

/**
 * 
 */
OXCART_INLINE oxcart_quatf_t OXCART_VCALL oxcart_quatf_slerp(const oxcart_quatf_t* q1, const oxcart_quatf_t* q2, float t)
{
  float angle, rsa, s1, s2;
  oxcart_quatf_t quat1;
  oxcart_quatf_t quat2;

  OXCART_ASSERT(q1);
  OXCART_ASSERT(q2);

  quat1 = *q1;
  quat2 = *q2;

  angle = oxcart_vec4f_dot(&quat1, &quat2);

  /* if angle is less than 0, negate values to take short way around sphere */
  if (angle < 0.0f) {
    angle = -angle;
    quat1.d[0] = -quat1.d[0];
    quat1.d[1] = -quat1.d[1];
    quat1.d[2] = -quat1.d[2];
    quat1.d[3] = -quat1.d[3];
  }

  if (angle > (1.0f - FLT_EPSILON)) {
    return(oxcart_vec4f_lerp(&quat1, &quat2, t));
  }

  t = oxcart_clampf(t, 0.0f, 1.0f);
  angle = acosf(angle);
  rsa = 1.0f / sinf(angle);
  s1 = sinf(angle * (1.0f - t)) * rsa;
  s2 = sinf(angle * t) * rsa;

  quat1 = oxcart_quatf_multiplyscalar(&quat1, s1);
  quat2 = oxcart_quatf_multiplyscalar(&quat2, s2);

  return(oxcart_vec4f_add(&quat1, &quat2));
}

/**
 * 
 */
OXCART_INLINE oxcart_mat4f_t OXCART_VCALL oxcart_quatf_matrix(const oxcart_quatf_t* q1)
{
  oxcart_mat4f_t mat4;

  OXCART_ASSERT(q1);

  mat4.d[ 0] = 1.0f - 2.0f * ((q1->d[1] * q1->d[1]) + (q1->d[2] * q1->d[2]));
  mat4.d[ 1] =        2.0f * ((q1->d[0] * q1->d[1]) - (q1->d[2] * q1->d[3]));
  mat4.d[ 2] =        2.0f * ((q1->d[0] * q1->d[2]) + (q1->d[1] * q1->d[3]));
  mat4.d[ 3] =        0.0f;
  mat4.d[ 4] =        2.0f * ((q1->d[0] * q1->d[1]) + (q1->d[2] * q1->d[3]));
  mat4.d[ 5] = 1.0f - 2.0f * ((q1->d[0] * q1->d[0]) + (q1->d[2] * q1->d[2]));
  mat4.d[ 6] =        2.0f * ((q1->d[1] * q1->d[2]) - (q1->d[0] * q1->d[3]));
  mat4.d[ 7] =        0.0f;
  mat4.d[ 8] =        2.0f * ((q1->d[0] * q1->d[2]) - (q1->d[1] * q1->d[3]));
  mat4.d[ 9] =        2.0f * ((q1->d[1] * q1->d[2]) + (q1->d[0] * q1->d[3]));
  mat4.d[10] = 1.0f - 2.0f * ((q1->d[0] * q1->d[0]) + (q1->d[1] * q1->d[1]));
  mat4.d[11] =        0.0f;
  mat4.d[12] =        0.0f;
  mat4.d[13] =        0.0f;
  mat4.d[14] =        0.0f;
  mat4.d[15] =        1.0f;

  return(mat4);
}
