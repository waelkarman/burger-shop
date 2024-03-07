cmake_minimum_required(VERSION 3.16)

project(book-shop)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Sql)

set(SOURCES
    main.qrc
    main.cpp
)

set(HEADERS)

qt_add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

add_subdirectory(sqlite)
add_subdirectory(book)
add_subdirectory(dbhelper)
add_subdirectory(shop)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    book
    sqlite3
    dbhelper
    shop
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Sql
)

#install(TARGETS library DESTINATION bin)
