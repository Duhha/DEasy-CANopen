cmake_minimum_required(VERSION 3.0) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.
project(test_canopen LANGUAGES C)

set(SOURCE main.c 
            Src/CANopen/EMCY/EMCY_Internal/EMCY_Protocol/CANopen_EMCY_Protocol_Produce.c
            Src/CANopen/EMCY/EMCY_Internal/EMCY_Protocol/CANopen_EMCY_Protocol_Consume.c
            Src/CANopen/EMCY/EMCY_Internal/CANopen_Producer_EMCY_Transmit.c
            Src/CANopen/EMCY/EMCY_Internal/CANopen_Consumer_EMCY_Receive.c
            Src/CANopen/GUARD/GUARD_Internal/GUARD_Protocol/CANopen_GUARD_Protocol_Transmit_Response.c
            Src/CANopen/GUARD/GUARD_Internal/GUARD_Protocol/CANopen_GUARD_Protocol_Transmit_Request.c
            Src/CANopen/GUARD/GUARD_Internal/GUARD_Protocol/CANopen_GUARD_Protocol_Receive_Response.c
            Src/CANopen/GUARD/GUARD_Internal/GUARD_Protocol/CANopen_GUARD_Protocol_Receive_Response.c
            Src/CANopen/GUARD/GUARD_Internal/GUARD_Protocol/CANopen_GUARD_Protocol_Receive_Request.c
            Src/CANopen/GUARD/GUARD_Internal/CANopen_Server_GUARD_Transmit.c
            Src/CANopen/GUARD/GUARD_Internal/CANopen_Server_GUARD_Receive.c
            Src/CANopen/GUARD/GUARD_Internal/CANopen_Client_GUARD_Receive.c
            Src/CANopen/GUARD/GUARD_User/CANopen_Client_GUARD_Transmit.c
            Src/CANopen/HEARTBEAT/HEARTBEAT_Internal/HEARTBEAT_Protocol/CANopen_HEARTBEAT_Protocol_Produce.c
            Src/CANopen/HEARTBEAT/HEARTBEAT_Internal/HEARTBEAT_Protocol/CANopen_HEARTBEAT_Protocol_Consume.c
            Src/CANopen/HEARTBEAT/HEARTBEAT_Internal/CANopen_Producer_HEARTBEAT_Transmit.c
            Src/CANopen/HEARTBEAT/HEARTBEAT_Internal/CANopen_Consumer_HEARTBEAT_Receive.c
            Src/CANopen/LSS/LSS_Internal/LSS_Protocol/CANopen_LSS_Protocol_Transmit_Response.c
            Src/CANopen/LSS/LSS_Internal/LSS_Protocol/CANopen_LSS_Protocol_Transmit_Request.c
            Src/CANopen/LSS/LSS_Internal/LSS_Protocol/CANopen_LSS_Protocol_Receive_Response.c
            Src/CANopen/LSS/LSS_Internal/LSS_Protocol/CANopen_LSS_Protocol_Receive_Request.c
            Src/CANopen/LSS/LSS_Internal/CANopen_Slave_LSS_Transmit.c
            Src/CANopen/LSS/LSS_Internal/CANopen_Slave_LSS_Receive.c
            Src/CANopen/LSS/LSS_Internal/CANopen_Master_LSS_Receive.c
            Src/CANopen/LSS/LSS_User/CANopen_Master_LSS_Transmit.c
            Src/CANopen/NMT/NMT_Internal/NMT_Protocol/CANopen_NMT_Protocol_Transmit_Request.c
            Src/CANopen/NMT/NMT_Internal/NMT_Protocol/CANopen_NMT_Protocol_Receive_Request.c
            Src/CANopen/NMT/NMT_Internal/CANopen_Slave_NMT_Receive.c
            Src/CANopen/NMT/NMT_User/CANopen_Master_NMT_Transmit.c
            Src/CANopen/OD/CANopen_OD.c
            Src/CANopen/PDO/PDO_Internal/PDO_Protocol/CANopen_PDO_Protocol_Produce.c
            Src/CANopen/PDO/PDO_Internal/PDO_Protocol/CANopen_PDO_Protocol_Consume.c
            Src/CANopen/PDO/PDO_Internal/CANopen_Producer_PDO_Transmit.c
            Src/CANopen/PDO/PDO_Internal/CANopen_Producer_PDO_Receive.c
            Src/CANopen/PDO/PDO_Internal/CANopen_Consumer_PDO_Receive.c
            Src/CANopen/PDO/PDO_User/CANopen_Consumer_PDO_Transmit.c
            Src/CANopen/SDO/SDO_Internal/SDO_Protocol/CANopen_SDO_Protocol_Transmit_Response.c
            Src/CANopen/SDO/SDO_Internal/SDO_Protocol/CANopen_SDO_Protocol_Transmit_Request.c
            Src/CANopen/SDO/SDO_Internal/SDO_Protocol/CANopen_SDO_Protocol_Receive_Response.c
            Src/CANopen/SDO/SDO_Internal/SDO_Protocol/CANopen_SDO_Protocol_Receive_Request.c
            Src/CANopen/SDO/SDO_Internal/CANopen_Server_SDO_Transmit.c
            Src/CANopen/SDO/SDO_Internal/CANopen_Server_SDO_Receive.c
            Src/CANopen/SDO/SDO_Internal/CANopen_Client_SDO_Receive.c
            Src/CANopen/SDO/SDO_User/CANopen_Client_SDO_Transmit.c
            Src/CANopen/SYNC/SYNC_Internal/SYNC_Protocol/CANopen_SYNC_Protocol_Produce.c
            Src/CANopen/SYNC/SYNC_Internal/SYNC_Protocol/CANopen_SYNC_Protocol_Consume.c
            Src/CANopen/SYNC/SYNC_Internal/CANopen_Producer_SYNC_Transmit.c
            Src/CANopen/SYNC/SYNC_Internal/CANopen_Consumer_SYNC_Receive.c
            Src/CANopen/TIME/TIME_Internal/TIME_Protocol/CANopen_TIME_Protocol_Produce.c
            Src/CANopen/TIME/TIME_Internal/TIME_Protocol/CANopen_TIME_Protocol_Consume.c
            Src/CANopen/TIME/TIME_Internal/CANopen_Producer_TIME_Transmit.c
            Src/CANopen/TIME/TIME_Internal/CANopen_Consumer_TIME_Receive.c
            Src/Easy_CANopen/Easy_CANopen_Thread.c
            Src/Easy_CANopen/Easy_CANopen_This_Node.c
            Src/Easy_CANopen/Easy_CANopen_Other_Node.c
            Src/Hardware/Hardware_Time.c
            Src/Hardware/Hardware_Memory.c
            Src/Hardware/Hardware_CAN.c)
#set(HEADER main.h
#            foo.h)

add_executable(main ${SOURCE})		# Создает исполняемый файл с именем main
									# из исходника main.cpp