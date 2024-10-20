/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        Memory Allocation Handler internal data type definitions
  \author       Gustavo S, Roberto V, Jorge V
  \project      Dynamic Memory Allocation Handler 
  \version      1.0
  \date         21/Sep/2024
   
  Program compiled with  WinIDEA Open Build 9.12.256 (54401), tested on Atmel SAMV71 Xplained Ultra
*/
/****************************************************************************************************/

#ifndef MEM_ALLOC_TYPES_H
#define MEM_ALLOC_TYPES_H

#include "stdint.h"

/**
 * @brief 
 * 
 */
typedef void* MemReturnType;

/**
 * @brief 
 * 
 */
typedef uint16_t MemSizeType;

/**
 * @brief 
 * 
 */
typedef struct
{
    uint8_t* MemStart;
    uint8_t* MemEnd;
    uint8_t* CurrAddr;
    uint32_t FreeBytes;
}MemHandlerType;

#endif