cmake_minimum_required(VERSION 3.15)

project(ImageTo3DConverter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем зависимости
find_package(Git REQUIRED)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/MeshProcessingLibrary")
    message(STATUS "Cloning MeshProcessingLibrary...")
    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone https://github.com/AlexanderOsharov/MeshProcessingLibrary.git ${CMAKE_BINARY_DIR}/MeshProcessingLibrary
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        RESULT_VARIABLE GIT_CLONE_RESULT
    )
    if(NOT GIT_CLONE_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to clone MeshProcessingLibrary")
    endif()
endif()

add_subdirectory(${CMAKE_BINARY_DIR}/MeshProcessingLibrary ${CMAKE_BINARY_DIR}/MeshProcessingLibrary-build)

# Добавляем свои исходные файлы
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_library(ImageTo3DConverter STATIC ${SOURCES} ${HEADERS})

target_include_directories(ImageTo3DConverter PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_BINARY_DIR}/MeshProcessingLibrary/include
)

target_link_libraries(ImageTo3DConverter PRIVATE MeshProcessingLibrary)

# Установка библиотеки
install(TARGETS ImageTo3DConverter
    EXPORT ImageTo3DConverterTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
install(EXPORT ImageTo3DConverterTargets DESTINATION cmake)