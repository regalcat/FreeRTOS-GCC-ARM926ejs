/*
 * LDFScheduler.c
 *
 *  Created on: Dec 7, 2016
 *      Author: mksolleveld
 */

/* Standard Stuff */
//#include <time.h>
#include <stddef.h>
/* FreeRTOS Stuff */
#include <FreeRTOS.h>
#include <task.h>

/* Our Stuff */
#include <LDFScheduler.h>
#include <print.h>
#include <app_config.h>

// K is the number of network interfaces
#define K   1
#define Q   0.8
// Number of packets that arrive for 
#define C1_INC  1
#define C2_INC  2
#define C3_INC  3

typedef struct{
    char * name;
    int deficit;
} connection;

static long holdrand = 1L;

static void srand(unsigned int seed) {
    holdrand = (long) seed;
}

static int rand() {
    return (((holdrand = holdrand * 214013L + 2531011L) >> 16) & 0x7fff);
}

void LDFSchedulerTask(void* params){

    /* Initialize the things */
    // Deficits
    connection c1;
    c1.name = "Connection 1\r\n";
    c1.deficit = 0;
    connection c2;
    c2.name = "Connection 2\r\n";
    c2.deficit = 0;
    connection c3;
    c3.name = "Connection 3\r\n";
    c3.deficit = 0;
    // Seed the random number number generator
    srand(1002);
    /* Do the receive stuff */
    int i=0;
    for(i=0; i<C1_INC; i++){
        if(rand()%10 < Q*10)
            c1.deficit++;
    }
    i=0;
    for(i=0; i<C2_INC; i++){
        if(rand()%10 < Q*10)
            c2.deficit++;
    }
    i=0;
    for(i=0; i<C3_INC; i++){
        if(rand()%10 < Q*10)
            c3.deficit++;
    }
    /* Schedule things */
    while(c1.deficit>0 || c2.deficit>0 || c3.deficit>0){
        // Find the largest deficit
        i=0;
        int arr[3] = {c1.deficit, c2.deficit, c3.deficit};
        int max = 0;
        int index = 0;
        for(i=0;i<3; i++){
            if(arr[i]> max){
                max = arr[i];
                index = i;
            }
        }
        
        // Send to printer
        if(index==0){
            c1.deficit--;
            vPrintMsg(c1.name);
        }
        if(index==1){
            c2.deficit--;
            vPrintMsg(c2.name);
        }
        if(index==2){
            c3.deficit--;
            vPrintMsg(c3.name);
        }
    }

    vTaskDelete(NULL);

    (void) params;
}
