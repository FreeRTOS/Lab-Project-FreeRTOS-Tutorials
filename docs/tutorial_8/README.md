# Learning Objectives
* Scheduling Algorithms.

# Concepts
FreeRTOS-Kernel supports the following 3 scheduling algorithms:
1. Prioritized Preemptive Scheduling with Time Slicing
2. Prioritized Preemptive Scheduling without Time Slicing
3. Co-operative Scheduling

## Co-operative Scheduling
The required FreeRTOSConfig.h settings are:

```c
#define configUSE_PREEMPTION    0
```

When the co-operative scheduling is used, a context switch will only occur
when the Running task enters the Blocked state, or the Running task
explicitly yields (manually requests a re-schedule) by calling
taskYIELD(). Tasks are never preempted, so time slicing cannot be used.

# Steps

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=8
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
