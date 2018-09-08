#ifndef _BSP_I2C_H
#define _BSP_I2C_H

#include "stm32f10x.h"
#include <stdio.h>

// I2C1
#define  EEPROM_I2C                I2C1
#define  EEPROM_I2C_CLK            RCC_APB1Periph_I2C1
#define  EEPROM_I2C_APBxClkCmd     RCC_APB2PeriphClockCmd
#define  EEPROM_I2C_BAUDRATE       40000

// I2C GPIO Òý½Åºê¶¨Òå
#define  EEPROM_SCL_GPIO_CLK       (RCC_APB2Periph_GPIOB)
#define  EEPROM_SDA_GPIO_CLK	     (RCC_APB2Periph_GPIOB)

#define  EEPROM_I2C_GPIO_APBxClkCmd RCC_APB2PeriphClockCmd
    
#define  EEPROM_I2C_SCL_GPIO_PORT   GPIOB
#define  EEPROM_I2C_SCL_GPIO_PIN    GPIO_Pin_6

#define  EEPROM_I2C_SDA_GPIO_PORT   GPIOB
#define  EEPROM_I2C_SDA_GPIO_PIN    GPIO_Pin_7

#define STM32_I2C_OWN_ADDR					0x5F				


#endif


