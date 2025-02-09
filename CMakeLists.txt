cmake_minimum_required(VERSION 3.10)
project(ImageTo3DConverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Подключение HeightMapGenerator и MeshProcessingLibrary
include(FetchContent)
FetchContent_Declare(
    HeightMapGenerator
    GIT_REPOSITORY https://github.com/AlexanderOsharov/HeightMapGenerator.git
    GIT_TAG main
)
FetchContent_MakeAvailable(HeightMapGenerator)

FetchContent_Declare(
    MeshProcessingLibrary
    GIT_REPOSITORY https://github.com/AlexanderOsharov/MeshProcessingLibrary.git
    GIT_TAG main
)
FetchContent_MakeAvailable(MeshProcessingLibrary)

# Создание библиотеки
add_library(ImageTo3DConverter STATIC
    src/ImageTo3DConverter.cpp
)

# Подключение заголовочных файлов
target_include_directories(ImageTo3DConverter PUBLIC include)
target_include_directories(ImageTo3DConverter PRIVATE 
    ${HeightMapGenerator_SOURCE_DIR}/include
    ${MeshProcessingLibrary_SOURCE_DIR}/include
)

# Связывание с зависимостями
target_link_libraries(ImageTo3DConverter PRIVATE HeightMapGenerator MeshProcessingLibrary)

# Тестирование
add_executable(ImageTo3DConverterTest tests/main.cpp)
target_link_libraries(ImageTo3DConverterTest PRIVATE ImageTo3DConverter)



# Добавление C-интерфейса
add_library(ImageTo3DConverter_CAPI STATIC src/ImageTo3DConverter_CAPI.cpp)

# Подключение заголовочных файлов
target_include_directories(ImageTo3DConverter_CAPI PUBLIC include)
target_include_directories(ImageTo3DConverter_CAPI PRIVATE 
    ${HeightMapGenerator_SOURCE_DIR}/include
    ${MeshProcessingLibrary_SOURCE_DIR}/include
)

# Связывание с зависимостями
target_link_libraries(ImageTo3DConverter_CAPI PRIVATE HeightMapGenerator MeshProcessingLibrary)

# Создание библиотеки
add_library(ImageTo3DConverter_SHARED SHARED $<TARGET_OBJECTS:ImageTo3DConverter_CAPI>)
set_target_properties(ImageTo3DConverter_SHARED PROPERTIES POSITION_INDEPENDENT_CODE ON)