cmake_minimum_required(VERSION 4.3)
project(Gogenskyi_CUI LANGUAGES CXX)

add_library(Gogenskyi_CUI STATIC src/Console.cpp
        src/Widget/Widget.h
        src/Widget/TextMessage.cpp
        src/Widget/TextMessage.h)

target_compile_features(Gogenskyi_CUI PUBLIC cxx_std_26)

target_include_directories(Gogenskyi_CUI PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)