
const SDL2 = require('bindings')('napi_sdl2.node')

const Constants = require('./lib/constants.js');


if (SDL2.SDL_Init(Constants.SDL_INIT_EVERYTHING) != 0) {
  let err = SDL2.SDL_GetError();

  console.log("error initializing SDL:", err);

} else {
  console.log("SDL2 Initialized");

  let win = SDL2.SDL_CreateWindow("TEST", 0, 0, 800, 500, 0);


  SDL2.SDL_Quit();
}

