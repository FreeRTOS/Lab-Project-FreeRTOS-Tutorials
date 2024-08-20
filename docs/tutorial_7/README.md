# Learning Objectives
* Scheduling Algorithms.

# Concepts
FreeRTOS-Kernel supports the following 3 scheduling algorithms:
1. Prioritized Preemptive Scheduling with Time Slicing
2. Prioritized Preemptive Scheduling without Time Slicing
3. Co-operative Scheduling

## Prioritized Preemptive Scheduling without Time Slicing
The required FreeRTOSConfig.h settings are:

```c
#define configUSE_PREEMPTION    1
#define configUSE_TIME_SLICING  0
```

Prioritized Preemptive Scheduling with without Slicing algorithm uses
Preemption but does not use Time Slicing.

**Preemption** - Preemptive scheduling algorithm immediately preempts the
Running task if a task that has a priority higher than the Running task
enters the Ready state. Being preempted means being involuntarily
(without explicitly yielding or blocking) moved out of the Running state and
into the Ready state to allow a different task to run.

**Time Slicing** - Time slicing is used to share processing time between tasks
of equal priority, even when the tasks do not explicitly yield or enter the
Blocked state. Time Slicing selects a new task to run at the end of each
time slice if there are other Ready state tasks that have the same priority
as the Running task. A time slice is equal to the time between two RTOS tick
interrupts.

# Steps

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=7
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
