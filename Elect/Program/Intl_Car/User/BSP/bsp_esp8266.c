#include "Config.h"

#define TRYCOUNT   10
struct  STRUCT_USARTx_Fram strEsp8266_Fram_Record = { 0 };

/*
Function name:						USART_printf
Description	 :						Same as printf in C
Para				 :						--USARTx		Name of the USART port
													--Data			The vector of the date which need to transit
													--...				Other para
Output			 :						NONE
Return			 :						NONE
*/

void USART_printf(USART_TypeDef * USARTx, char * Data, ... )
{
	const char *s;
	int d;
	char buf[16];
	
	va_list ap;
	va_start(ap,Data);
	
	while(*Data != 0)
	{
		if ( * Data == 0x5c )
		{
			switch ( *++Data )
			{
				case 'r':
					USART_SendData(USARTx, 0x0d);
					Data ++;
					break;
				case 'n':
					USART_SendData(USARTx, 0x0a);
					Data ++;
					break;
				default:
					Data ++;
					break;
			}
		}
		else if (* Data == '%')
		{
			switch (*++Data)
			{
				case 's':
					s = va_arg(ap, const char *);
					for( ; *s; s++)
					{
						USART_SendData(USARTx, *s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
					}
					Data ++;
					break;
					
				case 'd':
					d = va_arg(ap, int);	
					itoa(d, buf, 10);
					for (s = buf; *s; s++)
					{
						USART_SendData(USARTx, *s);
						while( USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
					}
					Data ++;
					break;
				default:
					Data ++;
					break;
			}
		}
		else USART_SendData(USARTx, *Data++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
			
	}
}

/*
Function name:						itoa
Description	 :						Switch int into string
Para				 :						--radix = 10		Decimal
													--value					The number need to be change
													--buf						The string after change
													--radix = 10
Output			 :						NONE
Return			 :						NONE					
*/
static char * itoa( int value, char *string, int radix )
{
	int		i,d;
	int		flag = 0;
	char	*ptr = string;
	
	/* This implementation only works for decimal numbers. */
	if(radix != 10)
	{
		*ptr = 0;
		return string;
	}
	if(!value)
	{
		*ptr++ = 0x30;
		*ptr = 0;
		return string;
	}
	
	/* if this is a negative value insert the minus sign. */
	if(value < 0)
	{
		*ptr++ = '-';
		value *= -1;
	}
	for(i = 10000; i > 0; i/= 10)
	{
		d = value / i;
		if(d || flag)
		{
			*ptr++ = (char)(d + 0x30);
			value -= (d * i);
			flag = 1;
		}
	}
	
	/* Null terminate the string. */
	*ptr = 0;
	return string;
	
}

/*
Function name:						ESP8266_Init
Description	 :						Init ESP8266
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE					
*/

void ESP8266_Init( void )
{
	ESP8266_GPIO_Config ();	
	ESP8266_USART_Config();
	macESP8266_RST_HIGH_LEVEL();
}

/*
Function name:						ESP8266_GPIO_Config
Description	 :						Init ESP8266 GPIO
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE					
*/
static void ESP8266_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(macESP8266_CH_PD_CLK | macESP8266_RST_CLK, ENABLE);
	
	//Config CH_PD Port
	GPIO_InitStructure.GPIO_Pin	    = macESP8266_CH_PD_PIN;
	GPIO_InitStructure.GPIO_Mode	  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(macESP8266_CH_PD_PORT, & GPIO_InitStructure);
	
	//Config RST Port
	GPIO_InitStructure.GPIO_Pin			= macESP8266_RST_PIN;
	GPIO_Init(macESP8266_RST_PORT, & GPIO_InitStructure);
}

/*
Function name:						ESP8266_USART_Config
Description	 :						Init ESP8266 USART
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE					
*/
static void ESP8266_USART_Config ( void )
{
	GPIO_InitTypeDef		GPIO_InitStructure;
	USART_InitTypeDef		USART_InitStructure;
	
	//Config USART Clock
	macESP8266_USART_APBxClock_FUN( macESP8266_USART_CLK, ENABLE);
	macESP8266_USART_GPIO_APBxClock_FUN (macESP8266_USART_GPIO_CLK, ENABLE);
	
	//USART GPIO Config
	// Configure USART Tx as alternate function push-pull
	GPIO_InitStructure.GPIO_Pin		=		macESP8266_USART_TX_PIN;
	GPIO_InitStructure.GPIO_Mode	=		GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = 	GPIO_Speed_50MHz;
	GPIO_Init(macESP8266_USART_TX_PORT, & GPIO_InitStructure);
	
	// Configure USART Rx as input floating
	GPIO_InitStructure.GPIO_Pin 	=		macESP8266_USART_RX_PIN;
	GPIO_InitStructure.GPIO_Mode	=		GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed	=		GPIO_Speed_50MHz;
	GPIO_Init(macESP8266_USART_RX_PORT, &GPIO_InitStructure);
	
	// USART1 mode config
	USART_InitStructure.USART_BaudRate		=		macESP8266_USART_BAUD_RATE;
	USART_InitStructure.USART_WordLength	=		USART_WordLength_8b;
	USART_InitStructure.USART_StopBits		=		USART_StopBits_1;
	USART_InitStructure.USART_Parity			=		USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl		=		USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode				=		USART_Mode_Rx	| USART_Mode_Tx;
	USART_Init(macESP8266_USARTx, &USART_InitStructure);
	
	//Interrupt
	USART_ITConfig( macESP8266_USARTx, USART_IT_RXNE, ENABLE );
	USART_ITConfig( macESP8266_USARTx, USART_IT_IDLE, ENABLE);
	
	ESP8266_USART_NVIC_Configuration();
	
	USART_Cmd(macESP8266_USARTx, ENABLE);
	
}

/*
Function name:						ESP8266_USART_NVIC_Configuration
Description	 :						Config NVIC Interrupt
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE					
*/
static void ESP8266_USART_NVIC_Configuration ( void )
{
	NVIC_InitTypeDef		NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = macESP8266_USART_IRQ;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}

/*
Function name:						ESP8266_Rst
Description	 :						Restart Wifi_ESP8266
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE					
*/
void ESP8266_Rst( void )
{
	#if 0
	ESP8266_Cmd("AT+RST", "OK", "ready", 2500);
	#else
	macESP8266_RST_LOW_LEVEL();
	Delay(500);
	macESP8266_RST_HIGH_LEVEL();
	#endif
}

/*
Function name:						ESP8266_Cmd
Description	 :						Send Command to Wifi-ESP8266
Para				 :						-cmd, Command
													-reply1, -reply2, response time
													-waiting,	waiting time
Output			 :						NONE
Return			 :						1, send data successfully
													0, send data fail
*/
bool ESP8266_Cmd( char * cmd, char * reply1, char * reply2, u32 waittime)
{
	strEsp8266_Fram_Record.InfBit.FramLength = 0;
	
	macESP8266_Usart ( "%s\r\n", cmd );
	
	if((reply1 == 0) && (reply2 == 0))				//if no data to send
	{
		return true;
	}
	
	Delay(waittime);
	
	strEsp8266_Fram_Record .Data_RX_BUF [ strEsp8266_Fram_Record .InfBit .FramLength ]  = '\0';
	
	macPC_Usart ( "%s", strEsp8266_Fram_Record .Data_RX_BUF );
	
	if ( ( reply1 != 0 ) && ( reply2 != 0 ) )
		return ( ( bool ) strstr ( strEsp8266_Fram_Record .Data_RX_BUF, reply1 ) || 
						 ( bool ) strstr ( strEsp8266_Fram_Record .Data_RX_BUF, reply2 ) ); 
 	
	else if ( reply1 != 0 )
		return ( ( bool ) strstr ( strEsp8266_Fram_Record .Data_RX_BUF, reply1 ) );
	
	else
		return ( ( bool ) strstr ( strEsp8266_Fram_Record .Data_RX_BUF, reply2 ) );
	
}

/*
Function name:						ESP8266_AT_Test
Description	 :						Test for ESP8266 if ready
Para				 :						NONE
Return			 :						1, Ready
													0, noReady
*/
bool ESP8266_AT_Test(void)
{
	char count = 0;
	
	macESP8266_RST_HIGH_LEVEL();
	Delay(1000);
	while(count < TRYCOUNT)
	{
		if(ESP8266_Cmd("AT","OK",NULL,500)) return 1;
			ESP8266_Rst();
		count++;
	}
	return 0;
}

/*
Function name:						ESP8266_Net_Mode_Choose
Description	 :						Choose ESP8266 Working Mode
Para				 :						-enumMode,	Working mode
Output			 :						NONE
Return			 :						1, Sellect successfully
													0, Sellect fail
*/
bool ESP8266_Net_Mode_Choose( ENUM_Net_ModeTypeDef enumMode)
{
	bool result = 0;
	char count = 0;
	while(count < TRYCOUNT)
	{
		switch( enumMode)
		{
			case STA:
				result = ESP8266_Cmd("AT+CWMODE=1","OK","no change", 2500);
			break;
			case AP:
				result = ESP8266_Cmd("AT+CWMODE=2","OK","no change", 2500);
			break;
			case STA_AP:
				result = ESP8266_Cmd("AT+CWMODE=3","OK","no change", 2500);
			break;
			default:
				result = false;
			break;
		}
		if(result) return result;
		++count;
	}
	return 0;
}

/*
Function name:						ESP8266_JoinAP
Description	 :						ESP8266 Connect to WiFi
Para				 :						-pSSID,	SSID of WiFi
													-pPassWord,	Password of WiFi
Output			 :						NONE
Return			 :						1, Connect successfully
													0, Connect fail
*/
bool ESP8266_JoinAP( char * pSSID, char * pPassWord)
{
	char cCmd[120];
	sprintf ( cCmd, "AT+CWJAP=\"%s\",\"%s\"", pSSID, pPassWord );
	if(ESP8266_Cmd(cCmd, "OK", NULL, 5000))
	{
		return 1;
	}
	return 0;
}

/*
Function name:						ESP8266_BuildAP
Description	 :						ESP8266 Create WiFi hotpoint
Para				 :						-pSSID,	SSID of WiFi
													-pPassWord,	Password of WiFi
													-enumPadMode, encrypt mode
Output			 :						NONE
Return			 :						1, Connect successfully
													0, Connect fail
*/
bool ESP8266_BuildAP ( char * pSSID, char * pPassWord, ENUM_AP_PsdMode_TypeDef enunPsdMode )
{
	char cCmd[120];
	char count = 0;
	sprintf ( cCmd, "AT+CWSAP=\"%s\",\"%s\",1,%d", pSSID, pPassWord, enunPsdMode );
	while(count < TRYCOUNT)
	{
		if(ESP8266_Cmd(cCmd, "OK", 0, 1000))
		{
			return 1;
		}
		++count;
	}
	return 0;
}

/*
Function name:						ESP8266_Enable_MultipleId
Description	 :						ESP8266 set up multiple connection
Para				 :						-enumEnUnvarnishTx, enable multiple connection
Output			 :						NONE
Return			 :						1, Connect successfully
													0, Connect fail
*/
bool ESP8266_Enable_MultipleId( FunctionalState enumEnUnvarnishTx)
{
	char cStr[20];
	sprintf ( cStr, "AT+CIPMUX=%d", ( enumEnUnvarnishTx ? 1 : 0 ) );
	if(ESP8266_Cmd(cStr, "OK", 0, 500))
	{
		return 1;
	}
	return 0;
}

/*
Function name:						ESP8266_Link_Server
Description	 :						ESP8266 Connect to outside server
Para				 :						-enumE, Network protocol
													-ip, Server IP
													-ComNum, Server Port
													-id, Server ID
Output			 :						NONE
Return			 :						1, Connect successfully
													0, Connect fail
*/
bool ESP8266_Link_Server(ENUM_NetPro_TypeDef enumE, char * ip, char * ComNum, ENUM_ID_NO_TypeDef id)
{
	char cStr[100] = { 0 }, cCmd[120];
	
	switch( enumE)
	{
		case enumTCP:
			sprintf ( cStr, "\"%s\",\"%s\",%s", "TCP", ip, ComNum );
		break;
		case enumUDP:
			sprintf ( cStr, "\"%s\",\"%s\",%s", "UDP", ip, ComNum );
		break;
		default:
			break;
	}
}












