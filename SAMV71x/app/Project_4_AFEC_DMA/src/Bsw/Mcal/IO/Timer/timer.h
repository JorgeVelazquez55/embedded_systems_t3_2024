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

#ifndef _TIMER_H        /*prevent duplicated includes*/
	#define _TIMER_H


extern void TC0_Handler(void);
extern void _ConfigureTc(void);

#endif /* _UART_H */