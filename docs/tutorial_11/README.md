# Learning Objectives
* Software Timers.

# Concepts
Software timers are used to schedule the execution of a function at a set time
in the future, or periodically with a fixed frequency. The function executed by
the software timer is called the software timer's callback function.

Software timer callback functions are implemented as C functions and must have
the following prototype:

```c
void TimerCallback( TimerHandle_t xTimer );
```
A software timer’s period is the time between the software timer being started,
and the software timer’s callback function executing. There are two types of
software timer:

1. One-shot timers - Once started, a one-shot timer will execute its callback
function once only. A one-shot timer can be restarted manually, but will not
restart itself.

2. Auto-reload timers - Once started, an auto-reload timer will re-start itself
each time it expires, resulting in periodic execution of its callback function.


# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_11/source/tutorial_11.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=11
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
