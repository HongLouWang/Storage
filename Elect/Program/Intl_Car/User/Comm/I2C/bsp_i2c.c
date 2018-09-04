
#include "bsp_i2c.h"
//#include 

void I2C_EE_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	I2C_InitTypeDef I2C_InitStructure;
	
	//Open I2C GPIO 
	EEPROM_I2C_GPIO_APBxClkCmd(EEPROM_SCL_GPIO_CLK | EEPROM_SDA_GPIO_CLK, ENABLE);
	
	//Open I2C CLOCK
	EEPROM_I2C_APBxClkCmd(EEPROM_I2C_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SCL_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(EEPROM_I2C_SCL_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SDA_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(EEPROM_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);
	
	//
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = EEPROM_I2C_BAUDRATE;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C ;
	I2C_InitStructure.I2C_OwnAddress1 = STM32_I2C_OWN_ADDR;
	
	I2C_Init(EEPROM_I2C, &I2C_InitStructure);
	
	I2C_Cmd(EEPROM_I2C, ENABLE);
	
}

