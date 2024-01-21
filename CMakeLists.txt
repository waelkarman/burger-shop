cmake_minimum_required(VERSION 3.16)

project(library)

set(SOURCES
    main.cpp
    shop.cpp
    dbhelper.cpp
)

set(HEADERS
    shop.hpp
    dbhelper.hpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
add_subdirectory(sqlite)
add_subdirectory(book)
add_subdirectory(dbhelper)
add_subdirectory(shop)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(library
    book
    sqlite3
    dbhelper
    shop
)

#install(TARGETS library DESTINATION bin)