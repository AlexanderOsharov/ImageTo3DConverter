#include "ImageTo3DConverter_CAPI.h"
#include "OBJExporter.h"
#include "STLExporter.h"
#include "PLYExporter.h"

extern "C" EMSCRIPTEN_KEEPALIVE void exportToOBJ(const char* filename) {
    OBJExporter exporter;
    exporter.exportToFile("output.obj");
}

extern "C" EMSCRIPTEN_KEEPALIVE void exportToSTL(const char* filename) {
    STLExporter exporter;
    exporter.exportToFile("output.stl");
}

extern "C" EMSCRIPTEN_KEEPALIVE void exportToPLY(const char* filename) {
    PLYExporter exporter;
    exporter.exportToFile("output.ply");
}