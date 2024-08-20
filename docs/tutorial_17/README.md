# Learning Objectives
* Task notifications.
* Using task notifications as a light weight binary semaphore.

# Concepts
Task notifications are an efficient mechanism to allow tasks to interact with
other tasks, and to synchronize with ISRs, without the need for a separate
communication object. Using a task notification to send an event or data to a
task is significantly faster than using a queue, semaphore or event group to
perform an equivalent operation. These performance benefits come with some use
case limitations:

1. Task notifications can only be used when there is only one task that
can be the recipient of the event.
1. While a receiving task can wait for a notification in the Blocked state
(so not consuming any CPU time), a sending task cannot wait in the Blocked
state for a send to complete if the send cannot complete immediately.

## Using task notifications as a light weight binary semaphore
When a task notification is used in place of a binary semaphore the receiving
task's notification value is used in place of the binary semaphore's count
value, and the ulTaskNotifyTake() (or ulTaskNotifyTakeIndexed()) API function is
used in place of the semaphore's xSemaphoreTake() API function. The
ulTaskNotifyTake() function's xClearOnExit parameter is set to pdTRUE so the
count value is returned to zero each time the notification is taken - emulating
a binary semaphore. Likewise the xTaskNotifyGive() (or xTaskNotifyGiveIndexed())
is used in place of the semaphore's xSemaphoreGive() function.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_17/source/tutorial_17.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=17
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
