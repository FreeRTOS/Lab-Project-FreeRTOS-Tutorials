# Learning Objectives
* Task notifications.
* Using task notifications as a light weight event group.

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

## Using task notifications as a light weight event group
When a task notification is used in place of an event group the receiving
task's notification value is used in place of the event group, bits within
the receiving task's notification value are used as event flags, and the
xTaskNotifyWait() API function is used in place of the event group's
xEventGroupWaitBits() API function. Likewise, bits are set using the
xTaskNotify() API function (with their eAction parameter set to eSetBits) in
place of the xEventGroupSetBits() functions.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_18/source/tutorial_18.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=18
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
