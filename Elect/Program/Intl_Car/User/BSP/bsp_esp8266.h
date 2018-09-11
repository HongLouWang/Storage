#ifndef		__BSP_ESP8266_H_
#define		__BSP_ESP8266_H_

#include "Config.h"

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

typedef enum{
	STA,
	AP,
	STA_AP
}ENUM_Net_ModeTypeDef;

typedef enum{
	 enumTCP,
	 enumUDP,
} ENUM_NetPro_TypeDef;

typedef enum{
	Multiple_ID_0 = 0,
	Multiple_ID_1 = 1,
	Multiple_ID_2 = 2,
	Multiple_ID_3 = 3,
	Multiple_ID_4 = 4,
	Single_ID_0 = 5,
} ENUM_ID_NO_TypeDef;

typedef enum{
	OPEN = 0,
	WEP = 1,
	WPA_PSK = 2,
	WPA2_PSK = 3,
	WPA_WPA2_PSK = 4,
} ENUM_AP_PsdMode_TypeDef;

/******************************* ESP8266 外部全局变量声明 ***************************/
#define RX_BUF_MAX_LEN										2048

extern struct STRUCT_USARTx_Fram
{
	char Data_RX_BUF [RX_BUF_MAX_LEN];
	union
	{
		__IO u16 InfAll;
		struct{
			__IO u16 FramLength								:15;
			__IO u16 FramFinishFlag						:1;
		}Infbit;
		
	};
}	strEsp8266_Fram_Record;

/*********************************************** ESP8266 函数宏定义 *******************************************/
#define				macESP8266_CH_PD_CLK											RCC_APB2Periph_GPIOD
#define 			macESP8266_CH_PD_PORT											GPIOD
#define				macESP8266_CH_PD_PIN											GPIO_Pin_8

#define				macESP8266_CH_RST_CLK											RCC_APV2Periph_GPIOD
#define				macESP8266_CH_RST_PORT										GPIOD
#define				macESP8266_CH_RST_PIN											GPIO_Pin_7

#define				macESP8266_USART_BAUD_RAT									115200

#define				macESP8266_USARTX													USART3
#define				macESP8255_USART_APVxClock_FUN						RCC_APN1PeriphClockCmd
#define				macESP8266_USART_CLK											RCC_APB1Periph_USART3
#define       macESP8266_USART_GPIO_APBxClock_FUN       RCC_APB2PeriphClockCmd
#define       macESP8266_USART_GPIO_CLK                 RCC_APB2Periph_GPIOD
#define				macESP8266_USART_TX_PORT									GPIOD
#define				macESP8266_USART_TX_PIN										GPIO_Pin_9
#define				macESP8266_USART_RX_PORT									GPIOD
#define				macESP8266_USART_RX_PIN										GPIO_Pin_10
#define       macESP8266_USART_IRQ                      USART3_IRQn
#define       macESP8266_USART_INT_FUN                  USART3_IRQHandler

/*********************************************** ESP8266 函数宏定义 *******************************************/
#define				macESP8266_Usart( fmt, ... )							USART_printf( macESP8266_USARTx, fmt, ##__VA_ARGS__ )
#define       macPC_Usart( fmt, ... )                

#define    		macESP8266_CH_ENABLE()                 		GPIO_SetBits ( macESP8266_CH_PD_PORT, macESP8266_CH_PD_PIN )
#define     	macESP8266_CH_DISABLE()                		GPIO_ResetBits ( macESP8266_CH_PD_PORT, macESP8266_CH_PD_PIN )

#define     	macESP8266_RST_HIGH_LEVEL()            		GPIO_SetBits ( macESP8266_RST_PORT, macESP8266_RST_PIN )
#define    		macESP8266_RST_LOW_LEVEL()             		GPIO_ResetBits ( macESP8266_RST_PORT, macESP8266_RST_PIN )

static char * itoa( int value, char *string, int radix );








#endif

