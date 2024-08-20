# Learning Objectives
* Task Parameters.

# Concepts
A task can be passed a value at the time of creation using the `pvParameters`
parameter of the `xTaskCreate` API. The value is passed as the parameter to the
created task.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_5/source/tutorial_5.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=5
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```
