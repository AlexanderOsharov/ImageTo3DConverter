#include "ImageTo3DConverter_CAPI.h"
#include "ImageTo3DConverter.h"
#include <stdexcept>

extern "C" {

void convert_image_to_3d(const char* input_filename, const char* output_filename, const char* output_format) {
    try {
        // Конвертация изображения в 3D-модель
        Mesh mesh = ImageTo3DConverter::convert(input_filename, output_format);

        // Экспорт в выбранный формат
        if (std::string(output_format) == "obj") {
            OBJExporter exporter;
            exporter.exportToFile(mesh, output_filename);
        } else if (std::string(output_format) == "stl") {
            STLExporter exporter;
            exporter.exportToFile(mesh, output_filename);
        } else if (std::string(output_format) == "ply") {
            PLYExporter exporter;
            exporter.exportToFile(mesh, output_filename);
        } else {
            throw std::runtime_error("Unsupported output format");
        }
    } catch (const std::exception& e) {
        // Вывод ошибки в стандартный поток
        fprintf(stderr, "Error: %s\n", e.what());
    }
}

}