cmake_minimum_required(VERSION 3.13)

include(/home/piobr/projects_2026/embedded/pico-playground/deps/pico-sdk/external/pico_sdk_import.cmake)


project(blink C CXX)

pico_sdk_init()

add_executable(blink
    main.c
)

target_link_libraries(blink pico_stdlib)

pico_add_extra_outputs(blink)

