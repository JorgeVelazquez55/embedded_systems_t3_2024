/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        User component module interfaces
  \author       Gustavo S, Roberto V, Jorge V
  \project      Dynamic Memory Allocation Handler 
  \version      1.0
  \date         21/Sep/2024
   
  Program compiled with  WinIDEA Open Build 9.12.256 (54401), tested on Atmel SAMV71 Xplained Ultra
*/
/****************************************************************************************************/
#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include "Mem_AllocTypes.h"
#include "stdint.h"

extern uint32_t _heap_mem_start;
extern uint32_t _heap_mem_end;

MemReturnType Mem_Alloc ( MemSizeType Size );

#endif