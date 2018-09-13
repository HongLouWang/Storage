#include "Config.h"

int Init_1602(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(LCD_1602_RS_CLK,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_RS_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_1602_RS_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_RW_PIN;
	GPIO_Init(LCD_1602_RW_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_EN_PIN;
	GPIO_Init(LCD_1602_EN_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D0_PIN;
	GPIO_Init(LCD_1602_D0_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D1_PIN;
	GPIO_Init(LCD_1602_D1_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D2_PIN;
	GPIO_Init(LCD_1602_D2_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D3_PIN;
	GPIO_Init(LCD_1602_D3_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D4_PIN;
	GPIO_Init(LCD_1602_D4_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D5_PIN;
	GPIO_Init(LCD_1602_D5_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D6_PIN;
	GPIO_Init(LCD_1602_D6_PORT, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin   = LCD_1602_D7_PIN;
	GPIO_Init(LCD_1602_D7_PORT, &GPIO_InitStructure);
	
	return 1;
}

void LCD1602_SendDate(u8 buf)
{
	GPIO_SetBits(LCD_1602_RS_PORT, LCD_1602_RS_PIN);
	GPIO_SetBits(LCD_1602_RW_PORT, LCD_1602_RW_PIN);
	Delay(400);
	GPIO_ReadOutputDataBit(LCD_1602_EN_PORT, LCD_1602_EN_PIN);
	Delay(400);
	
	LCD_GPIO->BSRR |= (buf<<8) & 0xff00;
	LCD_GPIO->BRR  |= ((~buf)<<8) & 0xff00;	
	
	GPIO_ReadOutputDataBit(LCD_1602_RS_PORT, LCD_1602_RS_PIN);
	GPIO_ReadOutputDataBit(LCD_1602_RW_PORT, LCD_1602_RW_PIN);
	Delay(400);
	GPIO_ResetBits(LCD_1602_EN_PORT, LCD_1602_EN_PIN);
}

void LCD1602_Cmd(u8 buf)
{
	GPIO_ReadOutputDataBit(LCD_1602_RS_PORT, LCD_1602_RS_PIN);
	GPIO_SetBits(LCD_1602_RW_PORT, LCD_1602_RW_PIN);
	Delay(400);
	GPIO_ReadOutputDataBit(LCD_1602_EN_PORT, LCD_1602_EN_PIN);
	Delay(400);
	
	LCD_GPIO->BSRR |= (buf<<8) & 0xff00;
	LCD_GPIO->BRR  |= ((~buf)<<8) & 0xff00;	
	
	GPIO_SetBits(LCD_1602_RS_PORT, LCD_1602_RS_PIN);
	GPIO_ReadOutputDataBit(LCD_1602_RW_PORT, LCD_1602_RW_PIN);
	Delay(400);
	GPIO_ResetBits(LCD_1602_EN_PORT, LCD_1602_EN_PIN);
	
}

int Init_LCD1602()
{
	LCD1602_Cmd(0x38);
	Delay(5);
	LCD1602_Cmd(0x38);
	Delay(5);
	LCD1602_Cmd(0x38);
	Delay(5);
	LCD1602_Cmd(0x38);
	LCD1602_Cmd(0x08);
	LCD1602_Cmd(0x01);
	return 1;
}

