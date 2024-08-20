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
#include "queue.h"

/**
 * @brief Function that implement FreeRTOS task.
 */
static void prvReceiverTask( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Queue used in the program.
 */
static QueueHandle_t xQueue;

/**
 * @brief Counter used in the program.
 */
static UBaseType_t uxCounter = 0;
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate( prvReceiverTask,
                                       "Receiver",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    /* TODO 1 - Create a queue capable of holding 5 UBaseType_t using
     * xQueueCreate API.
     *
     * Use the following values for xQueueCreate parameters:
     * uxQueueLength    5
     * uxItemSize       sizeof( UBaseType_t )
     *
     * Assign the return value to xQueue.
     */

    configASSERT( xQueue != NULL );

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

static void prvReceiverTask( void * pvParams )
{
    UBaseType_t uxReceivedValue;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /* TODO 2 - Receive from the queue using xQueueReceive API.
         *
         * Use the following values for xQueueReceive parameters:
         * xQueue           xQueue
         * pvBuffer         &( uxReceivedValue )
         * xTicksToWait     portMAX_DELAY
         */


        fprintf( stderr, "Value received from the queue: %lu\r\n", uxReceivedValue );
        fprintf( stderr, "Number of items in the queue: %lu.\r\n", uxQueueMessagesWaiting( xQueue ) );
    }
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
    BaseType_t xQueueSendResult = pdFAIL;
    BaseType_t xHighPriorityTaskWoken = pdFALSE;

    uxCounter++;

    if( ( uxCounter % 1000 ) == 0 )
    {
        /* TODO 3 - Send uxCounter to the queue using xQueueSendFromISR API.
         *
         * Use the following values for xQueueSend parameters:
         * xQueue                       xQueue
         * pvItemToQueue                &( uxCounter )
         * pxHigherPriorityTaskWoken    &( xHighPriorityTaskWoken )
         *
         * Assign the return value to xQueueSendResult.
         */

        configASSERT( xQueueSendResult == pdPASS );
    }

    portYIELD_FROM_ISR( xHighPriorityTaskWoken );
}
/*-----------------------------------------------------------*/
