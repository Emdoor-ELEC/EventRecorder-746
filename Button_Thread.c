#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "Board_Buttons.h"
#include "Board_LED.h"
#include "EventRecorder.h"
#include "main.h"
/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
osThreadId_t tid_ButtonThread;                        // thread id
 
void ButtonThread (void *argument);                   // thread function
 
int Init_ButtonThread (void) {
 
  tid_ButtonThread = osThreadNew(ButtonThread, NULL, NULL);
  if (tid_ButtonThread == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void ButtonThread (void *argument) {
	
	int Button_status = 0;
	int some_error;
  while (1) {
		Button_status=Buttons_GetState();
		if(Button_status)
		{
			LED_On(0);
		  MyFunction (0x10);
		  some_error = 1;                               // set error flag
		  MyFunction (0x60);
		}
		else
			LED_Off(0);
			
    ; // Insert thread code here...
    osThreadYield();                            // suspend thread
  }
}
