/**
\file       i2c.c
\brief      MCAL abstraction level - i2c configuration
\author     Jorge V, Gustavo S, Roberto V
\version    1.0
\project    
\date       01/12/2024
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

#include "twi.h"
#include "twid.h"
#include "Std_types.h"
#include "i2c.h"

/*----------------------------------------------------------------------------
 *        FUNCTIONS
 *----------------------------------------------------------------------------*//*    TWI instancia    */


/** TWI High Speed clock */
#define I2C_CLOCK		  400000
Twid twid;

void i2c_configure(void)
{
	/** Enable peripheral clock. */
	PMC_EnablePeripheral(ID_TWIHS0);
	TWI_ConfigureMaster( TWIHS0, I2C_CLOCK, BOARD_MCK);
  TWID_Initialize(&twid, TWIHS0);
  
  	/* Configuracion de la interrupcion de TWI */
	NVIC_ClearPendingIRQ(TWIHS0_IRQn);
	NVIC_EnableIRQ(TWIHS0_IRQn);
	
}


/*    Interrupcion de TWI    */
void TWIHS0_Handler(void){
	TWID_Handler(&twid);
}

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/

