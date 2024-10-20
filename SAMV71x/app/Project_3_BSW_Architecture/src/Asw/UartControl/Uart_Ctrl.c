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
/** Pin definition: Pin type definition is located at pio.h file */
/* 
  typedef struct _Pin
  {
  	uint32_t mask;     PIO_PA9                                      -> Bitmask indicating which pin(s) to configure.
  	Pio    *pio;       PIOA                                         -> Pointer to the PIO controller which has the pin(s).
  	uint8_t id;        ID_PIOA                                      -> Peripheral ID of the PIO controller which has the pin(s).
  	uint8_t type;      PIO_INPUT                                    -> Pin Type
  	uint8_t attribute; PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE -> Pin attribute
  } Pin ;
*/
/** UART pins (UTXD0 and URXD0) definitions, PA9,10. */
#define PINS_UART0  \
		{PIO_PA9A_URXD0 | PIO_PA10A_UTXD0, PIOA, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/
/** SW0 Pin Definition, used to configure the Pin and Pin Interrupt, see ConfigureSW0Button function  */
const Pin PinUartTx0[] = PINS_UART0;


void Uart_ConfigurePIO( void )
{
	/* Configure PinSW0 as input. */
	PIO_Configure(PinUartTx0, PIO_LISTSIZE(PinUartTx0) ) ;
}

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
