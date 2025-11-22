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
        src/Rooms/room1.cpp
        src/Rooms/room1.h
        src/Rooms/room2.cpp
        src/Rooms/room2.h
        src/Rooms/garage.cpp
        src/Rooms/garage.h
        src/Rooms/reception.cpp
        src/Rooms/reception.h
        src/Rooms/outerLed.cpp
        src/Rooms/outerLed.h
        src/Modes/homeAway.cpp
        src/Modes/homeAway.h
        src/Modes/bedTimeMode.cpp
        src/Modes/bedTimeMode.h
        src/Modes/EmergencyMode.cpp
        src/Modes/EmergencyMode.h
        src/dataModel.cpp
        src/utilities.cpp
        src/utilities.h
        src/flameAlarm.cpp
        src/flameAlarm.h
        src/Doors/mainDoor.cpp
        src/Doors/mainDoor.h
        src/Doors/garageDoor.cpp
        src/Doors/garageDoor.h
        src/Modes/managerMode.cpp
        src/Modes/managerMode.h

)

target_link_libraries(backend
        PRIVATE
        httplib::httplib
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(backend PRIVATE ws2_32)
endif()
