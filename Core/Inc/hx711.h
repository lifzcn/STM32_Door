#ifndef __HX711_H__
#define __HX711_H__

#include "stm32f1xx_hal.h"
#include "main.h"

#define HX711_1_CLK_HIGH	HAL_GPIO_WritePin(HX711_1_CLK_GPIO_Port,HX711_1_CLK_Pin,GPIO_PIN_SET)
#define HX711_1_CLK_LOW		HAL_GPIO_WritePin(HX711_1_CLK_GPIO_Port,HX711_1_CLK_Pin,GPIO_PIN_RESET)
#define HX711_1_DATA_OUT	HAL_GPIO_ReadPin(HX711_1_DATA_GPIO_Port,HX711_1_DATA_Pin)

#define HX711_2_CLK_HIGH	HAL_GPIO_WritePin(HX711_2_CLK_GPIO_Port,HX711_2_CLK_Pin,GPIO_PIN_SET)
#define HX711_2_CLK_LOW		HAL_GPIO_WritePin(HX711_2_CLK_GPIO_Port,HX711_2_CLK_Pin,GPIO_PIN_RESET)
#define HX711_2_DATA_OUT	HAL_GPIO_ReadPin(HX711_2_DATA_GPIO_Port,HX711_2_DATA_Pin)

void Get_Maopi_1(void);
long Get_Weight_1(void);
unsigned long HX711_Read_1(void);

void Get_Maopi_2(void);
long Get_Weight_2(void);
unsigned long HX711_Read_2(void);

#endif
