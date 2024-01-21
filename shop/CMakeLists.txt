cmake_minimum_required(VERSION 3.16)

project(shop)

set(SOURCES
    shop.cpp
)

set(HEADERS
    shop.hpp
)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
