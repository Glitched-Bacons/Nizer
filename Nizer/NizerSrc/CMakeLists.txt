cmake_minimum_required(VERSION 3.5)

project(NizerSrc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

FILE(GLOB_RECURSE UIs *.ui)
qt_wrap_ui(UI_HEADERS ${UIs})

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        resources/resources.qrc

        # Views
        View/ViewStack.cpp
        View/ViewStack.h
        View/View.h
        View/View.cpp
        #View/AlgorithmSelectionView.h
        #View/AlgorithmSelectionView.cpp
        View/WelcomeView.h
        View/WelcomeView.cpp
        View/WelcomeView.ui
        View/HomepageView.h
        View/HomepageView.cpp
        View/HomepageView.ui
        View/Misc/AboutUs.h
        View/Misc/AboutUs.cpp
        View/Misc/AboutUs.ui
        View/Misc/FlowLayout.h
        View/Misc/FlowLayout.cpp
        View/Misc/FlowWidget.h
        View/Misc/FlowWidget.cpp
        #View/ImageView.h
        #View/ImageView.cpp

        # Hash algorithm
        #HashAlgorithm/HashAlgorithm.h
        #HashAlgorithm/HashAlgorithm.cpp
        #HashAlgorithm/PHash.h
        #HashAlgorithm/PHash.cpp
        #HashAlgorithm/DHash.h
        #HashAlgorithm/DHash.cpp
        #HashAlgorithm/AHash.h
        #HashAlgorithm/AHash.cpp
        #HashAlgorithm/Hash.h
        #HashAlgorithm/Hash.cpp

        # Tiles
        Tile/Tile.h
        Tile/Tile.cpp
        Tile/ClusterTile.h
        Tile/ClusterTile.cpp
        Tile/ClusterTile.ui
        Tile/ImageTile.h
        Tile/ImageTile.cpp
        Tile/ImageTile.ui
)

add_library(NizerSrc SHARED
    ${UI_HEADERS}
    ${PROJECT_SOURCES}
)

target_link_libraries(NizerSrc PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(NizerSrc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

target_compile_definitions(NizerSrc PRIVATE NIZERSRC_LIBRARY)

# PROGRAM
set(SOURCES main.cpp)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(NizerApp
        ${SOURCES}
    )
else()
    if(ANDROID)
        add_library(NizerApp SHARED
            ${SOURCES}
        )
    else()
        add_executable(NizerApp
          ${SOURCES}
        )
    endif()
endif()

target_link_libraries(NizerApp PRIVATE NizerSrc)

