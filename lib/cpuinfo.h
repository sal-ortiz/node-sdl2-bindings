
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>


static napi_value NAPI_SDL_GetCPUCacheLineSize(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  unsigned long int res = SDL_GetCPUCacheLineSize();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_GetCPUCount(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  unsigned long int res = SDL_GetCPUCount();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_GetSystemRAM(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  unsigned long int res = SDL_GetSystemRAM();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_Has3DNow(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_Has3DNow();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasAltiVec(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasAltiVec();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasAVX(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasAVX();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasAVX2(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasAVX2();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasMMX(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasMMX();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasRDTSC(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasRDTSC();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasSSE(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasSSE();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasSSE2(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasSSE2();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasSSE3(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasSSE3();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasSSE41(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasSSE41();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}

static napi_value NAPI_SDL_HasSSE42(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value retval;

  SDL_bool res = SDL_HasSSE42();

  status = napi_create_int32(env, res, &retval);
  assert(status == napi_ok);

  return retval;
}
