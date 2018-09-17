#ifndef		_BSP_SPI_H_
#define		_BSP_SPI_H_

//				SPI1																			W25Q256				
#define		FLASH_SPI1																SPI1
#define		FLASH_SPI_APBxClockFUN										RCC_APB2PeriphClockCmd
#define		FLASH_SPI_CLK															RCC_APB2Periph_SPI1

#define		FLASH_SPI_CS_APBxClock_FUN								RCC_APB2PeriphClockCmd
#define		FLASH_SPI_CS_CLK_PORT											RCC_APB2Periph_GPIO

#define		FLASH_SPI_SCK_APBxClock_FUN								RCC_APB2PeriphClockCmd
#define		FLASH_SPI_SCK_CLK													RCC_APB2Periph_GPIOD
#define		RLASH_SPI_SCK_PORT												GPIOD
#define		FLASH_SPI_SCK_PIN													GPIO_Pin_2						//CLK

#define		FLASH_SPI_MOSI_APBxClock_FUN							RCC_APB2PeriphClockCmd	
#define		FLASH_SPI_MOSI_CLK												RCC_APB2Periph_GPIOD
#define		FLASH_SPI_MOSI_PORT												GPIOD
#define		FLASH_SPI_MOSI_PIN												GPIO_Pin_0						//DO

#define		FLASH_SPI_MISO_APBxClock_FUN							RCC_APB2PeriphClockCmd
#define		FLASH_SPI_MISO_CLK												RCC_APB2Periph_GPIOD
#define		FLASH_SPI_MISO_PORT												GPIOD
#define		FLASH_SPI_MISO_PIN												GPIO_Pin_1						//DI

//				SPI2																			IRControl

#define		FLASH_SPI2																SPI2	
#define		FLASH_SPI2_APBxClockFUN										RCC_APB1PeriphClockCmd
#define		FLASH_SPI2_CLK														RCC_APB1Periph_SPI2

#define		FLASH_SPI2_CS_APBxClock_FUN								RCC_APB1PeriphClockCmd
#define		FLASH_SPI2_CS_CLK_PORT										RCC_APB1Periph_GPIO

#define		FLASH_SPI2_SCK_APBxClock_FUN							RCC_APB1PeriphClockCmd
#define		FLASH_SPI2_SCK_CLK												RCC_APB1Periph_GPIOD
#define		RLASH_SPI2_SCK_PORT												GPIOD
#define		FLASH_SPI2_SCK_PIN												GPIO_Pin_11						

#define		FLASH_SPI2_MOSI_APBxClock_FUN							RCC_APB1PeriphClockCmd	
#define		FLASH_SPI2_MOSI_CLK												RCC_APB1Periph_GPIOD
#define		FLASH_SPI2_MOSI_PORT											GPIOD
#define		FLASH_SPI2_MOSI_PIN												GPIO_Pin_12						

#define		FLASH_SPI2_MISO_APBxClock_FUN							RCC_APB1PeriphClockCmd
#define		FLASH_SPI2_MISO_CLK												RCC_APB1Periph_GPIOD
#define		FLASH_SPI2_MISO_PORT											GPIOD
#define		FLASH_SPI2_MISO_PIN												GPIO_Pin_13						





#endif
