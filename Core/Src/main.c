/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ssd1306.h"
#include "fonts.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define 	TITLE			0
#define 	ARROW_SPACE		20
#define 	ARROW_START		0

#define		FIRST_ROW		20
#define		SECOND_ROW		35
#define 	THIRD_ROW		50
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart5;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
int row  = 0;
int page = 0;
int led  = 0;
int time = 0;

int uartFlag = 0;

void ScreenMenu (int r, int p)
{
	row  = r ;
	page = p ;

	switch(page)
	{
	case 1:
			SSD1306_Clear();

			SSD1306_GotoXY (10, TITLE);
			SSD1306_Puts ("< HANGI LED >", &Font_7x10, 1);

			SSD1306_GotoXY (ARROW_SPACE, FIRST_ROW);
			SSD1306_Puts ("1. Led", &Font_7x10, 1);

			SSD1306_GotoXY (ARROW_SPACE, SECOND_ROW);
			SSD1306_Puts ("2. Led", &Font_7x10, 1);

			SSD1306_GotoXY (ARROW_SPACE, THIRD_ROW);
			SSD1306_Puts ("3. Led", &Font_7x10, 1);

			switch(row)
			{
			case 1:
				SSD1306_GotoXY (ARROW_START, FIRST_ROW);
				SSD1306_Puts ("->", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				led = 1;
				break;
			case 2:
				SSD1306_GotoXY (ARROW_START, SECOND_ROW);
				SSD1306_Puts ("->", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				led = 2;
				break;
			case 3:
				SSD1306_GotoXY (ARROW_START, THIRD_ROW);
				SSD1306_Puts ("->", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				led = 3;
				break;
			}
			break;

	case 2:
			SSD1306_Clear();

			switch(led)
			{
			case 1:
				SSD1306_GotoXY (0, TITLE);
				SSD1306_Puts ("< 1.LED SURESI >", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, FIRST_ROW);
				SSD1306_Puts ("0.5 S", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, SECOND_ROW);
				SSD1306_Puts ("1 SN", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, THIRD_ROW);
				SSD1306_Puts ("2 SN", &Font_7x10, 1);
				break;
			case 2:
				SSD1306_GotoXY (5, 0);
				SSD1306_Puts ("< 2.LED SURESI >", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, FIRST_ROW);
				SSD1306_Puts ("0.5 S", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, SECOND_ROW);
				SSD1306_Puts ("1 SN", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, THIRD_ROW);
				SSD1306_Puts ("2 SN", &Font_7x10, 1);
				break;
			case 3:
				SSD1306_GotoXY (5, 0);
				SSD1306_Puts ("< 3.LED SURESI >", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, FIRST_ROW);
				SSD1306_Puts ("0.5 S", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, SECOND_ROW);
				SSD1306_Puts ("1 SN", &Font_7x10, 1);

				SSD1306_GotoXY (ARROW_SPACE, THIRD_ROW);
				SSD1306_Puts ("2 SN", &Font_7x10, 1);
				break;
			}

			switch(row)
			{
			case 1:
				SSD1306_GotoXY (ARROW_START, FIRST_ROW);
				SSD1306_Puts ("->", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				time = 1;
				break;
			case 2:
				SSD1306_GotoXY (ARROW_START, SECOND_ROW);
				SSD1306_Puts ("->", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				time = 2;
				break;
			case 3:
				SSD1306_GotoXY (ARROW_START, THIRD_ROW);
				SSD1306_Puts ("->", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				time = 3;
				break;
			}
			break;

	case 3:
		SSD1306_Clear();

		if(led == 1)
		{
			switch(time)
			{
			case 1:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("1.LED", &Font_11x18, 1);
				SSD1306_GotoXY (35, 35);
				SSD1306_Puts ("0.5 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 1;
				break;
			case 2:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("1.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("1 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 2;
				break;
			case 3:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("1.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("2 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 3;
				break;
			}
		}

		if(led == 2)
		{
			switch(time)
			{
			case 1:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("2.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("0.5 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 4;
				break;
			case 2:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("2.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("1 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 5;
				break;
			case 3:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("2.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("2 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 6;
				break;
			}
		}

		if(led == 3)
		{
			switch(time)
			{
			case 1:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("3.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("0.5 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 7;
				break;
			case 2:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("3.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("1 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 8;
				break;
			case 3:
				SSD1306_Clear();
				SSD1306_GotoXY (40, 15);
				SSD1306_Puts ("3.LED", &Font_11x18, 1);
				SSD1306_GotoXY (40, 35);
				SSD1306_Puts ("2 SN", &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				uartFlag = 9;
				break;
			}
		}
	}
}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART5_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART3_UART_Init(void);
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
  MX_UART5_Init();
  MX_I2C1_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  SSD1306_Init();

  ScreenMenu(1, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	switch(uartFlag)
	{
	case 1:
		HAL_UART_Transmit(&huart5, (uint8_t*)"1H\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"1H", 2, 1000);
		uartFlag = 0;
		break;
	case 2:
		HAL_UART_Transmit(&huart5, (uint8_t*)"1O\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"1O", 2, 1000);
		uartFlag = 0;
		break;
	case 3:
		HAL_UART_Transmit(&huart5, (uint8_t*)"1Y\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"1Y", 2, 1000);
		uartFlag = 0;
		break;
	case 4:
		HAL_UART_Transmit(&huart5, (uint8_t*)"2H\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"2H", 2, 1000);
		uartFlag = 0;
		break;
	case 5:
		HAL_UART_Transmit(&huart5, (uint8_t*)"2O\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"2O", 2, 1000);
		uartFlag = 0;
		break;
	case 6:
		HAL_UART_Transmit(&huart5, (uint8_t*)"2Y\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"2Y", 2, 1000);
		uartFlag = 0;
		break;
	case 7:
		HAL_UART_Transmit(&huart5, (uint8_t*)"3H\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"3H", 2, 1000);
		uartFlag = 0;
		break;
	case 8:
		HAL_UART_Transmit(&huart5, (uint8_t*)"3O\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"3O", 2, 1000);
		uartFlag = 0;
		break;
	case 9:
		HAL_UART_Transmit(&huart5, (uint8_t*)"3Y\n", 3, 1000);
		HAL_UART_Transmit(&huart3, (uint8_t*)"3Y", 2, 1000);
		uartFlag = 0;
		break;
	}
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief UART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pins : DownButton_Pin UpButton_Pin RightButton_Pin LeftButton_Pin */
  GPIO_InitStruct.Pin = DownButton_Pin|UpButton_Pin|RightButton_Pin|LeftButton_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == DownButton_Pin)
	{
			switch(row)
			{
			case 1:
				ScreenMenu(2, page);
				break;
			case 2:
				ScreenMenu(3, page);
				break;
			case 3:
				ScreenMenu(1, page);
				break;
			}
	}

	if(GPIO_Pin == UpButton_Pin)
	{
				switch(row)
				{
				case 1:
					ScreenMenu(3, page);
					break;
				case 2:
					ScreenMenu(1, page);
					break;
				case 3:
					ScreenMenu(2, page);
					break;
				}
	}

	if(GPIO_Pin == RightButton_Pin)
	{
			switch(page)
					{
					case 1:
						ScreenMenu(row, 2);
						break;
					case 2:
						ScreenMenu(row, 3);
						break;
					case 3:
						ScreenMenu(row, 3);
					}

	}

	if(GPIO_Pin == LeftButton_Pin)
	{
		switch(page)
		{
		case 1:
			ScreenMenu(row, 1);
			break;
		case 2:
			ScreenMenu(row, 1);
			break;
		case 3:
			ScreenMenu(row, 2);
		}
	}
}
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

