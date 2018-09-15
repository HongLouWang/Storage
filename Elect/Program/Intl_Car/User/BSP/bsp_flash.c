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
Description	 :						Clean Flash Sector Address
Para				 :						-SectorAddr, Sector Address
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_SectorErase(u32 SectorAddr)
{
	SPI_FLASH_WriteEnable();
  SPI_FLASH_WaitForWriteEnd();
	
	SPI_FLASH_SendByte(W25X_SectorErase);
	SPI_FLASH_SendByte((SectorAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((SectorAddr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(SectorAddr & 0xFF);
	
	SPI_FLASH_WaitForWriteEnd();
}

/*
Function name:						SPI_FLASH_BulkRease
Description	 :						Clean All Flash Sector
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_BulkRease(void)
{
	SPI_FLASH_WriteEnable();
	
	SPI_FLASH_SendByte(W25X_ChipErase);
	
	SPI_FLASH_WaitForWriteEnd(); 
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
	SPI_FLASH_SendByte(W25X_WriteEnable);
}

/*
Function name:						SPI_FLASH_ReadByte
Description	 :						Send a bit to FLASH
Para				 :						-byte, data need to be send
Output			 :						NONE
Return			 :						Received Date
*/
u8 SPI_FLASH_ReadByte(void)
{
  return (SPI_FLASH_SendByte(Dummy_Byte));
}

/*
Function name:						SPI_FLASH_SendByte
Description	 :						Send a bit to FLASH
Para				 :						-byte, data need to be send
Output			 :						NONE
Return			 :						Received Date
*/
u8 SPI_FLASH_SendByte(u8 byte)
{
	SPITimeout = SPIT_FLAG_TIMEOUT;
	
	while(SPI_I2S_GetFlagStatus(FLASH_SPI1, SPI_I2S_FLAG_TXE) == RESET)
	{
		if((SPITimeout--) == 0)
		{
			return 0;
		}
	}
	
	SPI_I2S_SendData(FLASH_SPI1, byte);
	
	SPITimeout = SPIT_FLAG_TIMEOUT;
	
	while(SPI_I2S_GetFlagStatus(FLASH_SPI1, SPI_I2S_FLAG_RXNE) == RESET)
	{
		if((SPITimeout--) == 0)
		{
			return 0;
		}
	}
	
	return SPI_I2S_ReceiveData(FLASH_SPI1);
	
}

void SPI_FLASH_WaitForWriteEnd(void)
{
	u8 FLASH_Status = 0;
	
	SPI_FLASH_SendByte(W25X_ReadStatusReg);
	
	do
	{
		FLASH_Status = SPI_FLASH_SendByte(Dummy_Byte);
	}
	while((FLASH_Status & WIP_Flag) == SET);
	
}










