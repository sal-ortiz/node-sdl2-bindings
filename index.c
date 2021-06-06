
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


  // Platform Category
  napi_property_descriptor getplatformDesc = DECLARE_NAPI_METHOD("SDL_GetPlatform", NAPI_SDL_GetPlatform);
  napi_property_descriptor getcpucachelinesizeDesc = DECLARE_NAPI_METHOD("SDL_GetCPUCacheLineSize", NAPI_SDL_GetCPUCacheLineSize);
  napi_property_descriptor getcpucountDesc = DECLARE_NAPI_METHOD("SDL_GetCPUCount", NAPI_SDL_GetCPUCount);
  napi_property_descriptor getsystemramDesc = DECLARE_NAPI_METHOD("SDL_GetSystemRAM", NAPI_SDL_GetSystemRAM);

  napi_property_descriptor has3dnowDesc = DECLARE_NAPI_METHOD("SDL_Has3DNow", NAPI_SDL_Has3DNow);
  napi_property_descriptor hasaltivecDesc = DECLARE_NAPI_METHOD("SDL_HasAltiVec", NAPI_SDL_HasAltiVec);
  napi_property_descriptor hasavxDesc = DECLARE_NAPI_METHOD("SDL_HasAVX", NAPI_SDL_HasAVX);
  napi_property_descriptor hasavx2Desc = DECLARE_NAPI_METHOD("SDL_HasAVX2", NAPI_SDL_HasAVX2);
  napi_property_descriptor hasmmxDesc = DECLARE_NAPI_METHOD("SDL_HasMMX", NAPI_SDL_HasMMX);
  napi_property_descriptor hasrdtscDesc = DECLARE_NAPI_METHOD("SDL_HasRDTSC", NAPI_SDL_HasRDTSC);
  napi_property_descriptor hassseDesc = DECLARE_NAPI_METHOD("SDL_HasSSE", NAPI_SDL_HasSSE);
  napi_property_descriptor hassse2Desc = DECLARE_NAPI_METHOD("SDL_HasSSE2", NAPI_SDL_HasSSE2);
  napi_property_descriptor hassse3Desc = DECLARE_NAPI_METHOD("SDL_HasSSE3", NAPI_SDL_HasSSE3);
  napi_property_descriptor hassse41Desc = DECLARE_NAPI_METHOD("SDL_HasSSE41", NAPI_SDL_HasSSE41);
  napi_property_descriptor hassse42Desc = DECLARE_NAPI_METHOD("SDL_HasSSE42", NAPI_SDL_HasSSE42);

  napi_property_descriptor swap16Desc = DECLARE_NAPI_METHOD("SDL_Swap16", NAPI_SDL_Swap16);
  napi_property_descriptor swap32Desc = DECLARE_NAPI_METHOD("SDL_Swap32", NAPI_SDL_Swap32);
  napi_property_descriptor swap64Desc = DECLARE_NAPI_METHOD("SDL_Swap64", NAPI_SDL_Swap64);
  napi_property_descriptor swapbe16Desc = DECLARE_NAPI_METHOD("SDL_SwapBE16", NAPI_SDL_SwapBE16);
  napi_property_descriptor swapbe32Desc = DECLARE_NAPI_METHOD("SDL_SwapBE32", NAPI_SDL_SwapBE32);
  napi_property_descriptor swapbe64Desc = DECLARE_NAPI_METHOD("SDL_SwapBE64", NAPI_SDL_SwapBE64);
  napi_property_descriptor swapfloatDesc = DECLARE_NAPI_METHOD("SDL_SwapFloat", NAPI_SDL_SwapFloat);
  napi_property_descriptor swapfloatbeDesc = DECLARE_NAPI_METHOD("SDL_SwapFloatBE", NAPI_SDL_SwapFloatBE);
  napi_property_descriptor swapfloatleDesc = DECLARE_NAPI_METHOD("SDL_SwapFloatLE", NAPI_SDL_SwapFloatLE);
  napi_property_descriptor swaple16Desc = DECLARE_NAPI_METHOD("SDL_SwapLE16", NAPI_SDL_SwapLE16);
  napi_property_descriptor swaple32Desc = DECLARE_NAPI_METHOD("SDL_SwapLE32", NAPI_SDL_SwapLE32);
  napi_property_descriptor swaple64Desc = DECLARE_NAPI_METHOD("SDL_SwapLE64", NAPI_SDL_SwapLE64);

  napi_property_descriptor mostsignificantbitindex32Desc = DECLARE_NAPI_METHOD("SDL_MostSignificantBitIndex32", NAPI_SDL_MostSignificantBitIndex32);

  status = napi_define_properties(env, exports, 1, &getplatformDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &getcpucachelinesizeDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &getcpucountDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &getsystemramDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &has3dnowDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hasaltivecDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hasavxDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hasavx2Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hasmmxDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hasrdtscDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hassseDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hassse2Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hassse3Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hassse41Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &hassse42Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swap16Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swap32Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swap64Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swapbe16Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swapbe32Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swapbe64Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swapfloatDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swapfloatbeDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swapfloatleDesc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swaple16Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swaple32Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &swaple64Desc);
  assert(status == napi_ok);

  status = napi_define_properties(env, exports, 1, &mostsignificantbitindex32Desc);
  assert(status == napi_ok);


  // Power Management Category
  //napi_property_descriptor getpowerinfoDesc = DECLARE_NAPI_METHOD("SDL_GetPowerInfo", NAPI_SDL_GetPowerInfo);

  //status = napi_define_properties(env, exports, 1, &getpowerinfoDesc);
  //assert(status == napi_ok);


  return exports;
}


NAPI_MODULE(NODE_GYP_MODULE_NAME, Export)
