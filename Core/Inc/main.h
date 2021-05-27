/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define HX711_1_CLK_Pin GPIO_PIN_4
#define HX711_1_CLK_GPIO_Port GPIOA
#define HX711_1_DATA_Pin GPIO_PIN_5
#define HX711_1_DATA_GPIO_Port GPIOA
#define HX711_2_CLK_Pin GPIO_PIN_6
#define HX711_2_CLK_GPIO_Port GPIOA
#define HX711_2_DATA_Pin GPIO_PIN_7
#define HX711_2_DATA_GPIO_Port GPIOA
#define HCSR04_TRIG_Pin GPIO_PIN_14
#define HCSR04_TRIG_GPIO_Port GPIOB
#define HCSR04_ECHO_Pin GPIO_PIN_15
#define HCSR04_ECHO_GPIO_Port GPIOB
#define DS18B20_Pin GPIO_PIN_5
#define DS18B20_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
