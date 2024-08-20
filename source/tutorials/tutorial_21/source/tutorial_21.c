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
#include "semphr.h"

/**
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvTask1( void * pvParams );
static void prvTask2( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Mutex used in this program.
 */
static SemaphoreHandle_t xMutex = NULL;

/**
 * @brief Shared counters used in this program.
 */
static uint32_t ulSharedCounter1BetweenTasks = 0;
static uint32_t ulSharedCounter2BetweenTasks = 0;
static uint32_t ulSharedCounterBetweenTasksAndInterrupts = 0;
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate( prvTask1,
                                       "Task1",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvTask2,
                                       "Task2",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xMutex = xSemaphoreCreateMutex();
    configASSERT( xMutex != NULL );

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* Should not reach here. */
    for( ;; )
    {

    }

    /* Just to make the compiler happy. */
    return 0;
}
/*-----------------------------------------------------------*/

static void prvTask1( void * pvParams )
{
    uint32_t ulLocalCounter1, ulLocalCounter2, ulLocalCounter3;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        vTaskSuspendAll();
        {
            ulSharedCounter1BetweenTasks++;
            ulLocalCounter1 = ulSharedCounter1BetweenTasks;
        }
        xTaskResumeAll();

        xSemaphoreTake( xMutex, portMAX_DELAY );
        {
            ulSharedCounter2BetweenTasks++;
            ulLocalCounter2 = ulSharedCounter2BetweenTasks;

        }
        xSemaphoreGive( xMutex );

        taskENTER_CRITICAL();
        {
            ulSharedCounterBetweenTasksAndInterrupts++;
            ulLocalCounter3 = ulSharedCounterBetweenTasksAndInterrupts;
        }
        taskEXIT_CRITICAL();

        fprintf( stderr, "Task 1 ulSharedCounter1BetweenTasks: %u.\r\n", ulLocalCounter1 );
        fprintf( stderr, "Task 1 ulSharedCounter2BetweenTasks: %u.\r\n", ulLocalCounter2 );
        fprintf( stderr, "Task 1 ulSharedCounterBetweenTasksAndInterrupts: %u.\r\n", ulLocalCounter3 );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/

static void prvTask2( void * pvParams )
{
    uint32_t ulLocalCounter1, ulLocalCounter2, ulLocalCounter3;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        vTaskSuspendAll();
        {
            ulSharedCounter1BetweenTasks++;
            ulLocalCounter1 = ulSharedCounter1BetweenTasks;
        }
        xTaskResumeAll();

        xSemaphoreTake( xMutex, portMAX_DELAY );
        {
            ulSharedCounter2BetweenTasks++;
            ulLocalCounter2 = ulSharedCounter2BetweenTasks;

        }
        xSemaphoreGive( xMutex );

        taskENTER_CRITICAL();
        {
            ulSharedCounterBetweenTasksAndInterrupts++;
            ulLocalCounter3 = ulSharedCounterBetweenTasksAndInterrupts;
        }
        taskEXIT_CRITICAL();

        fprintf( stderr, "Task 2 ulSharedCounter1BetweenTasks: %u.\r\n", ulLocalCounter1 );
        fprintf( stderr, "Task 2 ulSharedCounter2BetweenTasks: %u.\r\n", ulLocalCounter2 );
        fprintf( stderr, "Task 2 ulSharedCounterBetweenTasksAndInterrupts: %u.\r\n", ulLocalCounter3 );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    ulSharedCounterBetweenTasksAndInterrupts++;
}
/*-----------------------------------------------------------*/
