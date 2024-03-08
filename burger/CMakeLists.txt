cmake_minimum_required(VERSION 3.16)

project(burger)

set(SOURCES
    burger.cpp
)

set(HEADERS
    burger.hpp
)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
