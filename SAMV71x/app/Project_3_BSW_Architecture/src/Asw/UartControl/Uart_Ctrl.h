/****************************************************************************************************/
/**
\file       Uart_Ctrl.h
\brief      Application layer - Uart control
\author     Gustavo A, Roberto V, Jorge V,
\version    1.0
\date       21/10/2024
*/
/****************************************************************************************************/
 
#ifndef __UART_CTRL_H        /*prevent duplicated includes*/
#define __UART_CTRL_H
 
/*****************************************************************************************************
* Include files
*****************************************************************************************************/
 
/** Standard Types */
#include "Std_Types.h"
 
/** Used modules */
 
/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/
 
/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/
 
 
/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/
 
/** Uart Control Exported Functions */
extern void UartCtrl_2ms( void );
extern void UartCtrl_50ms( void );
extern void UartCtrl_100ms( void );
extern void UartCtrl_TriggerEvent( void );
 
extern void vfnSerialCtrl_Transfer0();
extern void vfnSerialCtrl_Transfer1();
extern void vfnSerialCtrl_Transfer2();
extern void vfnSerialCtrl_Transfer3();
extern void vfnSerialCtrl_Transfer4();
 
 
/**************************************************************************************************/
 
#endif /* __UART_CTRL_H */