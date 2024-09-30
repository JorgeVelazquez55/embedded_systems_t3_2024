/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        Main application (main module)
  \author       Gustavo S, Roberto V, Jorge V
  \project      Dynamic Memory Allocation Handler 
  \version      1.0
  \date         21/Sep/2024
   
  Program compiled with  WinIDEA Open Build 9.12.256 (54401), tested on Atmel SAMV71 Xplained Ultra
*/
/****************************************************************************************************/


/*~~~~~~  Headers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** Main group of includes for board definitions, chip definitions and type definitions */
#include    "board.h"
/** User component module interfaces */
/** LED control definitions */ 
#include    "led_ctrl.h"
//#include "MemAlloc/Mem_Alloc.h"
#include    "Mem_Alloc.h"

/*~~~~~~  Local definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/       

/*~~~~~~  Global variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*~~~~~~  Local functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
	//_ConfigureButtons();
	LED_Configure( 0 ) ;
	/* Disable watchdog */
	WDT_Disable(WDT);
	/* Enable I and D cache */
	SCB_EnableICache();
	/* SCB_EnableDCache(); */
	/* Configure LEDs */
	
	Mem_Alloc(8);
  
  Mem_Alloc(15);
  
  Mem_Alloc(200);
  
  Mem_Alloc(40);
  
  Mem_Alloc(10000);
  
	printf("Hola Mundo\n");

}