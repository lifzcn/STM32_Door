/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "ds18b20.h"
#include "hcsr04.h"
#include "hx711.h"
#include "oled.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int i = 0;
	int x = 0;
	int y = 0;
	
	float Temprature_Value;
	int Temprature_Value_Integer;
	int Temprature_Value_Decimal;
	
	float Distance_Value;
	int Distance_Value_Integer;
	int Distance_Value_Decimal;
	
	int Pressure_Left;
	int Pressure_Right;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	OLED_Init();
	OLED_Clear();
	
	OLED_ShowChinese(x, y, 0);
	OLED_ShowChinese(x + 1 * 16, y, 1);
	OLED_ShowChinese(x + 2 * 16, y, 8);
	OLED_ShowChar(x + 3 * 16, y, ':', 16);
	
	OLED_ShowChinese(x, y + 1 * 2, 2);
	OLED_ShowChinese(x + 1 * 16, y + 1 * 2, 3);
	OLED_ShowChinese(x + 2 * 16, y + 1 * 2, 8);
	OLED_ShowChar(x + 3 * 16, y + 1 * 2, ':', 16);
	
	
	OLED_ShowChinese(x, y + 2 * 2, 4);
	OLED_ShowChinese(x + 1 * 16, y + 2 * 2, 5);
	OLED_ShowChinese(x + 2 * 16, y + 2 * 2, 6);
	OLED_ShowChinese(x + 3 * 16, y + 2 * 2, 8);
	OLED_ShowChar(x + 4 * 16, y + 2 * 2, ':', 16);
	
	OLED_ShowChinese(x, y + 3 * 2, 4);
	OLED_ShowChinese(x + 1 * 16, y + 3 * 2, 5);
	OLED_ShowChinese(x + 2 * 16, y + 3 * 2, 7);
	OLED_ShowChinese(x + 3 * 16, y + 3 * 2, 8);
	OLED_ShowChar(x + 4 * 16, y + 3 * 2, ':', 16);
	
	while(DS18B20_Init())
	{
		printf("DS18B20接入失败，请重试!\r\n");
		HAL_Delay(500);
	}
	printf("DS18B20接入成功!\r\n");
	
	HAL_GPIO_WritePin(HX711_1_CLK_GPIO_Port,HX711_1_CLK_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(HX711_2_CLK_GPIO_Port,HX711_2_CLK_Pin,GPIO_PIN_RESET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		i += 1;
		
		if(i % 2 == 0)
		{
			Temprature_Value = DS18B20_GetTemperture();
			Temprature_Value_Integer = (int)Temprature_Value;
			Temprature_Value_Decimal = 10 * (Temprature_Value - (int)Temprature_Value);
			
			Distance_Value = HCSR04_GetDistance_Repeatedly(5);
			Distance_Value_Integer = (int)Distance_Value;
			Distance_Value_Decimal = 10 * (Distance_Value - (int)Distance_Value);
			
			Pressure_Left = Get_Weight_1();
			Pressure_Right = Get_Weight_2();
			
			if(Pressure_Left > 0)
			{
				Pressure_Left = Pressure_Left;
			}
			else
			{
				Pressure_Left = 0;
			}
			
			if(Pressure_Right > 0)
			{
				Pressure_Right = Pressure_Right;
			}
			else
			{
				Pressure_Right = 0;
			}
			
			printf("======================\r\n");
			printf("温度值：%.1fC\r\n",Temprature_Value);
			printf("距离值：%.1fcm\r\n",Distance_Value);
			printf("压力左值：%dg\r\n",Pressure_Left);
			printf("压力右值：%dg\r\n",Pressure_Right);
			printf("======================\r\n");
		}
		
		OLED_ShowNum(x + 7 * 8, y, Temprature_Value_Integer, 2, 16);
		OLED_ShowChar(x + 9 * 8, y, '.', 16);
		OLED_ShowNum(x + 10 * 8, y, Temprature_Value_Decimal, 1, 16);
		OLED_ShowChar(x + 11 * 8, y, 'C', 16);
		
		OLED_ShowNum(x + 7 * 8, y + 1 * 2, Distance_Value_Integer, 2, 16);
		OLED_ShowChar(x + 9 * 8, y + 1 * 2, '.', 16);
		OLED_ShowNum(x + 10 * 8, y + 1 * 2, Distance_Value_Decimal, 1, 16);
		OLED_ShowChar(x + 11 * 8, y + 1 * 2, 'c', 16);
		OLED_ShowChar(x + 12 * 8, y + 1 * 2, 'm', 16);
		
		OLED_ShowNum(x + 9 * 8, y + 2 * 2, Pressure_Left, 4, 16);
		OLED_ShowChar(x + 13 * 8, y + 2 * 2, 'g', 16);
		
		OLED_ShowNum(x + 9 * 8, y + 3 * 2, Pressure_Right, 4, 16);
		OLED_ShowChar(x + 13 * 8, y + 3 * 2, 'g', 16);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
