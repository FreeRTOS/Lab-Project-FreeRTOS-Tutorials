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
 * @brief Function that implement FreeRTOS task.
 */
static void prvTaskFunction( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief TCB and stack buffers for the task.
 */
static StaticTask_t xTaskTcbBuffer;
static StackType_t xTaskStackBuffer[ configMINIMAL_STACK_SIZE ];
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    TaskHandle_t xCreatedTaskHandle = NULL;

    /* TODO 1 - Create a FreeRTOS task using xTaskCreateStatic API which
     * uses prvTaskFunction as the task function.
     *
     * Use the following values for xTaskCreateStatic parameters:
     * pxTaskCode       prvTaskFunction
     * pcName           "Task1"
     * ulStackDepth     configMINIMAL_STACK_SIZE
     * pvParameters     NULL
     * uxPriority       tskIDLE_PRIORITY
     * puxStackBuffer   &( xTaskStackBuffer[ 0 ] )
     * pxTaskBuffer     &( xTaskTcbBuffer )
     *
     * Assign the return value to xCreatedTaskHandle.
     */
    configASSERT( xCreatedTaskHandle != NULL );

    /* TODO 2 - Call vTaskStartScheduler to start the scheduler. */

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
    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Tutorial 3 running...\r\n" );

        /* Pause for a second. */
        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/
