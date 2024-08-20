# Learning Objectives
* Add FreeRTOS to a bare metal project.
* Build and execute.

# Concepts
FreeRTOS code is organized into 2 parts:
1. **Common Code** - This is the code written in C and is applicable to all the
   platforms. This includes -
   * `FreeRTOS-Kernel/list.c`
   * `FreeRTOS-Kernel/tasks.c`
   * `FreeRTOS-Kernel/timers.c`
   * `FreeRTOS-Kernel/queue.c`
   * `FreeRTOS-Kernel/event_groups.c`
   * `FreeRTOS-Kernel/stream_buffer.c`
   * `FreeRTOS-Kernel/portable/MemMang/heap_x.c` where x is 1,2,3,4 or 5.

1. **Port Layer** - The code is written in Assembly and C and specific to the
   compiler (e.g. GCC) and the microcontroller architecture (e.g. Cortex-M4).
   We will use `FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix` port in our
   tutorials.

1. **Config File** - The application writer needs to provide a
   `FreeRTOSConfig.h` file to customize the FreeRTOS-Kernel behavior.

# Steps
1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=1
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```
