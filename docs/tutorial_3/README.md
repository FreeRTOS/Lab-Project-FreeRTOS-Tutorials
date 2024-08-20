# Learning Objectives
* Static allocation.

# Concepts
Each FreeRTOS task requires 2 blocks of memory -
* Task Control Block (TCB) - FreeRTOS-Kernel uses it to store the control
  information of a task.
* Stack - Each task maintains its own stack.

If a task is created using `xTaskCreate` API, then the memory needed for TCB and
Stack is allocated from the FreeRTOS heap by calling `pvPortMalloc`. If a task
is created using `xTaskCreateStatic` API, then the memory needed for TCB and
Stack is provided by the application writer.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_3/source/tutorial_3.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=3
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```
