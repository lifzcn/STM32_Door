#include "hx711.h"
#include "tim.h"
#include "main.h"

long HX711_Buffer_1 = 0;
long Weight_Maopi_1 = 0;
long Weight_Shiwu_1 = 0;

long HX711_Buffer_2 = 0;
long Weight_Maopi_2 = 0;
long Weight_Shiwu_2 = 0;

#define GapValue 1000

void Get_Maopi_1(void)
{
	Weight_Maopi_1 = HX711_Read_1();		
} 

long Get_Weight_1(void)
{
	HX711_Buffer_1 = HX711_Read_1();
	Weight_Shiwu_1 = HX711_Buffer_1;
	Weight_Shiwu_1 = Weight_Shiwu_1 - Weight_Maopi_1;//获取实物的AD采样数值。
	Weight_Shiwu_1 = (long)((float)Weight_Shiwu_1/GapValue); 	
	return Weight_Shiwu_1 - 8360;
}

unsigned long HX711_Read_1(void)//增益128
{
	unsigned long count; 
	unsigned char i;

	HAL_GPIO_WritePin(HX711_1_DATA_GPIO_Port,HX711_1_DATA_Pin,GPIO_PIN_SET);
	HAL_Delay_us(1);

	HX711_1_CLK_LOW;
	HAL_Delay_us(1);

  count=0; 
	
  while(HX711_1_DATA_OUT); 
	
  for(i=0;i<24;i++)
	{ 
	  HX711_1_CLK_HIGH; 
		HAL_Delay_us(1);
	  count=count<<1; 
		HX711_1_CLK_LOW; 
		HAL_Delay_us(1);
	  if(HX711_1_DATA_OUT)
		{
			count++;
		}			
	} 
 	HX711_1_CLK_HIGH; 
	count ^= 0x800000;
	HAL_Delay_us(1);
	HX711_1_CLK_LOW; 
	HAL_Delay_us(1);
	return(count);
}

void Get_Maopi_2(void)
{
	Weight_Maopi_2 = HX711_Read_2();		
} 

long Get_Weight_2(void)
{
	HX711_Buffer_2 = HX711_Read_2();
	Weight_Shiwu_2 = HX711_Buffer_2;
	Weight_Shiwu_2 = Weight_Shiwu_2 - Weight_Maopi_2;//获取实物的AD采样数值。
	Weight_Shiwu_2 = (long)((float)Weight_Shiwu_2/GapValue); 	
	return Weight_Shiwu_2 - 8488;
}

unsigned long HX711_Read_2(void)//增益128
{
	unsigned long count; 
	unsigned char i;

	HAL_GPIO_WritePin(HX711_2_DATA_GPIO_Port,HX711_2_DATA_Pin,GPIO_PIN_SET);
	HAL_Delay_us(1);

	HX711_2_CLK_LOW;
	HAL_Delay_us(1);

  count=0; 
	
  while(HX711_2_DATA_OUT); 
	
  for(i=0;i<24;i++)
	{ 
	  HX711_2_CLK_HIGH; 
		HAL_Delay_us(1);
	  count=count<<1; 
		HX711_2_CLK_LOW; 
		HAL_Delay_us(1);
	  if(HX711_2_DATA_OUT)
		{
			count++;
		}			
	} 
 	HX711_2_CLK_HIGH; 
	count ^= 0x800000;
	HAL_Delay_us(1);
	HX711_2_CLK_LOW; 
	HAL_Delay_us(1);
	return(count);
}
