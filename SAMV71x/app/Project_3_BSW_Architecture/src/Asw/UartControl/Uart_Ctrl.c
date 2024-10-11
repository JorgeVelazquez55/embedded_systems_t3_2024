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
#include  "Uart_Ctrl.h"
#include "Uart.h"

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/


/****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/

void UartCtrl_2ms( void )
{
  /* Example Code, need to be removed */
  /* Uart Logic Channel 0 */
  Uart_Send(0);
}

void UartCtrl_50ms( void )
{
  /* Example Code, need to be removed */
  /* Uart Logic Channel 1 */
  Uart_Send(1);
}

void UartCtrl_100ms( void )
{
  /* Example Code, need to be removed */
  /* Uart Logic Channel 2 */
  Uart_Send(2);
}

void UartCtrl_TriggerEvent( void )
{
  /* Example Code, need to be removed */
  /* These function handlers shall be invoked upon interrupt request */
  UART0_Handler();
  UART1_Handler();
  UART2_Handler();
  UART3_Handler();
  UART4_Handler();
  /* In your solution this trigger can start a buffer transmission */
}

/*******************************************************************************/
