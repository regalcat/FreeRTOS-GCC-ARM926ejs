/*
 * LDFDemo
 * @author Steff Bisinger and Megan Solleveld
 * This program uses the FreeRTOS Plus TCP code and a driver we found on
 * the Interwebs to recieve packets and schedule them. It simulates the
 * Largest Deficit First packet scheduling algorithm detailed 
 * here: http://www.public.asu.edu/~xkang6/index_files/khy15-1.pdf
 *
*/

/* Standard includes */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* FreeRTOS stuff */
#include "FreeRTOS.h"
#include "task.h"

/* FreeRTOS+TCP */
//#include "FreeRTOS_IP.h"
//#include "FreeRTOS_Sockets.h"

/* Our Stuff */
#include "app_config.h"
#include "print.h"
#include "LDFScheduler.h"

static void FreeRTOS_Error(const portCHAR* msg){
    if(msg!=NULL)
        vDirectPrintMsg(msg);

}

int main(void){
    
    /* Init the printer */
    if (pdFAIL == printInit(PRINT_UART_NR)){
        FreeRTOS_Error("Initialization of print failed\r\n");
    }
    
    vDirectPrintMsg("LDF Test\r\n\r\n");

    /* Create the gatekeeper */
    if(pdPASS!= xTaskCreate(printGateKeeperTask, "gk", 128, NULL,
                            PRIOR_PRINT_GATEKEEPR, NULL))
        FreeRTOS_Error("Oh no! We couldn't find the gatekeeper.\r\n");

    /* Create the LDF scheduler task */
    if(pdPASS!= xTaskCreate(LDFSchedulerTask, "ldfsched", 128, NULL,
                            PRIOR_LDF_SCHED, NULL))
        FreeRTOS_Error("Oh no! We couldn't find the scheduler.\r\n");

    /* Run all the things we created */
    vDirectPrintMsg("Starting LDF scheduler and helpers\r\n\r\n");
    vTaskStartScheduler();

    FreeRTOS_Error("Could not start the scheduler\r\n\r\n");

    return 0;
}
