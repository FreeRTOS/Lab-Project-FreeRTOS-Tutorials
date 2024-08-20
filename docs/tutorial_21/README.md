# Learning Objectives
* Resource Management.

# Concepts
In a multitasking system there is potential for error if one task starts to
access a shared resource, but does not complete its access before being
preempted. If the task leaves the resource in an inconsistent state, then access
to the same resource by any other task or interrupt could result in data
corruption, or other similar issue.

To ensure data consistency is maintained at all times, access to a shared
resource, must be managed using a 'mutual exclusion' technique. The goal is to
ensure that, once a task starts to access a shared resource, the same task has
exclusive access to the resource until the resource has been returned to a
consistent state.

FreeRTOS provides several features that can be used to implement mutual
exclusion, but the best mutual exclusion method is to (whenever possible, as it
is often not practical) design the application in such a way that resources are
not shared, and each resource is accessed only from a single task.

## Critical Sections
Critical sections are regions of code that are surrounded by calls to the macros
`taskENTER_CRITICAL()` and `taskEXIT_CRITICAL()`, respectively. Critical
sections work by disabling interrupts and therefore, must be kept very short,
otherwise they will adversely affect interrupt response times.

## Suspending (or Locking) the Scheduler
If a shared resource is only accessed from multiple tasks and not from any
interrupt, the access to it can be synchronized by suspending (or locking) the
scheduler. Suspending the scheduler prevents a context switch from occurring,
but leaves interrupts enabled. If an interrupt requests a context switch while
the scheduler is suspended, then the request is held pending, and is performed
only when the scheduler is resumed (un-suspended).

The scheduler is suspended by calling `vTaskSuspendAll()` and is resumed
(un-suspended) by calling `xTaskResumeAll()`.

## Mutex
Mutex, short for Mutual Exclusion, is a synchronization primitive used to
synchronize access to a shared resource that is shared between two or more
tasks.

# Steps
1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=21
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
