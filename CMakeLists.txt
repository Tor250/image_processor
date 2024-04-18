cmake_minimum_required(VERSION 3.16)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wextra -Wall")

add_executable(image_processor
    src/data/image.cpp
    src/data/pixel.cpp

    src/filters/grayscale.cpp
    src/filters/crop.cpp
    src/filters/negative.cpp
    src/filters/sharpening.cpp
    src/filters/edge_detection.cpp
    src/filters/blur.cpp
    src/filters/my_filter.cpp

    src/io/binary_reader.cpp
    src/io/binary_writer.cpp
    src/io/bmp.cpp
    image_processor.cpp
)

target_include_directories(image_processor PUBLIC include)
