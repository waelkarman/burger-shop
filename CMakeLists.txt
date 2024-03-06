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
        "media/book.png"
        "media/a1.jpg"
        "media/a2.jpg"
        "media/a3.jpg"
        "media/a4.jpg"
        "media/a5.jpg"
        "media/a6.jpg"
        "media/a7.jpg"
        "media/a8.jpg"
        "media/a9.jpg"
        "media/a10.jpg"
        "media/a11.jpg"
        "media/a12.jpg"
        "media/a13.jpg"
)

#install(TARGETS library DESTINATION bin)
