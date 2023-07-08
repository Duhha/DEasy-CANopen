#include <stdio.h>
#include <stdlib.h>

/* Include Easy CANopen */
#include "Src/Easy_CANopen/Easy_CANopen.h"

int main() {
	/* Declare our structures  */
	CANopen master_node = { 0 };
	CANopen slave_node = { 0 }; /* Notice that ONLY one slave node can be connected to the CAN network */

	/* Begin to activate node configuration so we can write our node ID */
	Easy_CANopen_Other_Node_Activate_Node_Configuration(true);

	/* Reading process for the slave node */
	Easy_CANopen_Thread_Listen_Messages(&slave_node);


	slave_node.slave.this_node_ID = 0x04;
//	CANopen_Client_SDO_Transmit_Request(&master_node, MODE_READ, 0x04, OD_INDEX_IDENTITY_OBJECT, 0, 0);
//	Easy_CANopen_Thread_Listen_Messages(&slave_node);
//	Easy_CANopen_Thread_Listen_Messages(&master_node);
	uint8_t data[8] = {0x40, 0x18, 0x10, 0x00, 0, 0, 0, 0};
	//Hardware_CAN_Send_Message(0x604, data);
	CANopen_Client_SDO_Transmit_Request(&master_node, CS_SDO_INITIATE_UPLOAD_REQUEST, 0x04, OD_INDEX_IDENTITY_OBJECT, 0, 0);
	Easy_CANopen_Thread_Listen_Messages(&slave_node);
	return 0;
}