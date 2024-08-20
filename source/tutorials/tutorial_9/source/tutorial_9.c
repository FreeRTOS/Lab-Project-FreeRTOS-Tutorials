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
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvSenderTask( void * pvParams );
static void prvReceiverTask( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Queue used in the program.
 */
static QueueHandle_t xQueue;
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate( prvSenderTask,
                                       "Sender",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY + 1,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

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

static void prvSenderTask( void * pvParams )
{
    BaseType_t xQueueSendResult;
    UBaseType_t uxValueToSend = 0;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        uxValueToSend++;

        /* TODO 2 - Send uxValueToSend to the queue using xQueueSend API.
         *
         * Use the following values for xQueueSend parameters:
         * xQueue           xQueue
         * pvItemToQueue    &( uxValueToSend )
         * xTicksToWait     portMAX_DELAY
         *
         * Assign the return value to xQueueSendResult.
         */

        configASSERT( xQueueSendResult == pdPASS );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/

static void prvReceiverTask( void * pvParams )
{
    UBaseType_t uxReceivedValue;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /* TODO 3 - Receive from the queue using xQueueReceive API.
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
