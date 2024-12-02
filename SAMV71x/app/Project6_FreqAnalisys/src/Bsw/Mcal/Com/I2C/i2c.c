


/** \file
 *
 *  This file contains all the specific code for the getting-started example.
 *
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "twi.h"
#include    "Std_types.h"


/** TWI High Speed clock */
#define I2C_CLOCK		  400000

void i2c_configure(void)
{
	/** Enable peripheral clock. */
	PMC_EnablePeripheral(ID_TWIHS0);
	TWI_ConfigureMaster( TWIHS0, I2C_CLOCK, BOARD_MCK);
  
  	/* Configuracion de la interrupcion de TWI */
	NVIC_ClearPendingIRQ(TWIHS0_IRQn);
	NVIC_EnableIRQ(TWIHS0_IRQn);
	
}



/*    Interrupcion de TWI    */
void TWIHS0_Handler(void){
	//TWID_Handler(&twid);
}

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

