#ifndef _WIFI_H_
#define _WIFI_H_

#include "Config.h"

//char * WiFi_Send_M;
//char * WiFi_Recv_M;

#define				ServerIP																	"192.168.0.1"
#define				ServerTCPPort															"6000"
#define				ServerUDPPort															6001
#define				ServerMySQLPort														3306
#define				WiFi_SSID																	"EmeraldDownStorage"
#define				WiFi_Password															"w20080811"

#define				Default_Connect_ID												10

int Init_WiFi(void);
int Init_Server_Con(ENUM_ID_NO_TypeDef ID);


#endif
