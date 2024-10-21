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

  }UartStatusType;
  


  /*Function pointer for Uart TXand RX notifications to be used as part of the configuration containers*/
  typedef void(*UartNotification)(void);


/*============================================================================*/
#endif /* UART_TYPES */
