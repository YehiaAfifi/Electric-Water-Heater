/*
 * Amitprojectf.c
 *
 * Created: 2/4/2022 10:49:33 AM
 * Author : pc
 */ 

#include <avr/io.h>


#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_MACROS.h"
#include "SYSTEM.h"



//ISR to switch between on and off states


ISR(INT2_vect)
{
	if(Current_state==OFF){
		Current_state = ON;
		desired_temp = EEPROM_read(0x0000);
	}
	else if (Current_state==ON || Current_state==SETTING){
		Current_state = OFF;
	}
}


//Timer1 ISR which triggers the interrupt every 100 ms which makes ADC Read


ISR(TIMER1_COMPA_vect)
{
	temp_measure_flag = 1;
}

/*
ISR triggers the interrupt every 1 second , to toggle the
toggle flag  and count to keep it in ON_STATE if nothing is pressed for 5 secs in the on and setting states.
*/

ISR(TIMER0_COMP_vect)
{
	if ((Current_state==SETTING) || (Current_state==ON)){
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_flag ^= 1;
		}
		if (setting_counter > 20){
			
			Current_state = ON;
		}
	}
}
//There is an error in the reading of the temp sensor and the displayed number on the seven segment


int main(void)
{
	
	system_init();
	
	while(1){
		switch (Current_state){
			case ON:{
				ON_SYS();
				break;
			}
			case OFF:{
				OFF_SYS();
				break;
			}
			case SETTING:{
				SET_SYS();
				break;
			}
		}
	}
}
