
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


//static napi_value NAPI_SDL_GetPowerInfo(napi_env env, napi_callback_info info) {
//  napi_status status;
//
//  size_t argc = 1;
//  napi_value args[1];
//
//  unsigned int secs;
//  unsigned int pct;
//
//  napi_value retval;
//
//  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
//  assert(status == napi_ok);
//
//  status = napi_get_value_int32(env, args[0], &secs);
//  assert(status == napi_ok);
//
//  status = napi_get_value_int32(env, args[0], &pct);
//  assert(status == napi_ok);
//
//  SDL_PowerState res = SDL_GetPowerInfo(&secs, &pct);
//
//  status = napi_create_int32(env, res, &retval);
//  assert(status == napi_ok);
//
//  return retval;
//}
