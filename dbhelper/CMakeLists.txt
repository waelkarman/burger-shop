cmake_minimum_required(VERSION 3.16)

project(dbhelper)

set(SOURCES
    dbhelper.cpp
)

set(HEADERS
    dbhelper.hpp
)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
