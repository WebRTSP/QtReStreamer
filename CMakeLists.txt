cmake_minimum_required(VERSION 3.19)

project(QtReStreamer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(HTTP_SUPPORT OFF CACHE BOOL "HTTP server is not used" FORCE)
set(WS_SERVER_SUPPORT  OFF CACHE BOOL "libwebsocket based server is not used" FORCE)
set(WS_CLIENT_SUPPORT OFF CACHE BOOL "libwebsocket based client is not used" FORCE)
set(ONVIF_SUPPORT OFF CACHE BOOL "ONVIF not used" FORCE)
set(QT_SERVER_SUPPORT ON CACHE BOOL "Qt server is used" FORCE)
set(H265_SUPPORT ON CACHE BOOL "h265 can be required" FORCE)
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
