

## 🧵 1. **Task Creation**

1. **What is a task in RTOS?**  
   A task is an independent thread of execution managed by the RTOS scheduler. It has its own stack and context. In FreeRTOS, tasks are created using `xTaskCreate()` or `xTaskCreateStatic()`.

2. **How do you create a task in FreeRTOS?**  
   Use `xTaskCreate()` for dynamic allocation:  
   ```c
   BaseType_t xTaskCreate(TaskFunction_t pxTaskCode, const char * const pcName,
                          configSTACK_DEPTH_TYPE usStackDepth, void *pvParameters,
                          UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask);
   ```

3. **What parameters are needed for `xTaskCreate()`?**  
   - `pxTaskCode`: Function pointer to the task code  
   - `pcName`: Task name (for debugging)  
   - `usStackDepth`: Stack size in words  
   - `pvParameters`: Pointer to parameters passed to the task  
   - `uxPriority`: Task priority  
   - `pxCreatedTask`: Handle to the created task

4. **What happens if task creation fails?**  
   `xTaskCreate()` returns `pdFAIL` if there’s insufficient heap memory.

5. **Can we create tasks from within another task?**  
   Yes, as long as it’s not inside an ISR. Task creation is thread-safe.

6. **Is there a limit on the number of tasks?**  
   No hard limit, but constrained by available RAM and CPU cycles.

7. **What is the role of the task handle?**  
   It’s used to reference the task later—for example, in `vTaskDelete(xHandle)` or `vTaskSuspend(xHandle)`.

8. **Can a task delete itself?**  
   Yes. Use `vTaskDelete(NULL);` inside the task function.

9. **What is the default state of a newly created task?**  
   It enters the **Ready** state and waits for the scheduler to run it.

10. **What is the difference between task and thread?**  
   In FreeRTOS, a task is essentially a lightweight thread. The terms are often used interchangeably in embedded systems.

---

## 🧱 2. **Static Allocation**

1. **What is static allocation in RTOS?**  
   Memory is allocated at compile time. This avoids runtime failures and fragmentation.

2. **Why is static allocation preferred in safety-critical systems?**  
   It ensures deterministic behavior and avoids heap-related crashes.

3. **Which API is used for static task creation in FreeRTOS?**  
   `xTaskCreateStatic()`  
   ```c
   TaskHandle_t xTaskCreateStatic(TaskFunction_t pxTaskCode, const char * const pcName,
                                  uint32_t ulStackDepth, void *pvParameters,
                                  UBaseType_t uxPriority, StackType_t *puxStackBuffer,
                                  StaticTask_t *pxTaskBuffer);
   ```

4. **What extra parameters are needed for static allocation?**  
   - `puxStackBuffer`: Pointer to pre-allocated stack  
   - `pxTaskBuffer`: Pointer to a `StaticTask_t` structure

5. **Can you mix static and dynamic allocation in the same system?**  
   Yes. FreeRTOS supports both simultaneously.

6. **What happens if the stack buffer is too small?**  
   Stack overflow may occur. Enable stack checking via `configCHECK_FOR_STACK_OVERFLOW`.

7. **Is static allocation more memory-efficient?**  
   It’s not always more efficient, but it’s more predictable and safer.

8. **Can queues and semaphores also be statically allocated?**  
   Yes. Use `xQueueCreateStatic()`, `xSemaphoreCreateMutexStatic()`, etc.

9. **What is the main drawback of static allocation?**  
   Less flexibility. You must plan memory usage ahead of time.

10. **How do you detect stack overflow in statically allocated tasks?**  
   Enable stack overflow detection in `FreeRTOSConfig.h`:
   ```c
   #define configCHECK_FOR_STACK_OVERFLOW 2
   ```

---

## 🎚️ 3. **Task Priorities**

1. **What is task priority in RTOS?**  
   It determines the order of execution. Higher-priority tasks preempt lower ones.

2. **What is the range of priorities in FreeRTOS?**  
   From 0 (lowest) to `configMAX_PRIORITIES - 1`.

3. **What happens if two tasks have the same priority?**  
   If time slicing is enabled (`configUSE_TIME_SLICING = 1`), they share CPU time in round-robin fashion.

