/*******************************************************************************/
/**
\file       
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        Gustavo A, Roberto V, Jorge V,
   \description   Uart definitions, and extern of uart.c functions
   \date          20/10/2024 
*/

#ifndef _I2C_H        /*prevent duplicated includes*/
	#define _I2C_H


/* Prototypes */
extern void i2c_configure(void);
extern void TWIHS0_Handler(void);

#endif /* _I2C_H */