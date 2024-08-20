cmake_minimum_required( VERSION 3.15 )
project( freertos_example )

# Compiler flags.
add_compile_options( -Wall -Wextra -Wpedantic )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )
set( CMAKE_CXX_FLAGS_DEBUG "-O0 -g3" )

# Default to 1st tutorial.
if( NOT DEFINED TUTORIAL )
    set( TUTORIAL 1 )
endif()

set( FREERTOS_KERNEL_PATH "FreeRTOS-Kernel" )
set( FREERTOS_TUTORIAL_INCLUDE_SEARCH_PATH "tutorials/tutorial_${TUTORIAL}/include" )
file( GLOB FREERTOS_TUTORIAL_SOURCES "tutorials/tutorial_${TUTORIAL}/source/*.c" )

# Add the freertos_config for FreeRTOS-Kernel.
add_library( freertos_config INTERFACE )
target_include_directories( freertos_config
                            INTERFACE
                            ${FREERTOS_TUTORIAL_INCLUDE_SEARCH_PATH} )

# Select heap 3.
set( FREERTOS_HEAP "3" CACHE STRING "" FORCE )

# Select the Posix port.
set( FREERTOS_PORT "GCC_POSIX" CACHE STRING "" FORCE )

# Add the FreeRTOS-Kernel subdirectory.
add_subdirectory( ${FREERTOS_KERNEL_PATH} ${CMAKE_CURRENT_BINARY_DIR}/FreeRTOS-Kernel )

add_executable( freertos_example
                ${FREERTOS_TUTORIAL_SOURCES} )

target_link_libraries( freertos_example freertos_kernel freertos_config )
