cmake_minimum_required(VERSION 3.19)

project(QtReStreamer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(HTTP_SUPPORT OFF)
set(WS_SERVER_SUPPORT OFF)
set(WS_CLIENT_SUPPORT OFF)
set(ONVIF_SUPPORT OFF)
set(QT_SERVER_SUPPORT ON)
add_subdirectory(WebRTSP)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS WebSockets)

qt_standard_project_setup()

qt_add_executable(QtReStreamer
    main.cpp
)

target_link_libraries(QtReStreamer
    PRIVATE
        Qt6::Core
        QtServer
)
