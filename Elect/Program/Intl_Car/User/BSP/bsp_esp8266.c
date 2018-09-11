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





