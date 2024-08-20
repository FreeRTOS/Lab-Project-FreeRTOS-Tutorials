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
#include "event_groups.h"

/**
 * @brief Definitions of event bits in the event group.
 */
#define EVENT_1_BIT ( 1UL << 0UL )
#define EVENT_2_BIT ( 1UL << 1UL )
/*-----------------------------------------------------------*/

/**
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvEventGeneratorTask( void * pvParams );
static void prvEventHandlerTask1( void * pvParams );
static void prvEventHandlerTask2( void * pvParams );
/*-----------------------------------------------------------*/

/**
 * @brief Event group used in this program.
 */
static EventGroupHandle_t xEventGroup = NULL;
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

    xTaskCreationResult = xTaskCreate( prvEventHandlerTask1,
                                       "Handler1",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY + 1,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvEventHandlerTask2,
                                       "Handler2",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY + 2,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    /*
     * TODO 1 - Create event group using xEventGroupCreate API.
     *
     * Assign the return value to xEventGroup.
     */

    configASSERT( xEventGroup != NULL );

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
         * TODO 2 - Set EVENT_1_BIT in the event group using xEventGroupSetBits
         * API.
         *
         * Use the following values for xEventGroupSetBits parameters:
         * xEventGroup  xEventGroup
         * uxBitsToSet  EVENT_1_BIT
         */


        vTaskDelay( pdMS_TO_TICKS( 500 ) );

        fprintf( stderr, "Generating event 2...\r\n" );

        /*
         * TODO 3 - Set EVENT_2_BIT in the event group using xEventGroupSetBits
         * API.
         *
         * Use the following values for xEventGroupSetBits parameters:
         * xEventGroup  xEventGroup
         * uxBitsToSet  EVENT_2_BIT
         */


        fprintf( stderr, "Generated both the events...\r\n" );

        vTaskDelay( pdMS_TO_TICKS( 500 ) );
    }
}
/*-----------------------------------------------------------*/

static void prvEventHandlerTask1( void * pvParams )
{
    EventBits_t xEventBitsValue;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /*
         * TODO 4 - Wait for events using xEventGroupWaitBits API.
         *
         * Use the following values for xEventGroupWaitBits parameters:
         * xEventGroup      xEventGroup
         * uxBitsToWaitFor  ( EVENT_1_BIT | EVENT_2_BIT )
         * xClearOnExit     pdTRUE
         * xWaitForAllBits  pdTRUE
         * xTicksToWait     portMAX_DELAY
         *
         * Assign the return value to xEventBitsValue.
         */


        if( ( xEventBitsValue & EVENT_1_BIT ) != 0 )
        {
            fprintf( stderr, "Handler Task 1: Handling  event 1...\r\n" );
        }
        if( ( xEventBitsValue & EVENT_2_BIT ) != 0 )
        {
            fprintf( stderr, "Handler Task 1: Handling  event 2...\r\n" );
        }
    }
}
/*-----------------------------------------------------------*/

static void prvEventHandlerTask2( void * pvParams )
{
    EventBits_t xEventBitsValue;

    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        /*
         * TODO 5 - Wait for events using xEventGroupWaitBits API.
         *
         * Use the following values for xEventGroupWaitBits parameters:
         * xEventGroup      xEventGroup
         * uxBitsToWaitFor  ( EVENT_1_BIT | EVENT_2_BIT )
         * xClearOnExit     pdTRUE
         * xWaitForAllBits  pdTRUE
         * xTicksToWait     portMAX_DELAY
         *
         * Assign the return value to xEventBitsValue.
         */


        if( ( xEventBitsValue & EVENT_1_BIT ) != 0 )
        {
            fprintf( stderr, "Handler Task 2: Handling  event 1...\r\n" );
        }
        if( ( xEventBitsValue & EVENT_2_BIT ) != 0 )
        {
            fprintf( stderr, "Handler Task 2: Handling  event 2...\r\n" );
        }
    }
}
/*-----------------------------------------------------------*/
