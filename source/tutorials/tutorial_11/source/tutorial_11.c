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
#include "timers.h"

/**
 * @brief Timer callback function.
 */
static void prvTimerCallback( TimerHandle_t xTimer );
/*-----------------------------------------------------------*/

/**
 * @brief Tutorial entry point.
 */
int main( void )
{
    BaseType_t xTimerStartResult = pdFAIL;
    TimerHandle_t xAutoReloadTimer, xOneShotTimer;

    /*
     * TODO 1 - Create an auto-reload timer with 1000 ms period using
     * xTimerCreate API.
     *
     * Use the following values for xTimerCreate parameters:
     * pcTimerName              "AutoTimer"
     * xTimerPeriodInTicks      pdMS_TO_TICKS( 1000 )
     * xAutoReload              pdTRUE
     * pvTimerID                ( void * ) 1
     * pxCallbackFunction       prvTimerCallback
     *
     * Assign the return value to xAutoReloadTimer.
     */

    configASSERT( xAutoReloadTimer != NULL );

    /*
     * TODO 2 - Create a one-shot timer with 100 ms period using xTimerCreate
     * API.
     *
     * Use the following values for xTimerCreate parameters:
     * pcTimerName              "OneTimer"
     * xTimerPeriodInTicks      pdMS_TO_TICKS( 100 )
     * xAutoReload              pdFALSE
     * pvTimerID                ( void * ) 2
     * pxCallbackFunction       prvTimerCallback
     *
     * Assign the return value to xOneShotTimer.
     */

    configASSERT( xOneShotTimer != NULL );

    /*
     * TODO 3 - Start the auto-reload timer using xTimerStart API.
     *
     * Use the following values for xTimerStart parameters:
     * xTimer           xAutoReloadTimer
     * xTicksToWait     0
     *
     * Assign the return value to xTimerStartResult.
     */

    configASSERT( xTimerStartResult == pdPASS );

    /*
     * TODO 4 - Start the one-shot timer using xTimerStart API.
     *
     * Use the following values for xTimerStart parameters:
     * xTimer           xOneShotTimer
     * xTicksToWait     0
     *
     * Assign the return value to xTimerStartResult.
     */

    configASSERT( xTimerStartResult == pdPASS );

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

static void prvTimerCallback( TimerHandle_t xTimer )
{
    fprintf( stderr, "Callback for Timer ID %p running...\r\n", pvTimerGetTimerID( xTimer ) );
}
/*-----------------------------------------------------------*/
