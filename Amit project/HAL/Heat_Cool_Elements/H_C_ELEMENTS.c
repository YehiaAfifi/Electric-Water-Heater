/*
 * H_C_ELEMENTS.c
 *
 * Created: 2/4/2022 10:56:31 AM
 *  Author: pc
 */ 
#include "STD_MACROS.h"
#include "H_C_ELEMENTS.h"

void heater_init(void)
{
	set_bit(HEATER_PORT_DIR,HEATER_PIN);
}

void cooler_init(void)
{
	set_bit(COOLER_PORT_DIR,COOLER_PIN);
}



 
//to start the Heater 


void heater_on(void)
{
	set_bit(HEATER_PORT,HEATER_PIN);
}

//to start the Cooler.

void cooler_on(void)
{
	set_bit(COOLER_PORT,COOLER_PIN);
}



// to stop Heater 


void heater_off(void)
{
	clr_bit(HEATER_PORT,HEATER_PIN);
}


// to stop cooler


void cooler_off(void)
{
	clr_bit(COOLER_PORT,COOLER_PIN);
}