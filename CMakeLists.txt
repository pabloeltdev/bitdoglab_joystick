cmake_minimum_required(VERSION 3.10)

project(bitdoglab_joystick VERSION 1.0 DESCRIPTION "Biblioteca que permite o fácil uso do joystick da placa BitDogLab")

add_library(bitdoglab_joystick src/joystick.c)

target_include_directories(bitdoglab_joystick
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(bitdoglab_joystick
    PRIVATE
        hardware_adc
    PUBLIC
        pico_stdlib
)