cmake_minimum_required(VERSION 3.5)

enable_testing()
project(Nizer VERSION 0.1 LANGUAGES CXX)

 
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

add_subdirectory(NizerSrc)
add_subdirectory(NizerTests)
