cmake_minimum_required(VERSION 2.8.12)

project(carla_opendrive)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    message(STATUS "current platform: FreeBSD")
ELSE ()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_definitions(-std=c++14)

#PROJECT_SOURCE_DIR : current dirctory including the CMakeList.txt file
set(carla_opendrive_source_path "${PROJECT_SOURCE_DIR}/src/")
set(carla_opendrive_third_party "${carla_opendrive_source_path}/third-party")

#message("[cmake debug] carla_opendrive_source_path: " ${carla_opendrive_source_path})

#find_package(Qt5Core)

include_directories(${carla_opendrive_source_path})
include_directories(${carla_opendrive_third_party})

#Add sources third-party
file(GLOB libopendrive_moodycamel_sources
    "${carla_opendrive_third_party}/moodycamel/*.h")
set(libopendrive_sources "${libopendrive_sources};${libopendrive_moodycamel_sources}")

file(GLOB libopendrive_pugixml_sources
    "${carla_opendrive_third_party}/pugixml/*.cpp"
    "${carla_opendrive_third_party}/pugixml/*.hpp"
    "${carla_opendrive_third_party}/pugixml/*.h")
set(libopendrive_sources "${libopendrive_sources};${libopendrive_pugixml_sources}")

#Add sources opendrive
file(GLOB sources_code
    "${carla_opendrive_source_path}/carla/*.cpp"
    "${carla_opendrive_source_path}/carla/*.h"
    )
set(libopendrive_sources "${libopendrive_sources};${sources_code}")

file(GLOB opendrive_sources
    "${carla_opendrive_source_path}/carla/opendrive/*.cpp"
    "${carla_opendrive_source_path}/carla/opendrive/*.h"
    "${carla_opendrive_source_path}/carla/opendrive/parser/*.cpp"
    "${carla_opendrive_source_path}/carla/opendrive/parser/*.h"
    #"${carla_opendrive_source_path}/carla/opendrive/parser/pugixml/*.cpp"
    #"${carla_opendrive_source_path}/carla/opendrive/parser/pugixml/*.hpp"
    )
#message("[cmake debug] opendrive_sources: " ${opendrive_sources})
set(libopendrive_sources "${libopendrive_sources};${opendrive_sources}")
#message("[cmake debug] libopendrive_sources:" ${libopendrive_sources})

#Add sources road
file(GLOB road_sources
    "${carla_opendrive_source_path}/carla/road/*.cpp"
    "${carla_opendrive_source_path}/carla/road/*.h"
    "${carla_opendrive_source_path}/carla/road/element/*.cpp"
    "${carla_opendrive_source_path}/carla/road/element/*.h"
    "${carla_opendrive_source_path}/carla/road/element/cephes/*.cpp"
    "${carla_opendrive_source_path}/carla/road/element/cephes/*.h"
    "${carla_opendrive_source_path}/carla/road/general/*.h"
    "${carla_opendrive_source_path}/carla/road/object/*.h"
    "${carla_opendrive_source_path}/carla/road/signal/*.h"
    )
#message("[cmake debug] road_sources: " ${road_sources})
set(libopendrive_sources "${libopendrive_sources};${road_sources}")
#message("[cmake debug] libopendrive_sources:" ${libopendrive_sources})

#Add sources geom
file(GLOB geom_sources
    "${carla_opendrive_source_path}/carla/geom/*.cpp"
    "${carla_opendrive_source_path}/carla/geom/*.h"
    )
#message("[cmake debug] road_sources: " ${road_sources})
set(libopendrive_sources "${libopendrive_sources};${geom_sources}")
#message("[cmake debug] libopendrive_sources:" ${libopendrive_sources})

#install header
file(GLOB carla_header
    "${carla_opendrive_source_path}/carla/*.h"
    )
file(GLOB opendrive_header
    "${carla_opendrive_source_path}/carla/opendrive/*.h"
    )
file(GLOB opendrive_parser_header
    "${carla_opendrive_source_path}/carla/opendrive/parser/*.h"
    )

#message("[cmake debug] opendrive_header:" ${opendrive_header})
#message("[cmake debug] opendrive_parser_header:" ${opendrive_parser_header})
#message("[cmake debug] opendrive_parser_pugixml_header:" ${opendrive_parser_pugixml_header})

install(FILES ${carla_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla)
install(FILES ${opendrive_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/opendrive)
install(FILES ${opendrive_parser_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/opendrive/parser)
install(FILES ${opendrive_parser_pugixml_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/opendrive/parser/pugixml)

file(GLOB opendrive_geom_header
    "${carla_opendrive_source_path}/carla/geom/*.h"
    )

install(FILES ${opendrive_geom_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/geom)

file(GLOB road_header
    "${carla_opendrive_source_path}/carla/road/*.h"
    )
file(GLOB road_element_header
    "${carla_opendrive_source_path}/carla/road/element/*.h"
    )
file(GLOB road_element_cephes_header
    "${carla_opendrive_source_path}/carla/road/element/cephes/*.h"
    )
file(GLOB road_general_header
    "${carla_opendrive_source_path}/carla/road/general/*.h"
    )
file(GLOB road_object_header
    "${carla_opendrive_source_path}/carla/road/object/*.h"
    )
file(GLOB road_signal_header
    "${carla_opendrive_source_path}/carla/road/signal/*.h"
    )

#message("[cmake debug] road_header:" ${road_header})
#message("[cmake debug] road_element_header:" ${road_element_header})
#message("[cmake debug] road_element_cephes_header:" ${road_element_cephes_header})
#message("[cmake debug] road_general_header:" ${road_general_header})
#message("[cmake debug] road_object_header:" ${road_object_header})
#message("[cmake debug] road_signal_header:" ${road_signal_header})

install(FILES ${road_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/road)
install(FILES ${road_element_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/road/element)
install(FILES ${road_element_cephes_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/road/element/cephes)
install(FILES ${road_general_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/road/general)
install(FILES ${road_object_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/road/object)
install(FILES ${road_signal_header} DESTINATION
    ${carla_opendrive_source_path}/../include/carla/road/signal)

#build shared library
add_library(carla_opendrive SHARED ${libopendrive_sources})

install(TARGETS carla_opendrive DESTINATION ${carla_opendrive_source_path}/../lib)
