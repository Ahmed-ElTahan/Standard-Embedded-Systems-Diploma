/*
 * RTOS_LAB1_ATMEGA32.c
 *
 * Created: 1/27/2014 12:22:11 AM
 *  Author: Islam
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
//#include "lcd_4bit.h"

#include <util/delay.h>

/* Define Tasks Priorities */
#define  TASK1_PRIORITY (3)
#define  TASK2_PRIORITY (3)

/*tasks codes prototypes */
 void task1_code(void*pvParamter);
 void task2_code(void*pvParamter);

int main(void)
{
	/*initialize LCD*/
	DDRA = 0xFF;
	//lcd_init();
	/*Creat tasks*/
	xTaskCreate(task1_code,NULL,85,NULL,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,NULL,configMINIMAL_STACK_SIZE,NULL,TASK2_PRIORITY,NULL);
	/*start Scheduler */
	vTaskStartScheduler();
	
	return 0;
    
}

/*Task1 Code */
 void task1_code(void*pvParamter)
{
	
	for (;;)
	{
		PORTA = 0xFF;
		//lcd_clrScreen();
		//lcd_dispString("I am Task 1");
		//_delay_ms(10000);
		//vTaskDelay(2000);
	}
		
}

/*Task 2 Code*/
 void task2_code(void*pvParamter)
{
	while(1)
	{
		PORTA = 0x00;
		//lcd_clrScreen();
		//lcd_dispString("I am Task 2");
		//_delay_ms(10000);
		//vTaskDelay(2000);
	}
}
