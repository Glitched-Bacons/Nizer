cmake_minimum_required(VERSION 3.5)

project(NizerTest LANGUAGES CXX)

include_directories(../NizerSrc)

find_package(QT NAMES Qt5 Qt6 COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

set(UT_Sources
    SampleQtTest.cpp
)

set(UI_Sources
    #put something here
)

# Download and unpack googletest at configure time
configure_file("CMakeLists.txt.in" "${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt")
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
)

# The gtest/gmock targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we
# have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include"
    )
endif()


add_executable(NizerTest 
    main.cpp
    QTestCase.h
    QTestCase.cpp
    UnitTest/${UT_Sources}
    UiTests/${UI_Sources}
)

target_link_libraries(NizerTest PRIVATE Qt${QT_VERSION_MAJOR}::Test NizerSrc)
target_link_libraries(NizerTest PRIVATE gtest gtest_main)
target_link_libraries(NizerTest PRIVATE gmock gmock_main)
