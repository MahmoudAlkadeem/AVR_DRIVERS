/**************************************************************************************************
 * Driver Title   :          ADC Driver                                                           *
 * Description    :          header file for the AVR ADC Registers                                *
 * File Name      :          ADC_registers.h                                                      *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/
#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_
/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "std_types.h"

/***************************************************************************************************
 *                                    Registers Definitions                                        *
 ***************************************************************************************************/
#define ADMUX_REG     (*(volatile u8 *)0x27)
#define REFS1         7
#define REFS0         6
#define ADLAR         5
#define MUX4          4
#define MUX3          3
#define MUX2          2
#define MUX1          1
#define MUX0          0

#define ADCSRA_REG    (*(volatile u8 *)0x26)
#define ADEN          7
#define ADSC          6
#define ADATE         5
#define ADIF          4
#define ADIE          3
#define ADPS2         2
#define ADPS1         1
#define ADPS0         0

#define ADC_REG       (*(volatile u16 *)0x24)

#endif /* ADC_REGISTERS_H_ */
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
