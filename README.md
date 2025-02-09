# ImageTo3DConverter

## Описание
Библиотека для конвертации 2D изображений в 3D-объекты. Поддерживает различные форматы входных изображений и выходных 3D-моделей.

## Установка
1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/AlexanderOsharov/ImageTo3DConverter.git
   ```
2. Скомпилируйте библиотеку
   ```bash
   cmake .
   make
   ```
## Использование
### С API
```C
void convert_image_to_3d(const char* input_filename, const char* output_filename, const char* output_format);
```
### Пример использования из Python
```Python
import ctypes

lib = ctypes.CDLL("./libImageTo3DConverter_SHARED.so")
lib.convert_image_to_3d(b"input.png", b"output.obj", b"obj")
```
### Пример использования из JavaScript (WebAssembly)
```JavaScript
fetch("ImageTo3DConverter.wasm")
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.instantiate(bytes))
    .then(results => {
        results.instance.exports.convert_image_to_3d(
            allocateString("input.png"),
            allocateString("output.obj"),
            allocateString("obj")
        );
    });
```

## Форматы
1. Вход: PNG, JPEG, BMP, SVG.
2. Выход: OBJ, STL, PLY.
