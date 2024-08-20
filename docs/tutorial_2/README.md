# Learning Objectives
* Use FreeRTOS APIs to create a task.

# Concepts

## Task Functions
FreeRTOS Tasks are implemented as C functions which must have the following
prototype:

```c
void TaskFunction( void *pvParameters );
```

Each task normally runs forever within an infinite loop, and does not exit. The
structure of a typical task is shown below:

```c
void TaskFunction( void *pvParameters )
{
    /* A task is normally implemented as an infinite loop. */
    for( ;; )
    {
        /* The code to implement the task functionality goes here. */
    }
}
```

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_2/source/tutorial_2.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=2
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```
