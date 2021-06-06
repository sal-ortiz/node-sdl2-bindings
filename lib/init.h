
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static napi_value NAPI_SDL_Init(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int flags;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &flags);
  assert(status == napi_ok);

  unsigned long int res = SDL_Init(flags);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static void NAPI_SDL_Quit(napi_env env, napi_callback_info info) {
  SDL_Quit();
}

static napi_value NAPI_SDL_QuitSubSystem(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int flags;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &flags);
  assert(status == napi_ok);

  SDL_QuitSubSystem(flags);

}

//static void NAPI_SDL_SetMainReady(napi_env env, napi_callback_info info) {
//  SDL_SetMainReady();
//}

static napi_value NAPI_SDL_WasInit(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int flags;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &flags);
  assert(status == napi_ok);

  unsigned long int res = SDL_WasInit(flags);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

//static napi_value NAPI_SDL_WinRTRunApp(napi_env env, napi_callback_info info) {
//  napi_status status;
//
//  size_t argc = 2;
//  napi_value args[2];
//
//  void* mainFunc;
//  unsigned long int reserved;
//
//  napi_value retval;
//
//  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
//  assert(status == napi_ok);
//
//  status = napi_get_value_external(env, args[0], &mainFunc);
//  assert(status == napi_ok);
//
//  status = napi_get_value_int32(env, args[1], &reserved);
//  assert(status == napi_ok);
//
//  unsigned long int res = SDL_WinRTRunApp(mainFunc);
//
//  status = napi_create_int32(env, res, &retval);
//  assert(status == napi_ok);
//
//  return retval;
//}


