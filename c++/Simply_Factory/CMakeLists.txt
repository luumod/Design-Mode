﻿cmake_minimum_required(VERSION 3.14)

project(Simply_Factory LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Simply_Factory
  main.cpp
)
target_link_libraries(Simply_Factory Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS Simply_Factory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include_directories("F:\\Tools\\vld\\Visual Leak Detector\\include")
link_directories("F:\\Tools\\vld\\Visual Leak Detector\\lib\\Win64")
