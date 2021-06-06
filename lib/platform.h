
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static napi_value NAPI_SDL_GetPlatform(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  const char* res = SDL_GetPlatform();

  status = napi_create_string_utf8(env, res, NAPI_AUTO_LENGTH, &retval);
  assert(status == napi_ok);

  return retval;
}
