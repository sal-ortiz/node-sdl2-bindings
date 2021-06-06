
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static void NAPI_SDL_GetError(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  const char* res = SDL_GetError();

  status = napi_create_string_utf8(env, res, NAPI_AUTO_LENGTH, retval);
  assert(status == napi_ok);

  return retval;
}

static void NAPI_SDL_ClearError(napi_env env, napi_callback_info info) {
  SDL_ClearError();
}

static napi_value NAPI_SDL_SetError(napi_env env, napi_callback_info info) {
  // NOTE: currently only takes a single argument, format string.
  //       does not take % tokens for the format string.
  napi_status status;

  unsigned long int strResult;

  size_t argc = 1;
  napi_value args[1];

  char* formatStr;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_string_utf8(env, args[0], &formatStr, NAPI_AUTO_LENGTH, &strResult);
  assert(status == napi_ok);

  unsigned long int res = SDL_Init(formatStr);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}
