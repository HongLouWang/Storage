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
Function name:						SPI_FLASH_PageWrite
Description	 :						Write FLASH by Page, need to erease page first
Para				 :						-pBuffer,	point need to be write
													-Write Address,	Address
													-NumByteToWrite, lenth of date, must less than SPI_FLASH_PerWritePageSize
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_PageWrite(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	SPI_FLASH_WriteEnable();
	SPI_FLASH_SendByte(W25X_PageProgram);
	SPI_FLASH_SendByte((WriteAddr & 0XFF0000) >> 16);
	SPI_FLASH_SendByte((WriteAddr) & 0xFF00 >> 8);
	SPI_FLASH_SendByte(WriteAddr & 0xFF);
	
	if(NumByteToWrite > SPI_FLASH_PerWritePageSize)
	{
		NumByteToWrite = SPI_FLASH_PerWritePageSize;
	}
	
	while(NumByteToWrite--)
	{
		SPI_FLASH_SendByte(*pBuffer);
		pBuffer++;
	}
	
	SPI_FLASH_WaitForWriteEnd();
	
}

/*
Function name:						SPI_FLASH_BufferWrite
Description	 :						Write data to page
Para				 :						-pBuffer,	point need to be write
													-WriteAddr, Address need to be write
													-NumByteToWrite, Length of the Date
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_BufferWrite(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite)
{
	u8 NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;
	
	Addr = WriteAddr & SPI_FLASH_PageSize;
	
	count = SPI_FLASH_PageSize - Addr;
	
	NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
	
	NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;
	
	if(Addr == 0)
	{
		if(NumOfPage == 0)
		{
			SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
		}
		else
		{
			while(NumOfPage--)
			{
				SPI_FLASH_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
				WriteAddr	+=	SPI_FLASH_PageSize;
				pBuffer		+=	SPI_FLASH_PageSize;
			}
			SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumOfSingle);
		}
	}
	else
	{
		if(NumOfPage == 0)
		{
			if(NumOfSingle > count)
			{
				temp = NumOfSingle - count;
				SPI_FLASH_PageWrite(pBuffer, WriteAddr, count);
				
				WriteAddr += count;
				pBuffer   += count;
				
				SPI_FLASH_PageWrite(pBuffer, WriteAddr, temp);
			}
			else
			{
				SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
			}
		}
		else
		{
			NumByteToWrite -= count;
      NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
      NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;
			
			SPI_FLASH_PageWrite(pBuffer, WriteAddr, count);
			
			WriteAddr += count;
			pBuffer   += count;
			
			while(NumOfPage--)
			{
				SPI_FLASH_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
				WriteAddr	+=	SPI_FLASH_PageSize;
				pBuffer		+=	SPI_FLASH_PageSize;
			}
			
			if(NumOfSingle != 0)
			{
				SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumOfSingle);
			}
		}
	}
}

/*
Function name:						SPI_FLASH_BufferRead
Description	 :						Read FLASH Data
Para				 :						-pBuffer, Data point
													-ReadAddr, the address need to be read
													-NumByteToRead, length of the Data need to be read
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_BufferRead(u8* pBuffer, u32 ReadAddr, u16 NumByteToRead)
{
	SPI_FLASH_SendByte(W25X_ReadData);
	
	SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
	
	SPI_FLASH_SendByte((ReadAddr& 0xFF00) >> 8);
	
	SPI_FLASH_SendByte(ReadAddr & 0xFF);
	
	while(NumByteToRead--)
	{
		*pBuffer = SPI_FLASH_SendByte(Dummy_Byte);
		pBuffer++;
	}
}

/*
Function name:						SPI_FLASH_ReadID
Description	 :						Read FLASH ID
Para				 :						NONE
Output			 :						FLASH ID
Return			 :						NONE
*/
u32 SPI_FLASH_ReadID(void)
{
	u32 Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;
	
	SPI_FLASH_SendByte(W25X_JedecDeviceID);
	
	Temp0 = SPI_FLASH_SendByte(Dummy_Byte);
	
	Temp1 = SPI_FLASH_SendByte(Dummy_Byte);
	
	Temp2 = SPI_FLASH_SendByte(Dummy_Byte);

	Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;
	
	return Temp;
}

/*
Function name:						SPI_FLASH_StartReadSequence
Description	 :						Initiates a read data byte (READ) sequence from the Flash.
													This is done by driving the /CS line low to select the device,
													then the READ instruction is transmitted followed by 3 bytes
													address. This function exit and keep the /CS line low, so the
													Flash still being selected. With this technique the whole
													content of the Flash is read with a single READ instruction.
Para				 :						-ReadAddr, FLASH's internal address to read from.
Output			 :						NONE
Return			 :						NONE
*/
void SPI_FLASH_StartReadSequence(u32 ReadAddr)
{
	SPI_FLASH_SendByte(W25X_ReadData);
	
	SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
	
	SPI_FLASH_SendByte((ReadAddr& 0xFF00) >> 8);
	
	SPI_FLASH_SendByte(ReadAddr & 0xFF);
	
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

/*
Function name:						SPI_FLASH_WaitForWriteEnd
Description	 :						Wait until WIP = 0
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE
*/
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

/*
Function name:						SPI_FLASH_SendHalfWord
Description	 :						Send 2 byte to FLASH
Para				 :						-byte, Data need to be send
Output			 :						NONE
Return			 :						NONE
*/
u16 SPI_FLASH_SendHalfWord(u16 HalfWord)
{
	SPITimeout = SPIT_FLAG_TIMEOUT;
	
	while (SPI_I2S_GetFlagStatus(FLASH_SPI1 , SPI_I2S_FLAG_TXE) == RESET)
	{
		if((SPITimeout--) == 0)
		{
			
		}
	}
	SPI_I2S_SendData(FLASH_SPI1 , HalfWord);
	SPITimeout = SPIT_FLAG_TIMEOUT;
	
	while(SPI_I2S_GetFlagStatus(FLASH_SPI1, SPI_I2S_FLAG_RXNE) == RESET)
	{
		 
	}
	return SPI_I2S_ReceiveData(FLASH_SPI1 );
}

/*
Function name:						SPI_Flash_PowerDown
Description	 :						Enter low power mode
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE
*/
void SPI_Flash_PowerDown(void)
{
	SPI_FLASH_SendByte(W25X_PowerDown);
}  

/*
Function name:						SPI_Flash_WAKEUP
Description	 :						Wake up FLASH
Para				 :						NONE
Output			 :						NONE
Return			 :						NONE
*/
void SPI_Flash_WAKEUP(void) 
{
	SPI_FLASH_SendByte(W25X_ReleasePowerDown);
}




