cmake_minimum_required(VERSION 2.8.12)

project(test)

add_definitions(-std=c++14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(carla_opendrive ${PROJECT_SOURCE_DIR}/../carla_opendrive)

include_directories(${carla_opendrive}/include)

link_directories(${carla_opendrive}/lib)
link_directories(/usr/local/lib)

set(SOURCES_FILE
    OpenDrive.cpp
    main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES_FILE})

target_link_libraries(${PROJECT_NAME}
    carla_opendrive
    boost_filesystem
    )
