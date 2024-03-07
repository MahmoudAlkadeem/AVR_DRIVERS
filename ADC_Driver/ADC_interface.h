/**************************************************************************************************
 * Title          :          ADC Driver                                                           *
 * Description    :          header file for the AVR ADC interface                                *
 * File Name      :          ADC_interface.h                                                      *
 * Author         :          Mahmoud Elkadeem                                                     *
 * Origin Date    :          07/03/2024                                                           *
 * Note           :          None                                                                 *
 **************************************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/***************************************************************************************************
 *                                      Types Declaration                                          *
 ***************************************************************************************************/
typedef enum{
	ADC_VREF_AREF,
	ADC_VREF_AVCC,
	ADC_VREF_RESERVED,
	ADV_VREF_2_56
}ADC_vRefrence_enum;

typedef enum{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
}ADC_channelNum_enum;

/***************************************************************************************************
 *                                        Definitions                                              *
 ***************************************************************************************************/
#define ADC_REF_VOLT_VALUE     5
#define ADC_MAXIMUM_VALUE    1023

/***************************************************************************************************
 *                                    Functions Prototypes                                         *
 ***************************************************************************************************/

void ADC_voidInit(ADC_vRefrence_enum copy_enumVoltRefrence);

void ADC_voidStartConv(ADC_channelNum_enum copy_enumChannelNum);

volatile u16 ADC_u16ReadDigitalValue(void);

void ADC_voidSetCallBack(volatile void (*ptrToFun)(void));



#endif /* ADC_INTERFACE_H_ */
/***************************************************************************************************
 *                                         File End                                                *
 ***************************************************************************************************/
