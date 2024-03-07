 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mahmoud Elkadeem
 *
 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "std_types.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{
	_delay_ms(100);
	/* Configure the direction for RS, RW and E pins as output pins */
	DIO_voidSetupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);

	DIO_voidSetupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);


	/* Configure 4 pins in the data port as output pins */
	DIO_voidSetupPinDirection(LCD_DATA_LIN1_PORT_ID,LCD_DATA_LIN1_PIN_ID,PIN_OUTPUT);
	DIO_voidSetupPinDirection(LCD_DATA_LIN2_PORT_ID,LCD_DATA_LIN2_PIN_ID,PIN_OUTPUT);
	DIO_voidSetupPinDirection(LCD_DATA_LIN3_PORT_ID,LCD_DATA_LIN3_PIN_ID,PIN_OUTPUT);
	DIO_voidSetupPinDirection(LCD_DATA_LIN4_PORT_ID,LCD_DATA_LIN4_PIN_ID,PIN_OUTPUT);

	LCD_sendCommand(LCD_GO_TO_HOME);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE); /* use 2-line lcd + 4-bit Data Mode */


	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command)
{

	_delay_ms(10);
	DIO_voidWritePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* Instruction Mode RS=0 */

	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the last 4 bits of the required command to the data bus D4 --> D7 */
	DIO_voidWritePin(LCD_DATA_LIN4_PORT_ID, LCD_DATA_LIN4_PIN_ID, ((command>>7) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN3_PORT_ID, LCD_DATA_LIN3_PIN_ID, ((command>>6) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN2_PORT_ID, LCD_DATA_LIN2_PIN_ID, ((command>>5) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN1_PORT_ID, LCD_DATA_LIN1_PIN_ID, ((command>>4) & 0x01));



	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the first 4 bits of the required command to the data bus D4 --> D7 */
	DIO_voidWritePin(LCD_DATA_LIN4_PORT_ID, LCD_DATA_LIN4_PIN_ID, ((command>>3) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN3_PORT_ID, LCD_DATA_LIN3_PIN_ID, ((command>>2) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN2_PORT_ID, LCD_DATA_LIN2_PIN_ID, ((command>>1) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN1_PORT_ID, LCD_DATA_LIN1_PIN_ID, ((command>>0) & 0x01));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data)
{

	_delay_ms(10);
	DIO_voidWritePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Data Mode RS=1 */

	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the last 4 bits of the required command to the data bus D4 --> D7 */
	DIO_voidWritePin(LCD_DATA_LIN4_PORT_ID, LCD_DATA_LIN4_PIN_ID, ((data>>7) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN3_PORT_ID, LCD_DATA_LIN3_PIN_ID, ((data>>6) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN2_PORT_ID, LCD_DATA_LIN2_PIN_ID, ((data>>5) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN1_PORT_ID, LCD_DATA_LIN1_PIN_ID, ((data>>4) & 0x01));



	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the first 4 bits of the required command to the data bus D4 --> D7 */
	DIO_voidWritePin(LCD_DATA_LIN4_PORT_ID, LCD_DATA_LIN4_PIN_ID, ((data>>3) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN3_PORT_ID, LCD_DATA_LIN3_PIN_ID, ((data>>2) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN2_PORT_ID, LCD_DATA_LIN2_PIN_ID, ((data>>1) & 0x01));
	DIO_voidWritePin(LCD_DATA_LIN1_PORT_ID, LCD_DATA_LIN1_PIN_ID, ((data>>0) & 0x01));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidWritePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	*********************************************************/
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col)
{
	u8 lcd_memory_address;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x12;
				break;
		case 3:
			lcd_memory_address=col+0x54;
				break;
	}					
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */

void LCD_displayInt(u16 data){
	   char buff[16]; /* String to hold the ascii result */
	   u8 lenth = 0;
	   u16 temp = data;

	   if(0 == data){
		   LCD_displayCharacter('0');
		   return;
	   }

	   while(temp > 0){
		   lenth++;
		   temp /= 10;
	   }

	   buff[lenth] = '\0';
	   lenth--;

	   for(int i = lenth; i>=0; i--){
		   buff[i] = (data%10)+'0';
		   data /=10;
	   }

	   LCD_displayString(buff); /* Display the string */
}
/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}

/*
void LCD_4_bit_Write_Custom_Char(uint8 line, uint8 col, uint8 mempos)
{
    LCD_sendCommand((_LCD_CGRAM_START + (mempos * 8)));
    LCD_moveCursor(line, col);
    LCD_displayCharacter(mempos);
}

void LCD_4_bit_Create_Custom_Char(uint8 *dataArr, uint8 mempos)
{
    LCD_sendCommand((_LCD_CGRAM_START + (mempos * 8)));
    for (uint8 i = 0; i < 8; i++)
    {
    	LCD_displayCharacter(dataArr[i]);
    }
    LCD_sendCommand(_LCD_DDRAM_START);
}
*/
