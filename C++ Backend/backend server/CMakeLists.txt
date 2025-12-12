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

include_directories(include)

add_executable(backend
        src/main.cpp
        src/server.cpp
        include/server.h
        src/Rooms/room1.cpp
        include/room1.h
        src/Rooms/room2.cpp
        include/room2.h
        src/Rooms/garage.cpp
        include/garage.h
        src/Rooms/reception.cpp
        include/reception.h
        src/Rooms/outerLed.cpp
        include/outerLed.h
        src/Modes/homeAway.cpp
        include/homeAway.h
        src/Modes/bedTimeMode.cpp
        include/bedTimeMode.h
        src/Modes/EmergencyMode.cpp
        include/EmergencyMode.h
        src/dataModel.cpp
        src/utilities.cpp
        include/utilities.h
        src/flameAlarm.cpp
        include/flameAlarm.h
        src/alarmManager.cpp
        include/alarmManager.h
)

target_link_libraries(backend
        PRIVATE
        httplib::httplib
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(backend PRIVATE ws2_32)
endif()
