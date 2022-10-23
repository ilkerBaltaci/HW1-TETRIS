cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME HW1-TETRIS)

project(${PROJECT_NAME} VERSION 0.1)

add_executable(${PROJECT_NAME}
    src/main.cpp 
    src/ProgramManager.cpp 
    src/Tetromino/Tetro_J.cpp
    src/Tetromino/Tetro_I.cpp
    src/Tetromino/Tetro_O.cpp
    src/Tetromino/Tetro_T.cpp
    src/Tetromino/Tetro_L.cpp
    src/Tetromino/Tetro_S.cpp
    src/Tetromino/Tetro_Z.cpp
    src/Tetromino/Tetromino.cpp
    src/Tetromino/TetrominoFactory.cpp
    src/Utils/Conversions.cpp
    src/Utils/Coordinate.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/Tetromino
    ${CMAKE_SOURCE_DIR}/src/Enums
    ${CMAKE_SOURCE_DIR}/src/Utils
    /usr/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ncurses
)
