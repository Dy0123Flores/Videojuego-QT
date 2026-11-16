
cmake_minimum_required(VERSION 3.16)

project(JuegoDemo VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.8 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appJuegoDemo
    main.cpp
    registropuntajes.h
    registropuntajes.cpp
)

qt_add_qml_module(appJuegoDemo
    URI JuegoDemo
    VERSION 1.0
    QML_FILES
        Main.qml
)

target_link_libraries(appJuegoDemo
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2
)

set_target_properties(appJuegoDemo PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

include(GNUInstallDirs)

install(TARGETS appJuegoDemo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
