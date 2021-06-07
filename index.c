
#include <assert.h>

#include <node_api.h>
#include <SDL2/SDL.h>

#include "./lib/init.h"
#include "./lib/error.h"
#include "./lib/video.h"
#include "./lib/platform.h"
#include "./lib/cpuinfo.h"
#include "./lib/endian.h"
#include "./lib/bits.h"
#include "./lib/power.h"


#ifndef EXPORT_VALUE

  #define EXPORT_VALUE(targ, id, val)                             \
                                                                  \
    do {                                                          \
      napi_status status;                                         \
      napi_value napi_val;                                        \
                                                                  \
      status = napi_create_int32(env, val, &napi_val);            \
      assert(status == napi_ok);                                  \
                                                                  \
      status = napi_set_named_property(env, targ, id, napi_val);  \
      assert(status == napi_ok);                                  \
    } while (0)

#endif

#ifndef EXPORT_METHOD

  #define EXPORT_METHOD(targ, id, meth)                                   \
                                                                          \
    do {                                                                  \
      napi_status status;                                                 \
      napi_value napi_val;                                                \
                                                                          \
      status = napi_create_function(env, NULL, 0, meth, NULL, &napi_val); \
      assert(status == napi_ok);                                          \
                                                                          \
      status = napi_set_named_property(env, targ, id, napi_val);          \
      assert(status == napi_ok);                                          \
    } while (0)

#endif


napi_value Export(napi_env env, napi_value exports) {


  // Init Category
  EXPORT_VALUE(exports, "SDL_INIT_TIMER", SDL_INIT_TIMER);
  EXPORT_VALUE(exports, "SDL_INIT_AUDIO", SDL_INIT_AUDIO);
  EXPORT_VALUE(exports, "SDL_INIT_VIDEO", SDL_INIT_VIDEO);
  EXPORT_VALUE(exports, "SDL_INIT_JOYSTICK", SDL_INIT_JOYSTICK);
  EXPORT_VALUE(exports, "SDL_INIT_HAPTIC", SDL_INIT_HAPTIC);
  EXPORT_VALUE(exports, "SDL_INIT_GAMECONTROLLER", SDL_INIT_GAMECONTROLLER);
  EXPORT_VALUE(exports, "SDL_INIT_EVENTS", SDL_INIT_EVENTS);
  EXPORT_VALUE(exports, "SDL_INIT_EVERYTHING", SDL_INIT_EVERYTHING);
  EXPORT_VALUE(exports, "SDL_INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE);


  EXPORT_METHOD(exports, "SDL_Init", NAPI_SDL_Init);
  EXPORT_METHOD(exports, "SDL_InitSubSystem", NAPI_SDL_Init);
  EXPORT_METHOD(exports, "SDL_Quit", NAPI_SDL_Quit);
  EXPORT_METHOD(exports, "SDL_QuitSubSystem", NAPI_SDL_QuitSubSystem);
  //EXPORT_METHOD(exports, "SDL_SetMainReady", NAPI_SDL_SetMainReady);
  EXPORT_METHOD(exports, "SDL_WasInit", NAPI_SDL_WasInit);
  //EXPORT_METHOD(exports, "SDL_WinRTRunApp", NAPI_SDL_WinRTRunApp);

  // Error Category
  EXPORT_METHOD(exports, "SDL_ClearError", NAPI_SDL_ClearError);
  EXPORT_METHOD(exports, "SDL_GetError", NAPI_SDL_GetError);
  EXPORT_METHOD(exports, "SDL_SetError", NAPI_SDL_SetError);

  // Display and Window Management Category
  EXPORT_METHOD(exports, "SDL_CreateWindow", NAPI_SDL_CreateWindow);

  // Platform Category
  EXPORT_METHOD(exports, "SDL_GetPlatform", NAPI_SDL_GetPlatform);
  EXPORT_METHOD(exports, "SDL_GetCPUCacheLineSize", NAPI_SDL_GetCPUCacheLineSize);
  EXPORT_METHOD(exports, "SDL_GetCPUCount", NAPI_SDL_GetCPUCount);
  EXPORT_METHOD(exports, "SDL_GetSystemRAM", NAPI_SDL_GetSystemRAM);

  EXPORT_METHOD(exports, "SDL_Has3DNow", NAPI_SDL_Has3DNow);
  EXPORT_METHOD(exports, "SDL_HasAltiVec", NAPI_SDL_HasAltiVec);
  EXPORT_METHOD(exports, "SDL_HasAVX", NAPI_SDL_HasAVX);
  EXPORT_METHOD(exports, "SDL_HasAVX2", NAPI_SDL_HasAVX2);
  EXPORT_METHOD(exports, "SDL_HasMMX", NAPI_SDL_HasMMX);
  EXPORT_METHOD(exports, "SDL_HasRDTSC", NAPI_SDL_HasRDTSC);
  EXPORT_METHOD(exports, "SDL_HasSSE", NAPI_SDL_HasSSE);
  EXPORT_METHOD(exports, "SDL_HasSSE2", NAPI_SDL_HasSSE2);
  EXPORT_METHOD(exports, "SDL_HasSSE3", NAPI_SDL_HasSSE3);
  EXPORT_METHOD(exports, "SDL_HasSSE41", NAPI_SDL_HasSSE41);
  EXPORT_METHOD(exports, "SDL_HasSSE42", NAPI_SDL_HasSSE42);

  EXPORT_METHOD(exports, "SDL_Swap16", NAPI_SDL_Swap16);
  EXPORT_METHOD(exports, "SDL_Swap32", NAPI_SDL_Swap32);
  EXPORT_METHOD(exports, "SDL_Swap64", NAPI_SDL_Swap64);
  EXPORT_METHOD(exports, "SDL_SwapBE16", NAPI_SDL_SwapBE16);
  EXPORT_METHOD(exports, "SDL_SwapBE32", NAPI_SDL_SwapBE32);
  EXPORT_METHOD(exports, "SDL_SwapBE64", NAPI_SDL_SwapBE64);
  EXPORT_METHOD(exports, "SDL_SwapFloat", NAPI_SDL_SwapFloat);
  EXPORT_METHOD(exports, "SDL_SwapFloatBE", NAPI_SDL_SwapFloatBE);
  EXPORT_METHOD(exports, "SDL_SwapFloatLE", NAPI_SDL_SwapFloatLE);
  EXPORT_METHOD(exports, "SDL_SwapLE16", NAPI_SDL_SwapLE16);
  EXPORT_METHOD(exports, "SDL_SwapLE32", NAPI_SDL_SwapLE32);
  EXPORT_METHOD(exports, "SDL_SwapLE64", NAPI_SDL_SwapLE64);

  EXPORT_METHOD(exports, "SDL_MostSignificantBitIndex32", NAPI_SDL_MostSignificantBitIndex32);

  // Power Management Category
  //EXPORT_METHOD(exports, "SDL_GetPowerInfo", NAPI_SDL_GetPowerInfo);


  return exports;
}


NAPI_MODULE(NODE_GYP_MODULE_NAME, Export)
