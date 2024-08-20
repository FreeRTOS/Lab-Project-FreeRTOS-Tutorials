# Learning Objectives
* Message Buffer.

# Concepts
Message buffers are inter-task communication primitives to allow variable length
discrete messages to be passed from an interrupt service routine to a task, or
from one task to another task. A message can only be read out in it entirety,
not as individual bytes.

**IMPORTANT NOTE:** The message buffer implementation assumes there is only one
task or interrupt that will write to the buffer (the writer), and only one task
or interrupt that will read from the buffer (the reader).

# Steps
1. Complete all the TODOs in the `source/tutorials/tutorial_20/source/tutorial_20.c`
   file.

1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=20
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
