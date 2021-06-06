{
  "targets": [
    {
      "target_name": "napi_sdl2",
      "sources": [
        "index.c"
      ],

      "cflags": [
        "-I/usr/include/SDL2",
        "-D_REENTRANT"
      ],

      "include_dirs": [
        "/usr/include/SDL2"
      ],

      "libraries": [
        "-lSDL2"
      ]

    }

  ]

}
