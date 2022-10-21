cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME HW1-TETRIS)

project(${PROJECT_NAME} VERSION 0.1)

add_executable(${PROJECT_NAME} src/main.cpp src/Tetromino/Tetro_J.cpp src/Tetromino/Tetromino.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/src/Tetromino
    ${CMAKE_SOURCE_DIR}/src/Enums
)

