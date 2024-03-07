/*
 * GI_interface.h
 *
 *  Created on: ٠٣‏/٠٣‏/٢٠٢٤
 *      Author: Mahmoud Elkadeem
 */

#ifndef GI_INTERFACE_H_
#define GI_INTERFACE_H_

#include "std_types.h"

#define SREG_reg   (*(volatile u8*)0x5f)

void GI_voidEnableGlobalInterrupt();
void GI_voidDisableGlobalInterrup();



#endif /* GI_INTERFACE_H_ */
