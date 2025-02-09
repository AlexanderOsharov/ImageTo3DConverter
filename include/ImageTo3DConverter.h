#ifndef IMAGETO3DCONVERTER_H
#define IMAGETO3DCONVERTER_H

#include "HeightMap.h"
#include "Mesh.h"
#include <string>

class ImageTo3DConverter {
public:
    static Mesh convert(const std::string& imageFilename, const std::string& outputFormat);
};

#endif // IMAGETO3DCONVERTER_H