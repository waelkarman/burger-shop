cmake_minimum_required(VERSION 3.16)

project(dbhelper)

set(SOURCES
    dbhelper.cpp
)

set(HEADERS
    dbhelper.hpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES}
    dberrors.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} 
    sqlite3
    burger
)
