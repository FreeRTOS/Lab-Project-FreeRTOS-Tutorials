# Learning Objectives
* Task Priorities.

# Concepts
The FreeRTOS scheduler always runs the highest priority ready task (i.e. the
task that is able to run).

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_4/source/tutorial_4.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=4
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```
