cmake_minimum_required(VERSION 3.16)

project(library)

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
        "ContactModel.qml"
)

#install(TARGETS library DESTINATION bin)
