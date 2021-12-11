cmake_minimum_required(VERSION 3.5)

project(Nizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        # Views
        View/ViewStack.cpp
        View/ViewStack.h
        View/View.h
        View/View.cpp
        View/AlgorithmSelectionView.h
        View/AlgorithmSelectionView.cpp
        View/WelcomeView.h
        View/WelcomeView.cpp
        View/WelcomeViewUI.ui
        View/HomepageView.h
        View/HomepageView.cpp
        View/ImageView.h
        View/ImageView.cpp

        # Hash algorithm
        HashAlgorithm/HashAlgorithm.h
        HashAlgorithm/HashAlgorithm.cpp
        HashAlgorithm/PHash.h
        HashAlgorithm/PHash.cpp
        HashAlgorithm/DHash.h
        HashAlgorithm/DHash.cpp
        HashAlgorithm/AHash.h
        HashAlgorithm/AHash.cpp
        HashAlgorithm/Hash.h
        HashAlgorithm/Hash.cpp

        # Tiles
        Tile/Tile.h
        Tile/Tile.cpp
        Tile/ClusterTile.h
        Tile/ClusterTile.cpp
        Tile/ImageTile.h
        Tile/ImageTile.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Nizer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Nizer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Nizer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Nizer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Nizer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Nizer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Nizer)
endif()
