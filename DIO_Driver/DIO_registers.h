/**************************************************************************************************
 * Driver Title   :          DIO Driver                                                           *
 * Description    :          header file for the AVR DIO Registers                                *
 * File Name      :          DIO_registers.h                                                      *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/

#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "std_types.h"

/***************************************************************************************************
 *                                    Registers Definitions                                        *
 ***************************************************************************************************/

#define PORTA_REG *((volatile u8 *)0x3B)
#define PORTB_REG *((volatile u8 *)0x38)
#define PORTC_REG *((volatile u8 *)0x35)
#define PORTD_REG *((volatile u8 *)0x32)

#define DDRA_REG *((volatile u8 *)0x3A)
#define DDRB_REG *((volatile u8 *)0x37)
#define DDRC_REG *((volatile u8 *)0x34)
#define DDRD_REG *((volatile u8 *)0x31)

#define PINA_REG *((volatile const u8 *)0x39)
#define PINB_REG *((volatile const u8 *)0x36)
#define PINC_REG *((volatile const u8 *)0x33)
#define PIND_REG *((volatile const u8 *)0x30)



#endif /* DIO_REGISTERS_H_ */
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
