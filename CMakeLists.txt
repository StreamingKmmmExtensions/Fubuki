cmake_minimum_required(VERSION 4.0)
project(Server)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(NO_SSL)

add_executable(Server
        Source/CivetWeb/CivetServer.cpp
        Source/CivetWeb/civetweb.c
        Source/C++/DictionarySearchHandler.cpp
        Source/C++/ExitHandler.cpp
        Source/C++/Program.cpp
        Source/C++/sqlite3.c
        Source/C++/WebpageBuilder.cpp
        Source/Include/WebpageBuilder.hpp
        Source/Include/HTTP.h
        Source/Include/Document.h)
