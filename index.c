
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>

#include "./lib/init.h"
#include "./lib/error.h"
#include "./lib/video.h"


#ifndef DECLARE_NAPI_METHOD

  #define DECLARE_NAPI_METHOD(name, func)       \
    { name, 0, func, 0, 0, 0, napi_default, 0 }

#endif


napi_value Export(napi_env env, napi_value exports) {
  napi_status status;

  // Init Category
  napi_property_descriptor initDesc = DECLARE_NAPI_METHOD("SDL_Init", NAPI_SDL_Init);
  napi_property_descriptor initsubsystemDesc = DECLARE_NAPI_METHOD("SDL_InitSubSystem", NAPI_SDL_Init);
  napi_property_descriptor quitDesc = DECLARE_NAPI_METHOD("SDL_Quit", NAPI_SDL_Quit);
  napi_property_descriptor quitsubsystemDesc = DECLARE_NAPI_METHOD("SDL_QuitSubSystem", NAPI_SDL_QuitSubSystem);
  //napi_property_descriptor setmainreadyDesc = DECLARE_NAPI_METHOD("SDL_SetMainReady", NAPI_SDL_SetMainReady);
  napi_property_descriptor wasinitDesc = DECLARE_NAPI_METHOD("SDL_WasInit", NAPI_SDL_WasInit);
  //napi_property_descriptor winrtrunappDesc = DECLARE_NAPI_METHOD("SDL_WinRTRunApp", NAPI_SDL_WinRTRunApp);

  status = napi_define_properties(env, exports, 1, &initDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &initsubsystemDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &quitDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &quitsubsystemDesc);
  assert(status == napi_ok);

  //status = napi_define_properties(env, exports, 1, &setmainreadyDesc);
  //assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &wasinitDesc);
  assert(status == napi_ok);

  //status = napi_define_properties(env, exports, 1, &winrtrunappDesc);
  //assert(status == napi_ok);


  // Error Category
  napi_property_descriptor clearerrorDesc = DECLARE_NAPI_METHOD("SDL_ClearError", NAPI_SDL_ClearError);
  napi_property_descriptor geterrorDesc = DECLARE_NAPI_METHOD("SDL_GetError", NAPI_SDL_GetError);
  napi_property_descriptor seterrorDesc = DECLARE_NAPI_METHOD("SDL_SetError", NAPI_SDL_SetError);

  status = napi_define_properties(env, exports, 1, &clearerrorDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &geterrorDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &seterrorDesc);
  assert(status == napi_ok);


  // Display and Window Management Category
  napi_property_descriptor createwindowDesc = DECLARE_NAPI_METHOD("SDL_CreateWindow", NAPI_SDL_CreateWindow);

  status = napi_define_properties(env, exports, 1, &createwindowDesc);
  assert(status == napi_ok);




  return exports;
}


NAPI_MODULE(NODE_GYP_MODULE_NAME, Export)
