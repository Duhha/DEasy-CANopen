/*
 * Hardware_Time.c
 *
 *  Created on: 15 okt. 2021
 *      Author: Daniel Mårtensson
 */

#include "Hardware.h"

#if PROCESSOR_CHOICE == HARDWARE_INTERNAL

uint32_t Hardware_Time_Get_Tick(){
	/* Implement your time handler function for the AVR platform */
	return 0;
}

void Hardware_Time_Get_RTC(uint8_t *date, uint8_t *month, uint16_t *year, uint8_t *hour, uint8_t *minute, uint8_t *second){
	/* Implement your time handler function for the platform */
}

#endif
