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
#define TASK_1_BIT ( 1UL << 0UL )
#define TASK_2_BIT ( 1UL << 1UL )
#define TASK_3_BIT ( 1UL << 2UL )
/*-----------------------------------------------------------*/

/**
 * @brief Functions that implement FreeRTOS tasks.
 */
static void prvTask1( void * pvParams );
static void prvTask2( void * pvParams );
static void prvTask3( void * pvParams );
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

    xTaskCreationResult = xTaskCreate( prvTask1,
                                       "Task1",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvTask2,
                                       "Task2",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
                                       NULL );
    configASSERT( xTaskCreationResult == pdPASS );

    xTaskCreationResult = xTaskCreate( prvTask3,
                                       "Task3",
                                       configMINIMAL_STACK_SIZE,
                                       NULL,
                                       tskIDLE_PRIORITY,
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

static void prvTask1( void * pvParams )
{
    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Task 1 reached sync point.\r\n" );

        /*
         * TODO 2 - Synchronize using xEventGroupSync API.
         *
         * Use the following values for xEventGroupSync parameters:
         * xEventGroup      xEventGroup
         * uxBitsToSet      TASK_1_BIT
         * uxBitsToWaitFor  ( TASK_1_BIT | TASK_2_BIT | TASK_3_BIT )
         * xTicksToWait     portMAX_DELAY
         */


        fprintf( stderr, "Task 1 exited sync point.\r\n" );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/

static void prvTask2( void * pvParams )
{
    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Task 2 reached sync point.\r\n" );

        /*
         * TODO 3 - Synchronize using xEventGroupSync API.
         *
         * Use the following values for xEventGroupSync parameters:
         * xEventGroup      xEventGroup
         * uxBitsToSet      TASK_2_BIT
         * uxBitsToWaitFor  ( TASK_1_BIT | TASK_2_BIT | TASK_3_BIT )
         * xTicksToWait     portMAX_DELAY
         */


        fprintf( stderr, "Task 2 exited sync point.\r\n" );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/

static void prvTask3( void * pvParams )
{
    /* Silence warning about unused parameters. */
    ( void ) pvParams;

    for( ;; )
    {
        fprintf( stderr, "Task 3 reached sync point.\r\n" );

        /*
         * TODO 4 - Synchronize using xEventGroupSync API.
         *
         * Use the following values for xEventGroupSync parameters:
         * xEventGroup      xEventGroup
         * uxBitsToSet      TASK_3_BIT
         * uxBitsToWaitFor  ( TASK_1_BIT | TASK_2_BIT | TASK_3_BIT )
         * xTicksToWait     portMAX_DELAY
         */


        fprintf( stderr, "Task 3 exited sync point.\r\n" );

        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
}
/*-----------------------------------------------------------*/