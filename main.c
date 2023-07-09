#include <stdio.h>
#include <stdlib.h>

/* Include Easy CANopen */
#include "Src/Easy_CANopen/Easy_CANopen.h"

int main() {
	/* Declare our structures  */
	CANopen master_node = { 0 };
	CANopen slave_node = { 0 };


	slave_node.slave.this_node_ID = 0x04;
	
	printf("\nTest SDO read uint32_t\n");
	slave_node.od_communication.device_type = 0x01020304;
	CANopen_Client_SDO_Transmit_Request(&master_node, CS_SDO_INITIATE_UPLOAD_REQUEST, 0x04, OD_INDEX_DEVICE_TYPE, 0, 0);
	Easy_CANopen_Thread_Listen_Messages(&slave_node);
	Easy_CANopen_Thread_Listen_Messages(&master_node);

	printf("\nTest SDO write uint32_t\n");
	CANopen_Client_SDO_Transmit_Request(&master_node, CS_SDO_INITIATE_DOWNLOAD_REQUEST, 0x04, OD_INDEX_DEVICE_TYPE, 0, 0xAA554425);
	Easy_CANopen_Thread_Listen_Messages(&slave_node);
	Easy_CANopen_Thread_Listen_Messages(&master_node);

	CANopen_Client_SDO_Transmit_Request(&master_node, CS_SDO_INITIATE_UPLOAD_REQUEST, 0x04, OD_INDEX_DEVICE_TYPE, 0, 0);
	Easy_CANopen_Thread_Listen_Messages(&slave_node);
	Easy_CANopen_Thread_Listen_Messages(&master_node);
	return 0;
}