
#include <stdint.h>
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static napi_value NAPI_SDL_Swap16(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned int res = SDL_Swap16(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_Swap32(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned long int res = SDL_Swap32(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_Swap64(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  int64_t input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int64(env, args[0], &input);
  assert(status == napi_ok);

  int64_t res = SDL_Swap64(input);

  status = napi_create_int64(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapBE16(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned int res = SDL_SwapBE16(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapBE32(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned long int res = SDL_SwapBE32(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapBE64(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  int64_t input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int64(env, args[0], &input);
  assert(status == napi_ok);

  int64_t res = SDL_SwapBE64(input);

  status = napi_create_int64(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapFloat(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  double input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_double(env, args[0], &input);
  assert(status == napi_ok);

  double res = SDL_SwapFloat(input);

  status = napi_create_double(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapFloatBE(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  double input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_double(env, args[0], &input);
  assert(status == napi_ok);

  double res = SDL_SwapFloatBE(input);

  status = napi_create_double(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapFloatLE(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  double input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_double(env, args[0], &input);
  assert(status == napi_ok);

  double res = SDL_SwapFloatLE(input);

  status = napi_create_double(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapLE16(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned int res = SDL_SwapLE16(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapLE32(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  unsigned long int input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int32(env, args[0], &input);
  assert(status == napi_ok);

  unsigned long int res = SDL_SwapLE32(input);

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_SwapLE64(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  int64_t input;

  napi_value retval;

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  status = napi_get_value_int64(env, args[0], &input);
  assert(status == napi_ok);

  int64_t res = SDL_Swap64LE(input);

  status = napi_create_int64(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}
