                /****************************************************************************************************/
/**
\file       timerC.c
\brief      MCAL abstraction level - Digital to Analog Converter Controller configuration and interrupt handling.
\author     Jorge V, Gustavo S, Roberto V
\version    1.0
\project    
\date       01/10/2024
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/
/** timerC function prototypes and definitions */

#include "timer.h"
#include "board.h"
#include <stdio.h>
/** Timer Counter */
#include    "tc.h"
#include    "timetick.h"

/**
 *  Interrupt handler for TC0 interrupt. Toggles the state of LED\#2.
 */

/** LED1 blinking control. */
volatile bool bLed1Active = true ;

void TC0_Handler(void)
{
	volatile uint32_t dummy;
	/* Clear status bit to acknowledge interrupt */
	dummy = TC0->TC_CHANNEL[ 0 ].TC_SR;

	/** Toggle LED state. */
	if(bLed1Active) {
		LED_Toggle( 1 );
		printf( "1ms time " );
    bLed1Active = false;
	}
  else {
		LED_Toggle( 0 );
		printf( "2ms time " );
    bLed1Active = true;
  }

}

/**
 *  Configure Timer Counter 0 to generate a trigger every 1ms.
 */
void _ConfigureTc(void)
{
	uint32_t div;
	uint32_t tcclks;

	/** Enable peripheral clock. */
	PMC_EnablePeripheral(ID_TC0);
	/** Configure TC for a 4Hz frequency and trigger on RC compare. */
	TC_FindMckDivisor( 2000, BOARD_MCK, &div, &tcclks, BOARD_MCK );
  //TC_Configure(TC0, 0, tcclks |  TC_CMR_WAVSEL_UP_RC | TC_CMR_WAVE | TC_CMR_ACPC_TOGGLE | TC_CMR_ENETRG);
  TC0->TC_CHANNEL[0].TC_CMR = tcclks |  TC_CMR_WAVSEL_UP_RC | TC_CMR_WAVE | TC_CMR_ACPC_TOGGLE | TC_CMR_ENETRG;
  TC0->TC_CHANNEL[0].TC_RC = (BOARD_MCK / div) / 2000;
  TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;

	/* Configure and enable interrupt on RC compare */
  /* Disables for the trigger purpose*/
	//NVIC_ClearPendingIRQ(TC0_IRQn);
	//NVIC_EnableIRQ(TC0_IRQn);
  //TC0->TC_CHANNEL[0].TC_IER = TC_IER_CPCS;
  
}