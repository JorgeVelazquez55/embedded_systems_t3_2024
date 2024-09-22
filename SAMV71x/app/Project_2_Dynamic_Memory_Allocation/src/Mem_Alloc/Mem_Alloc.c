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
#include    "board.h"
/** User component module interfaces */
#include    "Mem_Alloc.h"

/*~~~~~~  Local definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/       
MemHandlerType MemControl =
{
  .MemStart =   (uint8_t *) &_heap_mem_start,                               /* Sets the start of the heap memory */
  .MemEnd =     (uint8_t *) &_heap_mem_end,                                 /* Sets the end of the heap memory */
  .CurrAddr =   (uint8_t *) &_heap_mem_start,                               /* Initialize the current start address */
  .FreeBytes =  (uint8_t *) &_heap_mem_end - (uint8_t *) &_heap_mem_start;  /* Sets the size of the heap memory */
};

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





MemReturnType Mem_Alloc( MemSizeType Size )
{
  MemReturnType NewStartAddr;
  uint32_t      CurrStartAddr;

  if ( Size > MemControl.FreeBytes )
  {
    printf('Error: Size exceeds available HEAP memory - Unable to perform requested memory allocation');
    NewStartAddr = NULL;  
  }
  else
  {
    CurrStartAddr = MemControl.CurrAddr + Size;
    NewStartAddr = MemControl.CurrAddr;
  }

  return NewStartAddr;
}
