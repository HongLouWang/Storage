#ifndef	_BSP_FLASH_H_
#define	_BSP_FLASH_H_

#include "Config.h"

#define W25X_WriteEnable		      0x06 
#define W25X_WriteDisable		      0x04 
#define W25X_ReadStatusReg		    0x05 
#define W25X_WriteStatusReg		    0x01 
#define W25X_ReadData			        0x03 
#define W25X_FastReadData		      0x0B 
#define W25X_FastReadDual		      0x3B 
#define W25X_PageProgram		      0x02 
#define W25X_BlockErase			      0xD8 
#define W25X_SectorErase		      0x20 
#define W25X_ChipErase			      0xC7 
#define W25X_PowerDown			      0xB9 
#define W25X_ReleasePowerDown	    0xAB 
#define W25X_DeviceID			        0xAB 
#define W25X_ManufactDeviceID   	0x90 
#define W25X_JedecDeviceID		    0x9F

#define WIP_Flag                  0x01
#define Dummy_Byte                0xFF

#define SPIT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define SPIT_LONG_TIMEOUT         ((uint32_t)(10 * SPIT_FLAG_TIMEOUT))

u8 SPI_FLASH_SendByte(u8 byte);
void SPI_FLASH_WaitForWriteEnd(void);
u8 SPI_FLASH_SendByte(u8 byte);
u8 SPI_FLASH_ReadByte(void);
void SPI_FLASH_WriteEnable(void);
void SPI_FLASH_SectorErase(u32 SectorAddr);
void SPI_FLASH_Init(void);

#endif
