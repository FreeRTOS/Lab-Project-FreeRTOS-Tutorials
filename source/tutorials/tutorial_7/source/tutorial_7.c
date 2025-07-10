/*
 * FreeRTOS-Tutorials
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* Standard includes. */
#include <stdio.h>
#include <unistd.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/**
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvTask1Function(void *pvParams);
static void prvTask2Function(void *pvParams);
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                    char * pcTaskName )
{
    /* Check pcTaskName for the name of the offending task,
        * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    ( void ) xTask;
    ( void ) pcTaskName;

    // print the stack overflow error
    fprintf(stderr, "Stack overflow in task: %s\r\n", pcTaskName);
    // halt the system
    for (;;);
}

/**
 * @brief Tutorial entry point.
 */
int main(void)
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate(prvTask1Function,
                                      "Task1",
                                      configMINIMAL_STACK_SIZE,
                                      NULL,
                                      3,
                                      NULL);



    configASSERT(xTaskCreationResult == pdPASS);

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* Should not reach here. */
    for (;;)
    {
    }

    /* Just to make the compiler happy. */
    return 0;
}
/*-----------------------------------------------------------*/

static void prvTask1Function(void *pvParams)
{
    uint64_t i;
    BaseType_t xTaskCreationResult = pdFAIL;

    /* Silence warning about unused parameters. */
    (void)pvParams;

    xTaskCreationResult = xTaskCreate(prvTask2Function,
                                      "Task2",
                                      1000,
                                      NULL,
                                      2,
                                      NULL);
    configASSERT(xTaskCreationResult == pdPASS);

    for (;;)
    {
        fprintf(stderr, "Tutorial 7 task 1 running...\r\n");

        for (i = 0; i < 100000000; i++)
        {
            /* This loop is just a very crude delay implementation. */
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
/*-----------------------------------------------------------*/

static void prvTask2Function(void *pvParams)
{
    uint64_t i;

    /* Silence warning about unused parameters. */
    (void)pvParams;

    // simulate a stack overflow by creating an infinite loop
    // this will trigger the stack overflow hook defined above

    uint64_t stackOverflowCounter[10000] = {0}; // This will cause a stack overflow if the stack size is too small

    for (i = 0; i < sizeof(stackOverflowCounter) / sizeof(stackOverflowCounter[0]); i++)
    {
        stackOverflowCounter[i] = i; // This will fill the array and cause a stack overflow
    }
    for (;;)
    {
        fprintf(stderr, "******************Tutorial 7 task 2 running...\r\n");

        for (i = 0; i < 100000000; i++)
        {
            /* This loop is just a very crude delay implementation. */
        }
        // vTaskDelay ( pdMS_TO_TICKS( 100 ) );
    }
}
/*-----------------------------------------------------------*/
