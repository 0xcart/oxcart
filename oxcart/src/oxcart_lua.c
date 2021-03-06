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
#include <physfs.h>
#include "oxcart_assert.h"
#include "oxcart_lua.h"

typedef struct oxcart_luafdata_t oxcart_luafdata_t;

struct oxcart_luafdata_t
{
  PHYSFS_file *file;
  char buffer[LUAL_BUFFERSIZE];
};

static void _lua_doexpr(lua_State *L, const char *expr);
static int _lua_traceback(lua_State *L);
static int _lua_searcher(lua_State *L);
static int _lua_loadfile(lua_State *L);
static const char *_lua_freader(lua_State *L, void *data, size_t *size);

/**
 *
 */
lua_State *oxcart_lua_newstate()
{
  int i;
  lua_State *L;

  if (!(L = luaL_newstate())) {
    OXCART_ASSERT(!"luaL_newstate() failed");
  }

  luaL_openlibs(L);

  lua_pushcfunction(L, _lua_traceback);
  lua_setglobal(L, "_lua_traceback");

  lua_getglobal(L, "package");
  if (!lua_istable(L, -1)) {
    OXCART_ASSERT(!"lua_istable() failed");
  }

  lua_getfield(L, -1, "loaders");
  if (!lua_istable(L, -1)) {
    OXCART_ASSERT(!"lua_istable() failed");
  }

  /* right shift elements in package.loaders to free second slot */
  for (i = lua_objlen(L, -1); i >= 2; i--) {
    lua_rawgeti(L, -1, i);
    lua_rawseti(L, -2, i + 1);
  }

  /* insert _lua_searcher into second slot of package.loaders */
  lua_pushcfunction(L, _lua_searcher);
  lua_rawseti(L, -2, 2);
  lua_pop(L, 2);

  return(L);
}

/**
 *
 */
int oxcart_lua_pcall(lua_State *L, int nargs, int nresults)
{
  int index;
  int status;

  OXCART_ASSERT(L);

  index = lua_gettop(L) - nargs;

  lua_getglobal(L, "_lua_traceback");
  if (!lua_isfunction(L, -1)) {
    OXCART_ASSERT(!"lua_isfunction() failed");
  }

  /* put _lua_traceback under chunk and args */
  lua_insert(L, index);
  status = lua_pcall(L, nargs, nresults, index);
  lua_remove(L, index);

  if (status) {
    #ifdef _DEBUG
      fprintf_s(stderr, "%s\n", lua_tostring(L, -1));
    #endif

    lua_pop(L, 1);
  }

  return(status);
}

/**
 *
 */
int oxcart_lua_loadfile(lua_State *L, const char *filename)
{
  OXCART_ASSERT(L);
  OXCART_ASSERT(filename);

  lua_pushcfunction(L, _lua_loadfile);
  lua_pushstring(L, filename);

  if (oxcart_lua_pcall(L, 1, 1)) {
    return(1);
  }

  return(0);
}

/**
 *
 */
int oxcart_lua_toboolean(lua_State *L, const char *expr)
{
  OXCART_ASSERT(L);
  OXCART_ASSERT(expr);

  _lua_doexpr(L, expr);

  if (!lua_isboolean(L, -1)) {
    #ifdef _DEBUG
      fprintf_s(stderr, "%s\n", expr);
    #endif

    OXCART_ASSERT(!"lua_isboolean() failed");
  }

  return(lua_toboolean(L, -1));
}

/**
 *
 */
int oxcart_lua_tointeger(lua_State *L, const char *expr)
{
  OXCART_ASSERT(L);
  OXCART_ASSERT(expr);

  _lua_doexpr(L, expr);

  if (!lua_isnumber(L, -1)) {
    #ifdef _DEBUG
      fprintf_s(stderr, "%s\n", expr);
    #endif

    OXCART_ASSERT(!"lua_isnumber() failed");
  }

  return(lua_tointeger(L, -1));
}

/**
 *
 */
double oxcart_lua_tonumber(lua_State *L, const char *expr)
{
  OXCART_ASSERT(L);
  OXCART_ASSERT(expr);

  _lua_doexpr(L, expr);

  if (!lua_isnumber(L, -1)) {
    #ifdef _DEBUG
      fprintf_s(stderr, "%s\n", expr);
    #endif

    OXCART_ASSERT(!"lua_isnumber() failed");
  }

  return(lua_tonumber(L, -1));
}

/**
 *
 */
const char *oxcart_lua_tostring(lua_State *L, const char *expr)
{
  OXCART_ASSERT(L);
  OXCART_ASSERT(expr);

  _lua_doexpr(L, expr);

  if (!lua_isstring(L, -1)) {
    #ifdef _DEBUG
      fprintf_s(stderr, "%s\n", expr);
    #endif

    OXCART_ASSERT(!"lua_isstring() failed");
  }

  return(lua_tostring(L, -1));
}

/**
 *
 */
static void _lua_doexpr(lua_State *L, const char *expr)
{
  static char buffer[LUAL_BUFFERSIZE];

  OXCART_ASSERT(L);
  OXCART_ASSERT(expr);

  sprintf_s(buffer, LUAL_BUFFERSIZE, "return(%s)", expr);

  if (OXCART_LUA_DOSTRING(L, buffer)) {
    OXCART_ASSERT(!"OXCART_LUA_DOSTRING() failed");
  }
}

/**
 *
 */
static int _lua_traceback(lua_State *L)
{
  if (!lua_isstring(L, 1)) {
    return(1);
  }

  lua_getglobal(L, "debug");
  if (!lua_istable(L, -1)) {
    lua_pop(L, 1);
    return(1);
  }

  lua_getfield(L, -1, "traceback");
  if (!lua_isfunction(L, -1)) {
    lua_pop(L, 2);
    return(1);
  }

  lua_pushvalue(L, 1);   /* pass error message */
  lua_pushinteger(L, 2); /* skip this function and traceback */
  lua_call(L, 2, 1);     /* call debug.traceback */

  return(1);
}

/**
 *
 */
static int _lua_searcher(lua_State *L)
{
  const char *module;

  if (!(module = luaL_checkstring(L, 1))) {
    return(lua_error(L));
  }

  lua_pushcfunction(L, _lua_loadfile);
  lua_pushstring(L, "/");
  luaL_gsub(L, module, ".", "/");
  lua_pushstring(L, ".lua");
  lua_concat(L, 3);
  lua_call(L, 1, 1);

  return(1);
}

/**
 *
 */
static int _lua_loadfile(lua_State *L)
{
  int status;
  const char *filename;
  oxcart_luafdata_t fdata;

  if (!(filename = luaL_checkstring(L, 1))) {
    return(lua_error(L));
  }

  if (!(fdata.file = PHYSFS_openRead(filename))) {
    return(luaL_error(L, "%s: %s", filename, PHYSFS_getLastError()));
  }

  status = lua_load(L, _lua_freader, &fdata, filename);
  PHYSFS_close(fdata.file);

  if (status) {
    return(lua_error(L));
  }

  return(1);
}

/**
 *
 */
static const char *_lua_freader(lua_State *L, void *data, size_t *size)
{
  PHYSFS_sint64 count;
  oxcart_luafdata_t *fdata = (oxcart_luafdata_t*)data;

  if (0 >= (count = PHYSFS_read(fdata->file, fdata->buffer, 1, LUAL_BUFFERSIZE))) {
    *size = 0;
    return(0);
  }

  *size = (size_t)count;
  return(fdata->buffer);
}
