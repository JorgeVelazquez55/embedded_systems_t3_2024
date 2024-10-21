/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        Main application (main module)
  \author       Abraham Tezmol Otero, M.S.E.E
  \project      Tau 
  \version      1.0
  \date         12/Jun/2016
   
  Program compiled with  WinIDEA Open Build 9.12.256 (54401), tested on Atmel SAMV71 Xplained Ultra
*/
/****************************************************************************************************/


/*~~~~~~  Headers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** Main group of includes for board definitions, chip definitions and type definitions */
#include    "Std_Types.h"
/** Task scheduler definitions */
#include    "SchM.h"
#include    "chip.h"

/** LED control definitions */ 
#include    "Led_Ctrl.h"
/** Watchdog control function prototypes definitions */
#include    "Wdg.h"
/** Button Control interfaces */
#include    "Button_Ctrl.h"
/** Uart interfaces */
#include    "Uart.h"
//#include    "uart.h"
#include    "Uart_Cfg.h"
#include    "Uart_Types.h"

#include    "uart.h"
#include    "pmc.h"


/*~~~~~~  Local definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~  Global variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

UartStatusType Config;
/*~~~~~~  Local functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void uartConfigurationInit()
{
	//Config.UartNumberOfChannels = 2;
	
	//Config.UartChannel = (UartChannelType*)MemAlloc(sizeof(UartChannelType*) * (Config.UartNumberOfChannels));

  Config.ChannelId = 0;
	Config.UartChannel[0].ClkSrc = 0;
	Config.UartChannel[0].IsrEn = UART_INT_TXRDY;
	Config.UartChannel[0].Mode = UART_MODE_NORMAL;
	Config.UartChannel[0].Parity = UART_PARITY_ODD;
	Config.UartChannel[0].Baudrate = 9200;

  Config.ChannelId = 1;
	Config.UartChannel[1].ClkSrc = 0;
	Config.UartChannel[1].IsrEn = UART_INT_TXRDY;
	Config.UartChannel[1].Mode = UART_MODE_NORMAL;
	Config.UartChannel[1].Parity = UART_PARITY_EVEN;
	Config.UartChannel[1].Baudrate = 28800;

  Config.ChannelId = 2;  
	Config.UartChannel[2].ClkSrc = 0;
	Config.UartChannel[2].IsrEn = UART_INT_TXRDY;
	Config.UartChannel[2].Mode = UART_MODE_LOOPBACK;
	Config.UartChannel[2].Parity = UART_PARITY_NO;
	Config.UartChannel[2].Baudrate = 115200;

  Config.ChannelId = 3;  
	Config.UartChannel[3].ClkSrc = 0;
	Config.UartChannel[3].IsrEn = UART_INT_TXRDY;
	Config.UartChannel[3].Mode = UART_MODE_LOOPBACK;
	Config.UartChannel[3].Parity = UART_PARITY_EVEN;
	Config.UartChannel[3].Baudrate = 19200;




}
/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/**
 *  \brief getting-started Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
extern int main( void )
{
	/* Disable watchdog */
	Wdg_Disable();
	printf( "\n\r-- Scheduler Project %s --\n\r", SOFTPACK_VERSION ) ;
	printf( "-- %s\n\r", BOARD_NAME ) ;
	printf( "-- Compiled: %s %s With %s --\n\r", __DATE__, __TIME__ , COMPILER_NAME);
	/* Enable I and D cache */
	SCB_EnableICache();
	/* SCB_EnableDCache(); */
	/* Configure LEDs */
	printf( "-- Led Control --\n\r" ) ;
	LedCtrl_Configure();
  
    printf( "-- Button Control --\n\r" ) ;  
    ButtonCtrl_ConfigureSW0Button();
  
    /* Uart Inititalization */
    printf( "-- Uart Initialization --\n\r" ) ;
    Uart_ConfigurePIO();
   	uartConfigurationInit();
    Uart_Init(&Config);
    //Uart_Init(&UartConfiguredChannels[0]);
    Uart_Send(0);
  

  
	/* Scheduler Inititalization */
	printf( "-- Scheduler Initialization --\n\r" ) ;
	//SchM_Init(ScheduleConfig);
	
	/* Should never reach this code */
	//for(;;)
    //{
		//printf( "-- Unexpected Error at Scheduler Initialization --\n\r" ) ;
	//}
}
