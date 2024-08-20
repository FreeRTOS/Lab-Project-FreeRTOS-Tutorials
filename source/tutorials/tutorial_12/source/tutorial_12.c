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
 * @brief Semaphore used in this program.
 */
static SemaphoreHandle_t xSemaphore = NULL;
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
                                       tskIDLE_PRIORITY + 1,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvTask2,
                                       "Task2",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    /*
     * TODO 1 - Create a binary semaphore using xSemaphoreCreateBinary API.
     *
     * Assign the return value to xSemaphore.
     */

    configASSERT( xSemaphore != NULL );

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
    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /*
         * TODO 2 - Take the semaphore using the xSemaphoreTake API.
         *
         * Use the following values for xSemaphoreTake parameters:
         * xSemaphore   xSemaphore
         * xBlockTime   portMAX_DELAY
         */

        fprintf( stderr, "Task 1 is running...\r\n" );
    }

}
/*-----------------------------------------------------------*/

static void prvTask2( void * pvParams )
{
    BaseType_t xSemaphoreGiveResult = pdFAIL;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Task 2 - signalling Task 1...\r\n" );

        /*
         * TODO 3 - Give the semaphore using the xSemaphoreGive API.
         *
         * Use the following values for xSemaphoreGive parameters:
         * xSemaphore       xSemaphore
         *
         * Assign the return value to xSemaphoreGiveResult.
         */

        configASSERT( xSemaphoreGiveResult == pdPASS );

        fprintf( stderr, "Task 2 is running...\r\n" );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/
