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
static void prvTask1Function( void * pvParams );
static void prvTask2Function( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate( prvTask1Function,
                                       "Task1",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvTask2Function,
                                       "Task2",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
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

static void prvTask1Function( void * pvParams )
{
    uint64_t i;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Tutorial 6 task 1 running...\r\n" );

        for( i = 0; i < 100000000; i++ )
        {
            /* This loop is just a very crude delay implementation. */
        }
    }
}
/*-----------------------------------------------------------*/

static void prvTask2Function( void * pvParams )
{
    uint64_t i;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Tutorial 6 task 2 running...\r\n" );

        for( i = 0; i < 100000000; i++ )
        {
            /* This loop is just a very crude delay implementation. */
        }
    }
}
/*-----------------------------------------------------------*/
