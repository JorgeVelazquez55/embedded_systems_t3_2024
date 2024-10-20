/*******************************************************************************/
/**
\file       
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        
   \description   
   \date          
*/

/** Scheduler function prototypes definitions */
#include "Uart.h"
#include "Mem_Alloc.h"
/** Standard Types */
#include "Std_Types.h"
/** UART Types */
#include "Uart_Types.h"
/** UART Config */
#include "Uart_Cfg.h"
#include "pmc.h"
#include "uart.h"
#include "uartdrv.h"

//#include "C:\SAMV7x\SAMV71x\hal\libchip_samv7\include\uartdrv.h"

/*****************************************************************************************************
* Defines - 
*****************************************************************************************************/

#define UART_CHANNEL_UNDEF (255)

#define UART_CH0  (0) 
#define UART_CH1  (1)
#define UART_CH2  (2)
#define UART_CH3  (3)
#define UART_CH4  (4)

/*****************************************************************************************************
* Definition of  VARIABLEs - 
*****************************************************************************************************/

/* Uart Status Structure Example */
UartStatusType *UartStatus;
  

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/
/* Array of Uart Register Base Address */
static const Uart * UartRegAddr[]={ UART0, UART1, UART2, UART3, UART4 };

static const uint32_t UartIDs[] = { ID_UART0, ID_UART1, ID_UART2, ID_UART4, ID_UART3 };

static const uint8_t IRQn[]={ UART0_IRQn, UART1_IRQn, UART2_IRQn, UART3_IRQn, UART4_IRQn};

uint8_t  *		pu8SerialCtrl_ReadTxDataPtr;
uint8_t 		  u8SerialCtrl_TxData[] = {"Uart0"};
uint16_t      u16SerialCtrl_TxLength;

/*****************************************************************************************************
* Code of module wide Private FUNCTIONS
*****************************************************************************************************/

static uint8_t Uart_GetLogChannel(uint8_t PhyChannel)
{
  uint8_t LogicalChannel = UART_CHANNEL_UNDEF; 
  uint8_t LocChIdx = 0; /* LocChIdx represent the logical channel */
  /* UART_CFG_CHANNELS represents the number of configured channels from configuration structure */
  do
  {
    if (UartStatus[LocChIdx].ChannelId == PhyChannel)
    {
      LogicalChannel = LocChIdx; 
    }
    LocChIdx++;
  }while( (UartStatus[LocChIdx-1].ChannelId != PhyChannel) && (LocChIdx < UART_CFG_CHANNELS) );
  return (LogicalChannel);
}

/*****************************************************************************************************
* Code of module wide Public FUNCTIONS
*****************************************************************************************************/

void Uart_Init (const UartStatusType* UartStatus)
{
  Uart * LocUartReg;
  uint32_t Parity = 0;
	uint32_t Mode = 0;
	uint32_t Baudrate = 0;
	uint32_t Clock = 0;
	uint32_t Interrupt = 0;
  uint8_t LocChIdx = 0; /* LocChIdx represent the logical channel */
  uint8_t physicalUART = 100;
   
  /* Memory allocation for all Channel Status example */
  /* UART_CFG_CHANNELS represents the number of configured channels from configuration structure */
  UartStatus = (UartStatusType*) MemAlloc( sizeof(UartStatusType) * UART_CFG_CHANNELS  );  
  
  for (LocChIdx = 0; LocChIdx < UART_CFG_CHANNELS; LocChIdx++)
  {
    physicalUART = Uart_GetLogChannel(UartStatus->UartChannel[LocChIdx].ChannelId);
    /* Point to register address based of physical channel */
    LocUartReg = (Uart*)UartRegAddr[physicalUART];
    //LocUartReg = UartRegAddr[UartStatus[LocChIdx]];
    /* Access to register for the configured channel with LocUartReg */
    /* Access to channel status structure with LocChIdx */
    //UartStatus[LocChIdx].ChannelId = ChannelConfigure[LocChIdx];    
    PMC_EnablePeripheral(UartIDs[LocChIdx]);
    
    //Set correct value for baudrate from structure config
    switch(UartStatus->UartChannel[LocChIdx].Parity)
		{
			case (UART_PARITY_NO):
				Parity = UART_MR_PAR_NO;
				break;
			case (UART_PARITY_EVEN):
				Parity = UART_MR_PAR_EVEN;
				break; 
			case (UART_PARITY_MARK):
				Parity = UART_MR_PAR_MARK;
				break;
			case (UART_PARITY_ODD):
				Parity = UART_MR_PAR_ODD;
				break;
			case (UART_PARITY_SPACE):
				Parity = UART_MR_PAR_SPACE;
				break;


		}
  //Set correct value for mode from structure config
  switch(UartStatus->UartChannel[LocChIdx].Mode)
		{
			case (UART_MODE_AUTO):
				Mode = UART_MR_CHMODE_AUTOMATIC;
				break;
			case (UART_MODE_NORMAL):
				Mode = UART_MR_CHMODE_NORMAL;
				break;
			case (UART_MODE_LOOPBACK):
				Mode = UART_MR_CHMODE_LOCAL_LOOPBACK;
				break;
		}

  //Set correct value for clock source from structure config  
  if (UartStatus->UartChannel[LocChIdx].ClkSrc == 0)
  {
    Clock = BOARD_MCK;
  }
	else
	{
		Clock = UartStatus->UartChannel[LocChIdx].ClkSrc;
	}
  //Set correct value for baudrate from structure config
  Baudrate = UartStatus->UartChannel[LocChIdx].Baudrate;
  UART_Configure(LocUartReg, (Parity | Mode), Baudrate, Clock);
  NVIC_ClearPendingIRQ(IRQn[physicalUART]);
  NVIC_SetPriority(IRQn[physicalUART], 1);

  Interrupt = UartStatus->UartChannel[LocChIdx].IsrEn;

	UART_SetTransmitterEnabled(LocUartReg, Interrupt);
  UART_SetReceiverEnabled(LocUartReg, Interrupt);
		
  UART_EnableIt(LocUartReg, Interrupt);
  


  }
}

void Uart_Send(uint8_t Channel)
{
    Uart * LocUartReg;
    LocUartReg = (Uart*)UartRegAddr[Channel];
	  pu8SerialCtrl_ReadTxDataPtr = &u8SerialCtrl_TxData[0];
    u16SerialCtrl_TxLength = sizeof(u8SerialCtrl_TxData);
	  UART_SendBuffer(LocUartReg, pu8SerialCtrl_ReadTxDataPtr, u16SerialCtrl_TxLength);
}


/*****************************************************************************************************
* Code of module wide Interrupt Handler FUNCTIONS
*****************************************************************************************************/

void Uart_Isr( uint8_t Channel )
{
  const Uart * LocUartReg = UartRegAddr[Channel];
  uint8_t LocUartLogicChannel = Uart_GetLogChannel(Channel);
  
  /* Example Code */
  /* UART_CFG_CHANNELS represents the number of configured channels from configuration structure */
  if (LocUartLogicChannel<UART_CFG_CHANNELS)
    UartStatus[LocUartLogicChannel].TriggerCounter++;
	    
}


void UART0_Handler(void)
{
	Uart_Isr(UART_CH0);
}


void UART1_Handler(void)
{
	Uart_Isr(UART_CH1);
}


void UART2_Handler(void)
{
	Uart_Isr(UART_CH2);
}


void UART3_Handler(void)
{
	Uart_Isr(UART_CH3);
}


void UART4_Handler(void)
{
	Uart_Isr(UART_CH4);
}