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
 * @brief Function that implement FreeRTOS tasks.
 */
static void prvTaskFunction( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    /* TODO 1 - Create a FreeRTOS task using xTaskCreate API which
     * uses prvTaskFunction as the task function.
     *
     * Use the following values for xTaskCreate parameters:
     * pxTaskCode       prvTaskFunction
     * pcName           "Task1"
     * usStackDepth     configMINIMAL_STACK_SIZE
     * pvParameters     ( void * ) 1
     * uxPriority       tskIDLE_PRIORITY
     * pxCreatedTask    NULL
     *
     * Assign the return value to xTaskCreationResult.
     */
    configASSERT( xTaskCreationResult == pdPASS );

    /* TODO 2 - Create a FreeRTOS task using xTaskCreate API which
     * uses prvTaskFunction as the task function.
     *
     * Use the following values for xTaskCreate parameters:
     * pxTaskCode       prvTaskFunction
     * pcName           "Task2"
     * usStackDepth     configMINIMAL_STACK_SIZE
     * pvParameters     ( void * ) 2
     * uxPriority       tskIDLE_PRIORITY
     * pxCreatedTask    NULL
     *
     * Assign the return value to xTaskCreationResult.
     */
    configASSERT( xTaskCreationResult == pdPASS );

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

static void prvTaskFunction( void * pvParams )
{
    for( ;; )
    {
        fprintf( stderr, "Tutorial 5 task %p running...\r\n", pvParams );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/
