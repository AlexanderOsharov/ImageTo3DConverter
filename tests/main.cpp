#include <iostream>
#include "ImageTo3DConverter.h"

int main() {
    try {
        ImageTo3DConverter::convert("input.png", "obj");
        std::cout << "Conversion completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}