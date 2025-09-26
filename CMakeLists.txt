cmake_minimum_required(VERSION 4.0)
project(Server)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(NO_SSL)

add_executable(Server
        Source/CivetWeb/CivetServer.cpp
        Source/CivetWeb/civetweb.c
        Source/DictionarySearchHandler.cpp
        Source/ExitHandler.cpp
        Source/Program.cpp
        Source/sqlite3.c
        Source/WebpageBuilder.cpp
        Source/Include/WebpageBuilder.hpp
        Source/Include/HTTP.h
        Source/Include/Document.h)
