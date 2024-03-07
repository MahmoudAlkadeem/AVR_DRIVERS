/**************************************************************************************************
 * Driver Title   :          DIO Driver                                                           *
 * Description    :          header file for the AVR DIO interface                                *
 * File Name      :          DIO_interface.h                                                      *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "std_types.h"

/***************************************************************************************************
 *                                        Definitions                                              *
 ***************************************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7


/***************************************************************************************************
 *                                      Types Declaration                                          *
 ***************************************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;


/***************************************************************************************************
 *                                    Functions Prototypes                                         *
 ***************************************************************************************************/
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_voidSetupPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_voidWritePin(u8 port_num, u8 pin_num, u8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 DIO_u8ReadPin(u8 port_num, u8 pin_num);

/*
 * Description :
 * Toggles the pin output if the pin is output pin.
 * activate or disable the pull-up resistor if the pin is input
 */
void DIO_voidTogglePin(u8 port_num, u8 pin_num);

#endif /* DIO_INTERFACE_H_ */
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
