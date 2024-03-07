/*
 * GI_programm.c
 *
 *  Created on: ٠٣‏/٠٣‏/٢٠٢٤
 *      Author: Mahmoud Elkadeem
 */

#include "GI_interface.h"

void GI_voidEnableGlobalInterrupt(){
	SREG_reg |= (1<<7);

}
void GI_voidDisableGlobalInterrup(){
	SREG_reg &=~ (1<<7);

}
