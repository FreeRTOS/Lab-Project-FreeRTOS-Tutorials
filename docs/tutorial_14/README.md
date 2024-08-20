# Learning Objectives
* Priority Inversion and Priority Inheritance.

# Concepts
## Priority Inversion
Priority Inversion is a scenario in which a high priority task is indefinitely
delayed while waiting for a resource held by a low priority task that cannot
proceed due to the presence of an unrelated medium priority task. As a result,
the high priority task is prevented from running by lower medium priority task,
effectively inverting the assigned priorities of the tasks. This violates the
priority model that high priority tasks can only be prevented from running by
higher priority tasks.

## Priority Inheritance
Priority Inheritance is a method for eliminating unbounded Priority Inversion.
If a high priority task blocks while attempting to obtain a resource that is
currently held by a lower priority task, then the priority of the task holding
the resource is temporarily raised to that of the blocking task. This mechanism
ensures that the higher priority task is kept in the blocked state for the
shortest time possible, and in so doing minimize the 'priority inversion' that
has already occurred.

# Steps
1. Execute the following commands from the root of the repository to build:
   ```shell
   rm -rf build
   mkdir build
   cd build
   cmake -B . -S ../source/ -DTUTORIAL=14
   make
   ```

1. Execute the following command to run the binary:
   ```shell
   ./freertos_example
   ```

1. Understand the output.
