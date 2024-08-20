# Learning Objectives
* Creating and using FreeRTOS queues to send messages between tasks.

# Concepts
Queues are the primary mechanism for inter-task communications. They can be used
to send messages between tasks, and between interrupts and tasks.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_9/source/tutorial_9.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=9
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
