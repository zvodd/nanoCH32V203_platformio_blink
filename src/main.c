#if defined(CH32V00X)
#include <ch32v00x.h>
#elif defined(CH32V10X)
#include <ch32v10x.h>
#elif defined(CH32V20X)
#include <ch32v20x.h>
#elif defined(CH32V30X)
#include <ch32v30x.h>
#endif
#include <stdio.h>
#include "debug.h"


void GPIO_Toggle_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);
	GPIO_Toggle_init();

	u8 i = 0;
	while (1)
	{
		Delay_Ms(500); // give serial monitor time to open
		GPIO_WriteBit(GPIOA, GPIO_Pin_15, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
		Delay_Ms(100); // give serial monitor time to open
		GPIO_WriteBit(GPIOA, GPIO_Pin_15, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
		Delay_Ms(100); // give serial monitor time to open
		GPIO_WriteBit(GPIOA, GPIO_Pin_15, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
		Delay_Ms(100); // give serial monitor time to open
		GPIO_WriteBit(GPIOA, GPIO_Pin_15, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
		Delay_Ms(100); // give serial monitor time to open
		GPIO_WriteBit(GPIOA, GPIO_Pin_15, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
	}
		// printf("SystemClk: %u\r\n", (unsigned)SystemCoreClock);
		// #if defined(CH32V30X)
		// printf("ChipID: %08x\r\n", (unsigned)DBGMCU_GetCHIPID());
		// #else
		// printf("DeviceID: %08x\r\n", (unsigned)DBGMCU_GetDEVID());
		// #endif
		// printf("This is printf example\r\n");

		// printf("Program over, press reset button\r\n");
	
}

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void NMI_Handler(void) {}
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void)
{
	while (1)
	{
	}
}