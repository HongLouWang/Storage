#include "Config.h"

uint8_t	unvarnishSendEnable = 0;


/*
Function name:						Init_WiFi
Description	 :						ESP8266 Init and Connect WiFi
Para				 :						NONE
Output			 :						NONE
Return			 :						-1, Connect successfully, no unvarnishSend
													-2, Connect successfully, unvarnishSend
													-3, fail to Connect
*/
int Init_WiFi()
{
	static char ssid[120]  = {WiFi_SSID};
	static char	pwd[120]   = {WiFi_Password};
	//ESP8266_Init();
	
	if(ESP8266_JoinAP(ssid, pwd))
	{
		if(ESP8266_UnvarnishSend())
		{
			return 2;
		}
		return 1;
	}
	else
	{
		return 3;
	}
}

int Init_Server_Con()
{
	ESP8266_Link_Server(enumTCP, ServerIP, "192.168.0.1", 10);
}



