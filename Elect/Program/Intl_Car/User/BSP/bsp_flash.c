#include "Config.h"

static	__IO uint32_t		SPITimeout = SPIT_LONG_TIMEOUT;

/*
Function name:						SPI_FLASH_Init
Description	 :						Init SPI_FLASH
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_Init(void)
{
	SPI_InitTypeDef		SPI_InitStructure;
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	FLASH_SPI_APBxClockFUN( FLASH_SPI_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin   = FLASH_SPI_SCK_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(RLASH_SPI_SCK_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin   = FLASH_SPI_MOSI_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(FLASH_SPI_MOSI_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin   = FLASH_SPI_MISO_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(FLASH_SPI_MISO_PORT, &GPIO_InitStructure);
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode			= SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize	= SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL			= SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA			= SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS				=	SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
	SPI_InitStructure.SPI_FirstBit	= SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(FLASH_SPI1, &SPI_InitStructure);
	
	SPI_Cmd(FLASH_SPI1, ENABLE);
	
}

/*
Function name:						SPI_FLASH_SectorErase
Description	 :						Clean Flash Sector
Para				 :						-SectorAddr, Sector Address
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_SectorErase(u32 SectorAddr)
{
	
}

/*
Function name:						SPI_FLASH_WriteEnable
Description	 :						Enable to send Date to FLASH
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_WriteEnable(void)
{
	
}

u8 SPI_FLASH_ReadByte(void)
{
  return (SPI_FLASH_SendByte(Dummy_Byte));
}


u8 SPI_FLASH_SendByte(u8 byte)
{
	SPITimeout = SPIT_FLAG_TIMEOUT;
	
	while(SPI_I2S_GetFlagStatus(FLASH_SPI1, SPI_I2S_FLAG_TXE) == RESET)
	{
		
	}
	
}










