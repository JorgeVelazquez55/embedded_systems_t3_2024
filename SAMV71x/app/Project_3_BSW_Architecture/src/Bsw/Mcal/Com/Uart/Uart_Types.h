/*******************************************************************************/
/**
\file       Uart_Types.h
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        
   \description   
   \date          
*/

#ifndef UART_TYPES
#define UART_TYPES

  /** Standard Types */
  #include "Std_Types.h"
  
  /* UartStatusType example */
  typedef struct
  {
    uint8_t ChannelId;
    uint8_t Counter;
    uint8_t TriggerCounter;
    UartChannelType* UartChannel;
  }UartStatusType;
  
typedef struct UartConfigType
	{
    uint8_t ClkSrc;
		uint8_t ChannelId;
		uint32_t IsrEn;
		uint8_t Mode;
		uint8_t Parity;
		uint32_t Baudrate;
	} UartConfigType;
/*============================================================================*/
#endif /* UART_TYPES */
