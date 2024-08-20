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
 * @brief Definitions of event bits.
 */
#define EVENT_1_BIT ( 1UL << 0UL )
#define EVENT_2_BIT ( 1UL << 1UL )
/*-----------------------------------------------------------*/

/**
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvEventGeneratorTask( void * pvParams );
static void prvEventHandlerTask( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Handle of the event handler task.
 */
static TaskHandle_t xEventHandlerTaskHandle = NULL;
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTaskCreationResult = pdFAIL;

    xTaskCreationResult = xTaskCreate( prvEventGeneratorTask,
                                       "Generator",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvEventHandlerTask,
                                       "Handler",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY + 1,
                                       &( xEventHandlerTaskHandle ) );
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

static void prvEventGeneratorTask( void * pvParams )
{
    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Generating event 1...\r\n" );

        /*
         * TODO 1 - Notify the event handler task about event 1 using
         * xTaskNotify API.
         *
         * Use the following values for xTaskNotify parameters:
         * xTaskToNotify    xEventHandlerTaskHandle
         * ulValue          EVENT_1_BIT
         * eAction          eSetBits
         */


        vTaskDelay( pdMS_TO_TICKS( 500 ) );

        fprintf( stderr, "Generating event 2...\r\n" );

        /*
         * TODO 2 - Notify the event handler task about event 2 using
         * xTaskNotify API.
         *
         * Use the following values for xTaskNotify parameters:
         * xTaskToNotify    xEventHandlerTaskHandle
         * ulValue          EVENT_2_BIT
         * eAction          eSetBits
         */


        vTaskDelay( pdMS_TO_TICKS( 500 ) );

        fprintf( stderr, "Generated both events...\r\n" );
    }
}
/*-----------------------------------------------------------*/

static void prvEventHandlerTask( void * pvParams )
{
    uint32_t ulNotifiedValue;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /*
         * TODO 3 - Wait for a task notification using xTaskNotifyWait API.
         *
         * Use the following values for xTaskNotifyWait parameters:
         * ulBitsToClearOnEntry     0
         * ulBitsToClearOnExit      ~0
         * pulNotificationValue     &( ulNotifiedValue )
         * xTicksToWait             portMAX_DELAY
         */


        if( ( ulNotifiedValue & EVENT_1_BIT ) != 0 )
        {
            fprintf( stderr, "Handling event 1...\r\n" );
        }

        if( ( ulNotifiedValue & EVENT_2_BIT ) != 0 )
        {
            fprintf( stderr, "Handling event 2...\r\n" );
        }
    }
}
/*-----------------------------------------------------------*/
