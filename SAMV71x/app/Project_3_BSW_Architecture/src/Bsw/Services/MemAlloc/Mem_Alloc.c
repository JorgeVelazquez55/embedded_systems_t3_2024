/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        Memory Allocation Handler
  \author       Gustavo S, Roberto V, Jorge V
  \project      Dynamic Memory Allocation Handler 
  \version      1.0
  \date         21/Sep/2024
   
  Program compiled with  WinIDEA Open Build 9.12.256 (54401), tested on Atmel SAMV71 Xplained Ultra
*/
/****************************************************************************************************/


/*~~~~~~  Headers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** Main group of includes for board definitions, chip definitions and type definitions */
#include "Mem_Alloc.h"
#include "stdlib.h"


/*~~~~~~  Local definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/       
MemHandlerType MemControl = {(uint8_t *) &_heap_mem_start, (uint8_t *) &_heap_mem_end, (uint8_t *) &_heap_mem_start, 10000};

/*~~~~~~  Global variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~  Local functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
MemReturnType Mem_Alloc ( MemSizeType Size )
{   
    uint8_t* alignedAddress = NULL;
    if( MemControl.CurrAddr+Size > MemControl.MemEnd || Size > MemControl.FreeBytes )
    {
        // Not enough memory space
        return NULL;
    }
    else{
        MemControl.MemStart = MemControl.CurrAddr;
        MemControl.CurrAddr = (uint8_t*)((uint32_t)MemControl.CurrAddr + (uint32_t)((Size + 3) & 0xFFFFFFFC));
        MemControl.FreeBytes = MemControl.FreeBytes - Size;
        return MemControl.MemStart;
    }

}
/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/**
 *  \brief getting-started Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */

