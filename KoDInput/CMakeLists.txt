cmake_minimum_required(VERSION 3.16)

project(KoDInput)

find_package(Qt6 REQUIRED COMPONENTS Core)

set(SOURCES
    KoDInput.cpp
)

set(HEADERS
    KoDInput.hpp
)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    Qt6::Core
)
