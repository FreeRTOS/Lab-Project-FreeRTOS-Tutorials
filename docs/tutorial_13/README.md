# Learning Objectives
* Mutex.

# Concepts
Mutex, short for Mutual Exclusion, is a synchronization primitive used to
synchronize access to a shared resource.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_13/source/tutorial_13.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=13
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
