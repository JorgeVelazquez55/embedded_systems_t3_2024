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

#include "timerC.h"
#include "board.h"
#include <stdio.h>
/** Timer Counter */
#include    "tc.h"
#include    "timetick.h"

void TC0_Handler(void)
{
	volatile uint32_t dummy;
	/* Clear status bit to acknowledge interrupt */
	dummy = TC0->TC_CHANNEL[ 0 ].TC_SR;

	/** Toggle LED state. */
		LED_Toggle( 1 );
		printf( "1ms time " );

}

/**
 *  Configure Timer Counter 0 to generate an interrupt every 250ms.
 */
void _ConfigureTc(void)
{
	uint32_t div;
	uint32_t tcclks;

	/** Enable peripheral clock. */
	PMC_EnablePeripheral(ID_TC0);
	/** Configure TC for a 4Hz frequency and trigger on RC compare. */
	TC_FindMckDivisor( 100, BOARD_MCK, &div, &tcclks, BOARD_MCK );

	TC_Configure( TC0, 0, tcclks | TC_CMR_CPCTRG );
	TC0->TC_CHANNEL[ 0 ].TC_RC = ( BOARD_MCK / div ) / 100;

	/* Configure and enable interrupt on RC compare */
	NVIC_ClearPendingIRQ(TC0_IRQn);
	NVIC_EnableIRQ(TC0_IRQn);

	TC0->TC_CHANNEL[ 0 ].TC_IER = TC_IER_CPCS ;

		TC_Start( TC0, 0 );
}