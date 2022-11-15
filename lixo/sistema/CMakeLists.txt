cmake_minimum_required(VERSION 3.14)

project(sistema LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(sistema SHARED
  sistema_global.h
  sistema.cpp
  sistema.h
)
add_library(atendente SHARED
  atendente.h
  atendente.cpp
)

target_link_libraries(sistema PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(sistema PRIVATE SISTEMA_LIBRARY)
