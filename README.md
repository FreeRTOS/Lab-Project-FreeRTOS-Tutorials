# Getting-Started-With-FreeRTOS
This repository contains a collection of tutorials designed to help users to get
started with the FreeRTOS Kernel.

# Prerequisites
* GCC compiler.
* CMake 3.15.0 or later.
* Clone this repository along with the submodules:
  ```
  git clone --recurse-submodules https://github.com/FreeRTOS/Lab-Project-FreeRTOS-Tutorials.git
  ```
  Or
  ```
  git clone https://github.com/FreeRTOS/Lab-Project-FreeRTOS-Tutorials.git
  cd Lab-Project-FreeRTOS-Tutorials
  git submodule update --init --recursive
  ```

# Tutorials
## Add FreeRTOS to a Bare Metal Project
* [Add FreeRTOS to a Bare Metal Project](docs/tutorial_1/README.md)

## Tasks and Scheduling
* [Task Creation](docs/tutorial_2/README.md)
* [Static Allocation](docs/tutorial_3/README.md)
* [Task Priorities](docs/tutorial_4/README.md)
* [Task Parameters](docs/tutorial_5/README.md)
* [Scheduling Algorithm - Prioritized Preemptive Scheduling with Time Slicing](docs/tutorial_6/README.md)
* [Scheduling Algorithm - Prioritized Preemptive Scheduling without Time Slicing](docs/tutorial_7/README.md)
* [Scheduling Algorithm - Co-operative Scheduling](docs/tutorial_8/README.md)

## Queue
* [Using Queues for Inter-Task Communication](docs/tutorial_9/README.md)
* [Using Queues for Communication between Interrupts and Tasks](docs/tutorial_10/README.md)

## Software Timer
* [Software Timers](docs/tutorial_11/README.md)

## Semaphore and Mutex
* [Semaphore](docs/tutorial_12/README.md)
* [Mutex](docs/tutorial_13/README.md)
* [Priority Inversion and Priority Inheritance](docs/tutorial_14/README.md)

## Event Group
* [Event Management using Event Groups](docs/tutorial_15/README.md)
* [Task Synchronization using Event Groups](docs/tutorial_16/README.md)

## Task Notification
* [Using Task Notifications as a Light Weight Binary Semaphore](docs/tutorial_17/README.md)
* [Using Task Notifications as a Light Weight Event Group](docs/tutorial_18/README.md)

## Stream Buffer
* [Stream Buffer](docs/tutorial_19/README.md)

## Message Buffer
* [Message Buffer](docs/tutorial_20/README.md)

## Resource Management
* [Resource Management](docs/tutorial_21/README.md)
