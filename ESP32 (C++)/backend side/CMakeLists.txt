cmake_minimum_required(VERSION 3.10)
project(backend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        httplib
        GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
        GIT_TAG v0.14.3
)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(httplib json)

add_executable(backend
        src/main.cpp
        src/server.cpp
        src/server.h
)

target_link_libraries(backend
        PRIVATE
        httplib::httplib
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(backend PRIVATE ws2_32)
endif()
