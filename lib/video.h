
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static napi_value NAPI_SDL_CreateWindow(napi_env env, napi_callback_info info) {
  napi_status status;

  unsigned long int strResult;

  size_t argc = 6;
  napi_value args[6];

  char* name;
  unsigned long int xPos;
  unsigned long int yPos;
  unsigned long int width;
  unsigned long int height;
  unsigned long int flags;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);
  status = napi_get_value_string_utf8(env, args[0], &name, NAPI_AUTO_LENGTH, &strResult);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[1], &xPos);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[2], &yPos);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[3], &width);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[4], &height);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[5], &flags);
  assert(status == napi_ok);

  SDL_Window* res = SDL_CreateWindow(name, xPos, yPos, width, height, flags);

  status = napi_create_int64(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}
