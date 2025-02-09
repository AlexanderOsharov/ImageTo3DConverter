#include "ImageTo3DConverter.h"
#include "HeightMapGenerator.h"
#include "HeightMapToMeshConverter.h"
#include "ImageLoaderFactory.h"

Mesh ImageTo3DConverter::convert(const std::string& imageFilename, const std::string& outputFormat) {
    // Загрузка изображения
    std::string extension = imageFilename.substr(imageFilename.find_last_of(".") + 1);
    IImageLoader* loader = ImageLoaderFactory::createLoader(extension);
    if (!loader) {
        throw std::runtime_error("Unsupported image format");
    }

    int width, height;
    std::vector<std::vector<int>> pixels;
    if (!loader->load(imageFilename, width, height, pixels)) {
        throw std::runtime_error("Failed to load image");
    }

    delete loader;

    // Конвертация в градации серого
    GrayscaleProcessor processor;
    Image image;
    image.setPixels(pixels);
    processor.process(image);

    // Генерация карты высот
    HeightMap heightMap(width, height);
    heightMap.setData(image.getPixels());

    // Преобразование в 3D-модель
    Mesh mesh = HeightMapToMeshConverter::convert(heightMap);

    // Экспорт в выбранный формат
    if (outputFormat == "obj") {
        OBJExporter exporter;
        exporter.exportToFile(mesh, "output.obj");
    } else if (outputFormat == "stl") {
        STLExporter exporter;
        exporter.exportToFile(mesh, "output.stl");
    } else if (outputFormat == "ply") {
        PLYExporter exporter;
        exporter.exportToFile(mesh, "output.ply");
    } else {
        throw std::runtime_error("Unsupported output format");
    }

    return mesh;
}