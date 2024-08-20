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
static void prvHighPriorityTaskFunction( void * pvParams );
static void prvLowPriorityTaskFunction( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    /* TODO 1 - Create a FreeRTOS task using xTaskCreate API which
     * uses prvHighPriorityTaskFunction as the task function.
     *
     * Use the following values for xTaskCreate parameters:
     * pxTaskCode       prvHighPriorityTaskFunction
     * pcName           "High"
     * usStackDepth     configMINIMAL_STACK_SIZE
     * pvParameters     NULL
     * uxPriority       1
     * pxCreatedTask    NULL
     *
     * Assign the return value to xTaskCreationResult.
     */
    configASSERT( xTaskCreationResult == pdPASS );

    /* TODO 2 - Create a FreeRTOS task using xTaskCreate API which
     * uses prvLowPriorityTaskFunction as the task function.
     *
     * Use the following values for xTaskCreate parameters:
     * pxTaskCode       prvLowPriorityTaskFunction
     * pcName           "Low"
     * usStackDepth     configMINIMAL_STACK_SIZE
     * pvParameters     NULL
     * uxPriority       0
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

static void prvHighPriorityTaskFunction( void * pvParams )
{
    uint64_t i;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Tutorial 4 high priority task running...\r\n" );

        for( i = 0; i < 1000000000; i++ )
        {
            /* This loop is just a very crude delay implementation. */
        }
    }
}
/*-----------------------------------------------------------*/

static void prvLowPriorityTaskFunction( void * pvParams )
{
    uint64_t i;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Tutorial 4 low priority task running...\r\n" );

        for( i = 0; i < 1000000000; i++ )
        {
            /* This loop is just a very crude delay implementation. */
        }
    }
}
/*-----------------------------------------------------------*/
