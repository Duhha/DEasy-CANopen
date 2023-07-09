/*
 * Hardware_CAN.c
 *
 *  Created on: 11 juli 2021
 *      Author: Daniel Mårtensson
 */


#include "Hardware.h"

/* Platform independent library headers for CAN */
#if PROCESSOR_CHOICE == HARDWARE_INTERNAL
#include <stdio.h>
/* Internal fields */
static bool internal_new_message[256] = {false};
static uint8_t internal_data[256*8] = {0};
static uint16_t internal_COB_ID[256] = {0};
static uint8_t buffer_index_transmit = 0;
static uint8_t buffer_index_receive = 0;

/* Internal functions */
static STATUS_CODE Internal_Transmit(uint16_t COB_ID, uint8_t data[], uint8_t DLC) {
	printf("->: %03x|    ", COB_ID);
	internal_COB_ID[buffer_index_transmit] = COB_ID;

	for (uint8_t i = 0; i < 8; i++) {
		internal_data[buffer_index_transmit * 8 + i] = data[i];
		printf("%02x ", internal_data[buffer_index_transmit * 8 + i]);
	}
	printf("\n");
	internal_new_message[buffer_index_transmit] = true;
	buffer_index_transmit++;									/* When this is 256, then it will be come 0 again */
	return STATUS_CODE_SUCCESSFUL;
}

static void Internal_Receive(uint16_t *COB_ID, uint8_t data[], bool *is_new_message) {
	/* Do a quick check if we are going to read message that have no data */
	if(internal_new_message[buffer_index_receive] == false){
		*is_new_message = false;
		return;
	}

	*COB_ID = internal_COB_ID[buffer_index_receive];
	printf("<-: %03x|    ", *COB_ID);
	for (uint8_t i = 0; i < 8; i++) {
		data[i] = internal_data[buffer_index_receive * 8 + i];
		printf("%02x ", data[i]);
	}
	printf("\n");
	*is_new_message = internal_new_message[buffer_index_receive];
	/* Reset */
	internal_new_message[buffer_index_receive] = false;
	buffer_index_receive++;										/* When this is 256, then it will be come 0 again */
}


STATUS_CODE Hardware_CAN_Send_Message(uint16_t COB_ID, uint8_t data[]) {
	STATUS_CODE status;
	/* If no processor are used, use internal feedback for debugging */
	status = Internal_Transmit(COB_ID, data, 8);

	return status;
}

/* Read the current CAN-bus message. Returning false if the message has been read before, else true */
bool Hardware_CAN_Read_Message(uint16_t *COB_ID, uint8_t data[]) {
	bool is_new_message;
	/* If no processor are used, use internal feedback for debugging */
	Internal_Receive(COB_ID, data, &is_new_message);

	return is_new_message;
}

bool CAN_Set_Baud_Rate(uint8_t table_index){
	bool is_set = false;
	
	return is_set;
}

#endif
