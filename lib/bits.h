
#include <stdint.h>
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static napi_value NAPI_SDL_MostSignificantBitIndex32(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned int res = SDL_MostSignificantBitIndex32(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}
