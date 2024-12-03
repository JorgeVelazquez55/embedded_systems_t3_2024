/**
\file       i2c.c
\brief      MCAL abstraction level - i2sc configuration
\author     Jorge V, Gustavo S, Roberto V
\version    1.0
\project    
\date       01/12/2024
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

#include "i2sc.h"
#include "ssc.h"
/*----------------------------------------------------------------------------
 *        Global Variables
 *----------------------------------------------------------------------------*/
extern codecOutputData[SAMPLES];

/*----------------------------------------------------------------------------
 *        FUNCTIONS
 *----------------------------------------------------------------------------*/

void SSC_Init_Configuration(void){
	SSC_Configure(SSC, 0, BOARD_MCK);
	SSC_ConfigureReceiver(SSC, RX_MR, RX_FMR);
	SSC_DisableReceiver(SSC);
	SSC_ConfigureTransmitter(SSC, TX_MR, TX_FMR);
	SSC_DisableTransmitter(SSC);
}