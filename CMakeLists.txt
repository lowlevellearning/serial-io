cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

project(hello_serial C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()


add_executable(hello_serial
        hello_serial.c
        )

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(hello_serial pico_stdlib pico_bootrom)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(hello_serial)
