/**************************************************************************************************
 * Driver Title   :          DIO Driver                                                           *
 * Description    :          source file for the AVR DIO program                                  *
 * File Name      :          DIO_program.c                                                        *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/

/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "common_macros.h"
#include "DIO_interface.h"
#include "DIO_registers.h"

/***************************************************************************************************
 *                                    Functions Definition                                         *
 ***************************************************************************************************/
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_voidSetupPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction)
{

	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA_REG,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB_REG,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC_REG,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD_REG,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_voidWritePin(u8 port_num, u8 pin_num, u8 value)
{

	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA_REG,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB_REG,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC_REG,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD_REG,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD_REG,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 DIO_u8ReadPin(u8 port_num, u8 pin_num)
{
	u8 pin_value = LOGIC_LOW;

	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND_REG,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}

	return pin_value;
}

/*
 * Description :
 * Toggles the pin output if the pin is output pin.
 * activate or disable the pull-up resistor if the pin is input
 */
void DIO_voidTogglePin(u8 port_num, u8 pin_num){
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else{
		switch (port_num) {
			case PORTA_ID:
				TOGGLE_BIT(PORTA_REG,pin_num);
				break;

			case PORTB_ID:
				TOGGLE_BIT(PORTB_REG,pin_num);
				break;

			case PORTC_ID:
				TOGGLE_BIT(PORTC_REG,pin_num);
				break;

			case PORTD_ID:
				TOGGLE_BIT(PORTD_REG,pin_num);
				break;

			default:

		}
	}
}
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
