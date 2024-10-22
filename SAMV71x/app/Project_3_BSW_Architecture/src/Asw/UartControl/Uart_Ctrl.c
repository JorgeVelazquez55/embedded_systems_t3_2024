/****************************************************************************************************/
/**
\file       Uart_Ctrl.c
\brief      MCU abstraction level - Uart control
\author     Francisco Martinez
\version    1.0
\date       25/Sep/2018
*/
/****************************************************************************************************/
 
/*****************************************************************************************************
* Include files
*****************************************************************************************************/
/** Own headers */
#include "Uart_Ctrl.h"
#include "Uart_Cfg.h"
#include "Std_Types.h"
#include "Uart.h"
 
/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/
uint8_t*    pu8SerialCtrl_RxDataPtr;
 
uint16_t 		StringLength0;
uint16_t 		StringLength1;
uint16_t 		StringLength2;
uint16_t 		StringLength3;
uint16_t 		StringLength4;
uint8_t*    ptrString0;
uint8_t*    ptrString1;
uint8_t*    ptrString2;
uint8_t*    ptrString3;
uint8_t*    ptrString4;
 
uint8_t 		String0[] = { "UART0 @ 4800 bps" };
uint8_t 		String1[] = { "UART1 @ 9600 bps" };
uint8_t 		String2[] = { "UART2 @ 19200 bps" };
uint8_t 		String3[] = { "UART3 @ 57600 bps" };
uint8_t 		String4[] = { "UART4 @ 115200 bps" };
 
 
 
/****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/
 
void UartCtrl_2ms( void )
{
 
}
 
void UartCtrl_50ms( void )
{
 
}
 
void UartCtrl_100ms( void )
{
  /*Call to Uart Trigger*/
	UartCtrl_TriggerEvent();
}
 
void UartCtrl_TriggerEvent( void )
{
  //Initializing/reseting buffer of UART0 for testing
	ptrString0 = &String0[0];
	StringLength0 = sizeof(String0);
	Uart_EnableInt(UART_CFG_PHY_CHANNEL0, UART_MASK_TXRDY, 1);
  //Initializing/reseting buffer of UART1 for testing
	ptrString1 = &String1[0];
	StringLength1 = sizeof(String1);
	Uart_EnableInt(UART_CFG_PHY_CHANNEL1, UART_MASK_TXRDY, 1);
  //Initializing/reseting buffer of UART2 for testing
	ptrString2 = &String2[0];
	StringLength2 = sizeof(String2);
	Uart_EnableInt(UART_CFG_PHY_CHANNEL2, UART_MASK_TXRDY, 1);
  //Initializing/reseting buffer of UART3 for testing
	ptrString3 = &String3[0];
	StringLength3 = sizeof(String3);
	Uart_EnableInt(UART_CFG_PHY_CHANNEL3, UART_MASK_TXRDY, 1);
	//Initializing/reseting buffer of UART4 for testing
	ptrString4 = &String4[0];
	StringLength4 = sizeof(String4);
	Uart_EnableInt(UART_CFG_PHY_CHANNEL4, UART_MASK_TXRDY, 1);
 
}
 
 
void vfnSerialCtrl_Transfer0(void)
{
	if (StringLength0 > 0)
	{
		/* Send out one byte at a time */
		Uart_SendByteInt(UART_CFG_PHY_CHANNEL0, *ptrString0);
		/* point to next element */
		ptrString0++;
		/* update number of pending bytes to transfer */
		StringLength0--;
	}
	else
	{
		//Disable the interruption once that done
		Uart_EnableInt(UART_CFG_PHY_CHANNEL0, UART_MASK_TXRDY, 0);
	}
 
}
 
void vfnSerialCtrl_Transfer1(void)
{
	if (StringLength1 > 0)
	{
		/* Send out one byte at a time */
		Uart_SendByteInt(UART_CFG_PHY_CHANNEL1, *ptrString1);
		/* point to next element */
		ptrString1++;
		/* update number of pending bytes to transfer */
		StringLength1--;
	}
	else
	{
		//Disable the interruption once that done
		Uart_EnableInt(UART_CFG_PHY_CHANNEL1, UART_MASK_TXRDY, 0);
	}
}
 
void vfnSerialCtrl_Transfer2(void)
{
	if (StringLength2 > 0)
	{
		/* Send out one byte at a time */
		Uart_SendByteInt(UART_CFG_PHY_CHANNEL2, *ptrString2);
		/* point to next element */
		ptrString2++;
		/* update number of pending bytes to transfer */
		StringLength2--;
	}
	else
	{
		//Disable the interruption once that done
		Uart_EnableInt(UART_CFG_PHY_CHANNEL2, UART_MASK_TXRDY, 0);
	}
}
 
void vfnSerialCtrl_Transfer3(void)
{
	if (StringLength3 > 0)
	{
		/* Send out one byte at a time */
		Uart_SendByteInt(UART_CFG_PHY_CHANNEL3, *ptrString3);
		/* point to next element */
		ptrString3++;
		/* update number of pending bytes to transfer */
		StringLength3--;
	}
	else
	{
		//Disable the interruption once that done
		Uart_EnableInt(UART_CFG_PHY_CHANNEL3, UART_MASK_TXRDY, 0);
	}
}
 
void vfnSerialCtrl_Transfer4(void)
{
	if (StringLength4 > 0)
	{
		/* Send out one byte at a time */
		Uart_SendByteInt(UART_CFG_PHY_CHANNEL4, *ptrString4);
 
		/* point to next element */
		ptrString4++;
		/* update number of pending bytes to transfer */
		StringLength4--;
 
	}
	else
	{
		//Disable the interruption once that done
		Uart_EnableInt(UART_CFG_PHY_CHANNEL4, UART_MASK_TXRDY, 0);  
  }
}
 
 
/*******************************************************************************/