/*******************************************************************************/
/**
\file       
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        Gustavo A, Roberto V, Jorge V,
   \description   Uart definitions, and extern of uart.c functions
   \date          20/10/2024 
*/

#ifndef _UART_H        /*prevent duplicated includes*/
	#define _UART_H

	/** Standard Types */
	//#include "Std_Types.h"
	#include "Uart_Types.h"
	#include "Uart_Cfg.h"

	/*UART Mask Definition*/
	#define UART_MASK_RXRDY		1
	#define UART_MASK_TXRDY		2
	#define UART_MASK_OVRE		32
	#define UART_MASK_FRAME		64
	#define UART_MASK_PARE		128
	#define UART_MASK_TXEMPTY	512


	/* Uart Initialization and Config  Fucntions */
	extern void Uart_Init(const UartConfigType *ChannelConfigure );
	extern Std_ReturnType Uart_SetBaudrate(uint8_t Channel, uint32_t Baudrate);

	/* Uart for TX Fucntions */
	extern void Uart_SetTxEnable(uint8_t Channel, uint32_t Enable);
	extern Std_ReturnType Uart_SendBuffer(uint8_t Channel, uint8_t* Buffer, uint16_t Length);
	extern void Uart_SendByteInt(uint8_t Channel, uint8_t Byte);

	/* Uart for RX Fucntions */
  extern void Uart_SeRxEnable(uint8_t Channel, uint32_t Enable);
	extern uint8_t Uart_GetByte(uint8_t Channel);

	/* Uart for status Fucntions */
	extern uint32_t Uart_GetStatus(uint8_t Channel);


	/* Example Code - Need to be removed */
	extern void UART0_Handler(void);
	extern void UART1_Handler(void);
	extern void UART2_Handler(void);
	extern void UART3_Handler(void);
	extern void UART4_Handler(void);

/*============================================================================*/
#endif /* _UART_H */