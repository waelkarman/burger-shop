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
    main.cpp
)

set(HEADERS
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}

)
add_subdirectory(sqlite)
add_subdirectory(book)
add_subdirectory(dbhelper)
add_subdirectory(shop)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    book
    sqlite3
    dbhelper
    shop
    GL 
    GLU
    glut
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Sql
)

qt_add_resources(${PROJECT_NAME}
    PREFIX
        "/"
    FILES
        "main.qml"
        "book.png"
        "a1.jpg"
        "a2.jpg"
        "a3.jpg"
        "a4.jpg"
        "a5.jpg"
        "a6.jpg"
        "a7.jpg"
        "a8.jpg"
        "a9.jpg"
        "a10.jpg"
        "a11.jpg"
        "a12.jpg"
        "a13.jpg"
)

#install(TARGETS library DESTINATION bin)
