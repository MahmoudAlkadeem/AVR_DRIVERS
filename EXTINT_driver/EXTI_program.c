/**************************************************************************************************
 * Title          :          External interrupts Driver                                           *
 * Description    :          source file for the AVR external interrupts interface                *
 * File Name      :          EXTI_program.c                                                       *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/

/***************************************************************************************************
 *                                          Includes                                               *
 ***************************************************************************************************/
#include "EXTI_interface.h"
#include "EXTI_registers.h"
#include "common_macros.h"
#include "std_types.h"
#include "DIO_registers.h"

/***************************************************************************************************
 *                                     Global Variables                                            *
 ***************************************************************************************************/
 /* Global variables to hold the address of the call back function in the application */
volatile static void (*voidPtrToInt0CallBack)(void) = NULL_PTR;
volatile static void (*voidPtrToInt1CallBack)(void) = NULL_PTR;
volatile static void (*voidPtrToInt2CallBack)(void) = NULL_PTR;

/***************************************************************************************************
 *                                    Functions Definition                                         *
 ***************************************************************************************************/
/*
 * Description :
 * Enable the selected external interrupt pin.
 * input : external interrupt number[enum] & interrupt sense control[enum].
 * output: void.
 */
void  EXTI_voidEnable(EXTI_source_enum copy_enumInterruptSourse,EXTI_senseControle_enum copy_enumInterruptSenseControl){

	switch(copy_enumInterruptSourse){
	case EXTI_INT0:
		SET_BIT(GICR_REG,INT0); /* external interrupt request 0 enable */
		MCUCR_REG = (MCUCR_REG & 0xfc) | ((copy_enumInterruptSenseControl & 0x03)<<ISC00);
		break;

	case EXTI_INT1:
		SET_BIT(GICR_REG,INT1); /* external interrupt request 1 enable */
		MCUCR_REG = (MCUCR_REG & 0xf3) | ((copy_enumInterruptSenseControl & 0x03)<<ISC10);
		break;

	case EXTI_INT2:
		SET_BIT(GICR_REG,INT2); /* external interrupt request 2 enable */
		switch(copy_enumInterruptSenseControl){
		case     EXTI_RISING_EDGE:    SET_BIT(MCUCSR_REG,ISC2);      break;
		case     EXTI_FALLING_EDGE:   CLEAR_BIT(MCUCSR_REG,ISC2);    break;
		default:
		}
		break;

	default:

	}
}

/*
 * Description :
 * Disable the selected external interrupt pin.
 * input : external interrupt number[enum].
 * output: void.
 */
void  EXTI_voidDisable(EXTI_source_enum copy_enumInterruptSourse){

	switch(copy_enumInterruptSourse){
	case EXTI_INT0:
		GICR_REG &=~ (1<<INT0);
		break;

	case EXTI_INT1:
		GICR_REG &=~ (1<<INT1);
		break;

	case EXTI_INT2:
		GICR_REG &=~ (1<<INT2);
		break;

	default:

	}

}

/*
 * Description :
 * Set the external interrupt 0 callback function.
 */
void EXTI_voidSetInt0CallBack(void (*ref_voidPtrToCallBack)(void)){
	/* Save the address of the Call back function in a global variable */
	voidPtrToInt0CallBack = ref_voidPtrToCallBack;
}

/*
 * Description :
 * Set the external interrupt 1 callback function.
 */
void EXTI_voidSetInt1CallBack(void (*ref_voidPtrToCallBack)(void)){
	/* Save the address of the Call back function in a global variable */
	voidPtrToInt1CallBack = ref_voidPtrToCallBack;
}

/*
 * Description :
 * Set the external interrupt 2 callback function.
 */
void EXTI_voidSetInt2CallBack(void (*ref_voidPtrToCallBack)(void)){
	/* Save the address of the Call back function in a global variable */
	voidPtrToInt2CallBack = ref_voidPtrToCallBack;
}



/***************************************************************************************************
 *                                             ISRs                                                *
 ***************************************************************************************************/
/*
 * Description :
 * external interrupt 0 ISR.
 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void){

	if( voidPtrToInt0CallBack != NULL_PTR ){
		(*voidPtrToInt0CallBack)();
	}

}

/*
 * Description :
 * external interrupt 1 ISR.
 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void){

	if( voidPtrToInt1CallBack != NULL_PTR ){
		(*voidPtrToInt1CallBack)();
	}

}


/*
 * Description :
 * external interrupt 2 ISR.
 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void){

	if( voidPtrToInt2CallBack != NULL_PTR ){
		(*voidPtrToInt2CallBack)();
	}

}

/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
