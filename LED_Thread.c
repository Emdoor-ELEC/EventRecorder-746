#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "Board_Buttons.h"
#include "Board_LED.h"
#include "EventRecorder.h"
#include "main.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
osThreadId_t tid_Thread;                        // thread id
 
void LEDThread (void *argument);                   // thread function
 
int Init_LEDThread (void) {
 
  tid_Thread = osThreadNew(LEDThread, NULL, NULL);
  if (tid_Thread == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void LEDThread (void *argument) {
 
  while (1) {
    ; // Insert thread code here...
		EventStartA(0);
		LED_Off(0);
		osDelay(1000U);
		
		LED_On(0);
		osDelay(1000U);
		EventStopA(0);
		
    osThreadYield();                            // suspend thread
  }
}
