/**************************************************************************************************
 * Title          :          External interrupts Driver                                           *
 * Description    :          header file for the AVR external interrupts interface                *
 * File Name      :          EXTI_interface.h                                                     *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          06/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/***************************************************************************************************
 *                                      Types Declaration                                          *
 ***************************************************************************************************/
typedef enum{
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_source_enum;

typedef enum{
	EXTI_LOW_LEVEL = 0,
	EXTI_ANY_LOGIC_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE
}EXTI_senseControle_enum;

/***************************************************************************************************
 *                                        Definitions                                              *
 ***************************************************************************************************/
/*
 * Description :
 * Enable the selected external interrupt pin.
 * input : external interrupt number[enum] & interrupt sense control[enum].
 * output: void.
 */
void  EXTI_voidEnable(EXTI_source_enum copy_enumInterruptSourse,EXTI_senseControle_enum copy_enumInterruptSenseControl);

/*
 * Description :
 * Disable the selected external interrupt pin.
 * input : external interrupt number[enum].
 * output: void.
 */
void  EXTI_voidDisable(EXTI_source_enum copy_enumInterruptSourse);

/*
 * Description :
 * Set the external interrupt 0 callback function.
 */
void EXTI_voidSetInt0CallBack(void (*ref_voidPtrToCallBack)(void));

/*
 * Description :
 * Set the external interrupt 1 callback function.
 */
void EXTI_voidSetInt1CallBack(void (*ref_voidPtrToCallBack)(void));

/*
 * Description :
 * Set the external interrupt 2 callback function.
 */
void EXTI_voidSetInt2CallBack(void (*ref_voidPtrToCallBack)(void));


#endif /* EXTI_INTERFACE_H_ */
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
