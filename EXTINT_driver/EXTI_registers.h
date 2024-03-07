/**************************************************************************************************
 * Driver Title   :          External interrupts Driver                                           *
 * Description    :          header file for the AVR external interrupts Registers                *
 * File Name      :          EXTI_registers.h                                                     *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/
#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_

/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "std_types.h"

/***************************************************************************************************
 *                                    Registers Definitions                                        *
 ***************************************************************************************************/

#define MCUCR_REG     (*(volatile u8*)0x55)
#define ISC11         3
#define ISC10         2
#define ISC01         1
#define ISC00         0

#define MCUCSR_REG    (*(volatile u8*)0x54)
#define ISC2          6

#define GICR_REG      (*(volatile u8*)0x5B)
#define INT1          7
#define INT0          6
#define INT2          5

#define MIFR_REG      (*(volatile u8*)0x5A)
#define INTF1          7
#define INTF0          6
#define INTF2          5


#endif /* EXTI_REGISTERS_H_ */
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