4. **Can task priority be changed at runtime?**  
   Yes, using `vTaskPrioritySet(TaskHandle_t xTask, UBaseType_t uxNewPriority);`

5. **What is priority inversion?**  
   A low-priority task holds a resource needed by a high-priority task, causing the high-priority task to wait.

6. **How is priority inversion handled?**  
   Use mutexes with priority inheritance:
   ```c
   xSemaphoreCreateMutex(); // Enables priority inheritance
   ```

7. **What is the default priority of a task?**  
   Whatever you assign during creation. There’s no implicit default.

8. **What happens if all tasks have the same priority?**  
   They are time-sliced if enabled, otherwise the first ready task runs until it blocks or yields.

9. **Can an idle task have a higher priority than user tasks?**  
   No. The idle task always has the lowest priority (0).

10. **What is the effect of assigning all tasks the highest priority?**  
   The idle task won’t run, leading to starvation of background services like memory cleanup.



### **1. What is a Mutex?**

A **mutex** (mutual exclusion) is a synchronization primitive used to protect shared resources. It ensures that only one thread or task can access a critical section at a time. According to [GeeksforGeeks](https://www.geeksforgeeks.org/operating-systems/mutex-vs-semaphore/), mutexes enforce *strict ownership*—only the task that locks it can unlock it. This is crucial in embedded systems where shared peripherals like SPI or I²C buses are accessed by multiple tasks.

**API Example (FreeRTOS):**
```c
SemaphoreHandle_t xMutex = xSemaphoreCreateMutex();
xSemaphoreTake(xMutex, portMAX_DELAY);
// critical section
xSemaphoreGive(xMutex);
```

---

### **2. What is the Concept of Ownership?**

Ownership refers to the idea that the task which acquires a mutex is the only one allowed to release it. This prevents accidental unlocks and enforces discipline in resource management. As [FreeRTOS documentation](https://en.freertos.org/Documentation/02-Kernel/04-API-references/10-Semaphore-and-Mutexes/06-xSemaphoreCreateMutex) explains, this is what differentiates a mutex from a binary semaphore.

---

### **3. What is a Race Condition?**

A **race condition** occurs when multiple threads access shared data concurrently, and the final outcome depends on the timing of their execution. This can lead to unpredictable behavior. A great example from [CodeProject](https://www.codeproject.com/Articles/5388900/What-is-a-Race-Condition-Causes-Examples-and-Solut) illustrates a bank account scenario where simultaneous deposits and withdrawals without synchronization lead to incorrect balances.

**Prevention:** Use mutexes or atomic operations to serialize access.

---

### **4. What is a Semaphore?**

A **semaphore** is a signaling mechanism. It can be binary (0 or 1) or counting (0 to N). Unlike mutexes, semaphores don’t enforce ownership. They’re ideal for signaling between tasks or managing a pool of resources, like buffer slots or UART channels.

**API Example (FreeRTOS):**
```c
SemaphoreHandle_t xSemaphore = xSemaphoreCreateCounting(5, 5);
xSemaphoreTake(xSemaphore, portMAX_DELAY); // acquire resource
xSemaphoreGive(xSemaphore); // release resource
```

---

### **5. Difference Between Mutex and Semaphore**

| Feature         | Mutex                                      | Semaphore                                   |
|----------------|---------------------------------------------|---------------------------------------------|
| Ownership       | Enforced (only owner can release)           | Not enforced                                |
| Use Case        | Mutual exclusion                            | Signaling or resource counting              |
| API (FreeRTOS)  | `xSemaphoreCreateMutex()`                   | `xSemaphoreCreateBinary()` / `Counting()`   |
| Priority Inversion Handling | Yes (via priority inheritance) | No                                          |

As [GeeksforGeeks](https://www.geeksforgeeks.org/operating-systems/mutex-vs-semaphore/) and [Guru99](https://www.guru99.com/mutex-vs-semaphore.html) explain, mutexes are best for exclusive access, while semaphores are more flexible for signaling and resource pools.

---

If you'd like, I can walk you through a real-world firmware scenario using these APIs—maybe something like task synchronization in a sensor fusion system or managing DMA buffers. Want to dive into that?
