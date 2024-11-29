/*******************************************************************************/
/**
\file       
\brief      
   \~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   \version       1.0
   \author        Gustavo A, Roberto V, Jorge V,
   \description   WM8904 Audio Codec configuration functions
   \date          28/Nov/2024 
*/

#ifndef _WM8904_H        /*prevent duplicated includes*/
	#define _WM8904_H


extern void PMC_EnablePeripheral(void);
extern void PIO_Configure(void);
extern void TWI_ConfigureMaster(void);

#endif /* _WM8904_H */
