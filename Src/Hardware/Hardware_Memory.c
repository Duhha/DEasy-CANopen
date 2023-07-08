/*
 * Hardware_Memory.c
 *
 *  Created on: 22 sep. 2021
 *      Author: Daniel Mårtensson
 */

#include "Hardware.h"

#if PROCESSOR_CHOICE == HARDWARE_INTERNAL

bool Hardware_Memory_Save_Bytes(uint8_t data[], uint32_t data_length, char file_name[]){

	/* Implement your memory handler function for your platform */

	return true;
}

bool Hardware_Memory_Load_Bytes(uint8_t data[], uint32_t data_length, char file_name[]){
	/* Implement your memory handler function for your platform */

	return true;
}

#endif
