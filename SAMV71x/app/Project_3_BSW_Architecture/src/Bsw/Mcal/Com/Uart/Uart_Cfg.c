/*******************************************************************************/
/**
\file       Uart_Cfg.c
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        
   \description   
   \date          
*/

#include "Uart.h"
#include "Uart_Ctrl.h"   /* Callback functions */
#include "Uart_Cfg.h"

/** Standard Types */
#include "Std_Types.h"

/* Example of 3 configured channels */
const uint8_t UartConfiguredChannels[] = {
  UART_CFG_CHANNEL1,
  UART_CFG_CHANNEL0,
  UART_CFG_CHANNEL2,
  UART_CFG_CHANNEL4
};

