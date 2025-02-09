#ifndef IMAGE_TO_3D_CONVERTER_CAPI_H
#define IMAGE_TO_3D_CONVERTER_CAPI_H

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define EMSCRIPTEN_KEEPALIVE __attribute__((used))
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern "C" EMSCRIPTEN_KEEPALIVE void exportToOBJ(const char* filename);
extern "C" EMSCRIPTEN_KEEPALIVE void exportToSTL(const char* filename);
extern "C" EMSCRIPTEN_KEEPALIVE void exportToPLY(const char* filename);

#endif // IMAGE_TO_3D_CONVERTER_CAPI_H