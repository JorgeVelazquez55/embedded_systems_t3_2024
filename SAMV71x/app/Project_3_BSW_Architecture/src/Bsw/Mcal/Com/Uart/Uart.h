/*******************************************************************************/
/**
\file       Uart.h
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        
   \description   
   \date          
*/

#ifndef _UART_H        /*prevent duplicated includes*/
	#define _UART_H

	/** Standard Types */
	//#include "Std_Types.h"
	#include "Uart_Types.h"
	#include "Uart_Cfg.h"

	/*UART Mask Definition*/
	#define UART_MASK_TXRDY		2


	/* Uart Initialization Fucntion */
	extern void Uart_Init(const UartConfigType *ChannelConfigure );

	/* Uart Send Fucntion */
	extern Std_ReturnType Uart_SendBuffer(uint8_t Channel, uint8_t* Buffer, uint16_t Length);
	extern void Uart_SendByteInt(uint8_t Channel, uint8_t Byte);

	extern Std_ReturnType Uart_SetBaudrate(uint8_t Channel, uint32_t Baudrate);
	extern void Uart_SetTxEnable(uint8_t Channel, uint32_t Enable);


	/* Example Code - Need to be removed */
	extern void UART0_Handler(void);
	extern void UART1_Handler(void);
	extern void UART2_Handler(void);
	extern void UART3_Handler(void);
	extern void UART4_Handler(void);

/*============================================================================*/
#endif /* _UART_H */