# Learning Objectives
* Task Synchronization using Event Groups.

# Concepts
An event group can be used to create a synchronization point:

* Each task that must participate in the synchronization is assigned a unique
  event bit within the event group.
* Each task sets its own event bit when it reaches the synchronization point.
* Having set its own event bit, each task blocks on the event group to wait for
  the event bits that represent all the other synchronizing tasks to also become
  set.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_16/source/tutorial_16.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=16
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
