/**************************************************************************************************
 * Driver Title   :          ADC Driver                                                           *
 * Description    :          source file for the AVR ADC program                                  *
 * File Name      :          ADC_program.c                                                        *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          07/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/

/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "std_types.h"
#include "common_macros.h"
#include "ADC_registers.h"
#include "ADC_interface.h"

/***************************************************************************************************
 *                                      global variables                                           *
 ***************************************************************************************************/
/* global pointer to function to hold the callback address */
volatile static void (*ADC_voidPtrToCallBack)(void) = NULL_PTR;

/***************************************************************************************************
 *                                    Functions Definition                                         *
 ***************************************************************************************************/
void ADC_voidInit(ADC_vRefrence_enum copy_enumVoltRefrence){

	ADMUX_REG = (ADMUX_REG & 0x3f)  | ((copy_enumVoltRefrence << REFS0) & 0xc0);
	CLEAR_BIT(ADMUX_REG,ADLAR);
	ADCSRA_REG |= 0x03; /* pre-scaler = 128 */
	SET_BIT(ADCSRA_REG, ADEN);
	SET_BIT(ADCSRA_REG, ADIE);

}

void ADC_voidStartConv(ADC_channelNum_enum copy_enumChannelNum){
	ADMUX_REG = (ADMUX_REG & 0xe0) | (copy_enumChannelNum & 0x1f);
	SET_BIT(ADCSRA_REG,ADSC); /* start conversion */
}

volatile u16 ADC_u16ReadDigitalValue(void){
	return ADC_REG;
}

void ADC_voidSetCallBack(volatile void (*ptrToFun)(void)){
	ADC_voidPtrToCallBack = ptrToFun;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void){

	if( ADC_voidPtrToCallBack != NULL_PTR ){
		(*ADC_voidPtrToCallBack)();
	}

}
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
