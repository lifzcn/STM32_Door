#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "main.h"

//IO�ڲ���
#define DS18B20_DQ_OUT_HIGH HAL_GPIO_WritePin(DS18B20_GPIO_Port,DS18B20_Pin,GPIO_PIN_SET)
#define DS18B20_DQ_OUT_LOW 	HAL_GPIO_WritePin(DS18B20_GPIO_Port,DS18B20_Pin,GPIO_PIN_RESET)
#define DS18B20_DQ_IN	 HAL_GPIO_ReadPin(DS18B20_GPIO_Port,DS18B20_Pin)

uint8_t DS18B20_Init(void);//��ʼ��DS18B20
float DS18B20_GetTemperture(void);//��ȡ�¶�
void DS18B20_Start(void);//��ʼ�¶�ת��
void DS18B20_Write_Byte(uint8_t dat);//д��һ���ֽ�
uint8_t DS18B20_Read_Byte(void);//����һ���ֽ�
uint8_t DS18B20_Read_Bit(void);//����һ��λ
uint8_t DS18B20_Check(void);//����Ƿ����DS18B20
void DS18B20_Reset(void);//��λDS18B20   

#endif
