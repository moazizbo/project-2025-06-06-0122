#include "main.h"
#include "utils.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

UART_HandleTypeDef huart2;

static void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();
    char rx_buffer[BUFFER_SIZE];

    while (1) {
        if (HAL_UART_Receive(&huart2, (uint8_t*)rx_buffer, BUFFER_SIZE, HAL_MAX_DELAY) == HAL_OK) {
            handle_command(rx_buffer);
            memset(rx_buffer, 0, BUFFER_SIZE);
        }
    }
}

void SystemClock_Config(void) {
    // System clock configuration code ...
}

void MX_GPIO_Init(void) {
    // GPIO initialization code ...
}

void MX_USART2_UART_Init(void) {
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK) {
        Error_Handler();
    }
}

void Error_Handler(void) {
    while (1) {
        // Blink an LED or other error indicators
    }
}