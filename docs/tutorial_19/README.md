# Learning Objectives
* Stream Buffer.

# Concepts
Stream buffers are inter-task communication primitives to allow a stream of
bytes to be passed from an interrupt service routine to a task, or from one task
to another task. A byte stream can be of arbitrary length and does not
necessarily have a beginning or end.

**IMPORTANT NOTE:** The stream buffer implementation assumes there is only one
task or interrupt that will write to the buffer (the writer), and only one task
or interrupt that will read from the buffer (the reader).

The amount of data that must be in the stream buffer before a task that is
waiting for data, is removed from the blocked state is called the stream
buffer's Trigger Level. For example:
* If a task is blocked on a read of an empty stream buffer that has a trigger
  level of 1 then the task will be unblocked when a single byte is written to
  the buffer or the task's block time expires.
* If a task is blocked on a read of an empty stream buffer that has a trigger
  level of 10 then the task will not be unblocked until the stream buffer
  contains at least 10 bytes or the task's block time expires.

If a reading task's block time expires before the trigger level is reached then
the task will still receive however many bytes are actually available.

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_19/source/tutorial_19.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=19
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
