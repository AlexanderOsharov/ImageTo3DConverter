#ifndef IMAGETO3DCONVERTER_CAPI_H
#define IMAGETO3DCONVERTER_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif

// Функция для конвертации изображения в 3D-объект
void convert_image_to_3d(const char* input_filename, const char* output_filename, const char* output_format);

#ifdef __cplusplus
}
#endif

#endif // IMAGETO3DCONVERTER_CAPI_H