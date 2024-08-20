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
#include "stream_buffer.h"

/**
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvReaderTask( void * pvParams );
static void prvWriterTask( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Stream buffer used in this program.
 */
static StreamBufferHandle_t xStreamBuffer = NULL;
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate( prvReaderTask,
                                       "Reader",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY + 1,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvWriterTask,
                                       "Writer",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    /*
     * TODO 1 - Create a stream buffer of size 10 using xStreamBufferCreate API.
     *
     * Use the following values for xStreamBufferCreate parameters:
     * xBufferSizeBytes     10
     * xTriggerLevelBytes   5
     *
     * Assign the return value to xStreamBuffer.
     */

    configASSERT( xStreamBuffer != NULL );

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

static void prvReaderTask( void * pvParams )
{
    uint8_t ucRxData[ 5 ];
    size_t i, uxReceivedBytes;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /*
         * TODO 2 - Read data from the steam buffer using xStreamBufferReceive
         * API.
         *
         * Use the following values for xStreamBufferReceive parameters:
         * xStreamBuffer        xStreamBuffer
         * pvRxData             &( ucRxData[ 0 ] )
         * xBufferLengthBytes   5
         * xTicksToWait         portMAX_DELAY
         *
         * Assign the return value to uxReceivedBytes.
         */


        fprintf( stderr, "Received %lu byte(s)...\r\n", uxReceivedBytes );

        for( i = 0; i < uxReceivedBytes; i++ )
        {
            fprintf( stderr, "0x%0X ", ucRxData[ i ] );
        }

        fprintf( stderr, "\r\n" );
    }
}
/*-----------------------------------------------------------*/

static void prvWriterTask( void * pvParams )
{
    uint8_t ucTxData[ 6 ] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 };
    size_t uxSentBytes;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Sending 1 byte...\r\n" );

        /*
         * TODO 3 - Send 1 byte to the stream buffer using xStreamBufferSend
         * API.
         *
         * Use the following values for xStreamBufferSend parameters:
         * xStreamBuffer        xStreamBuffer
         * pvTxData             &( ucTxData[ 0 ] )
         * xDataLengthBytes     1
         * xTicksToWait         portMAX_DELAY
         *
         * Assign the return value to uxSentBytes.
         */

        configASSERT( uxSentBytes == 1 );

        fprintf( stderr, "Sending 5 bytes...\r\n" );

        /*
         * TODO 4 - Send 5 bytes to the stream buffer using xStreamBufferSend
         * API.
         *
         * Use the following values for xStreamBufferSend parameters:
         * xStreamBuffer        xStreamBuffer
         * pvTxData             &( ucTxData[ 1 ] )
         * xDataLengthBytes     5
         * xTicksToWait         portMAX_DELAY
         *
         * Assign the return value to uxSentBytes.
         */

        configASSERT( uxSentBytes == 5 );

        fprintf( stderr, "Finished sending data.\r\n" );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/
