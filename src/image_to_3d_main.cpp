#include "ImageTo3DConverter_CAPI.h"
#include <emscripten.h>

extern "C" {

// Точка входа для WebAssembly
EMSCRIPTEN_KEEPALIVE
void emscripten_entry(const char* input_filename, const char* output_filename, const char* output_format) {
    convert_image_to_3d(input_filename, output_filename, output_format);
}

}