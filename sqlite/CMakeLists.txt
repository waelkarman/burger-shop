cmake_minimum_required(VERSION 3.16)

project(sqlite3)

set(SOURCES
    sqlite3.c
    shell.c
)

set(HEADERS
    sqlite3.h
    sqlite3ext.h
)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)