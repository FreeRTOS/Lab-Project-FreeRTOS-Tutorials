# Learning Objectives
* Event Management using Event Groups.

# Concepts
Event groups are another synchronization primitives of FreeRTOS that allow
events to be communicated to tasks. Unlike queues and semaphores:

* Event groups allow a task to wait in the Blocked state for a combination of
  one of more events to occur.
* Event groups unblock all the tasks that were waiting for the same event, or
  combination of events, when the event occurs.

These unique properties of event groups make them useful for synchronizing
multiple tasks, broadcasting events to more than one task, allowing a task to
wait in the Blocked state for any one of a set of events to occur, and allowing
a task to wait in the Blocked state for multiple actions to complete.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_15/source/tutorial_15.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=15
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
