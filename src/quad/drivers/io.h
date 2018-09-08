#ifndef __IO_H
#define __IO_H

#include <stdbool.h>
#include "iodef.h"
#include "IOTypes.h"
#include "resource.h"
#include "stm32f4xx_gpio.h"

/* 
 *	preprocessor is used to convert pinid to requested C data value
 * 	compile-time error is generated if requested pin is not available (not set in TARGET_IO_PORTx)
 * 	ioTag_t and IO_t is supported, but ioTag_t is preferred
 */

/* Expand pinID to ioTag_t */
#define IO_TAG(pinID)		DEFIO_TAG(pinID)

#define IO_CONFIG(mode, speed, otype, pupd)			((mode) | ((speed) << 2) | ((otype) << 4) | ((pupd) << 5))
#define IOCFG_OUT_PP								IO_CONFIG(GPIO_Mode_OUT, 0, GPIO_OType_PP, GPIO_PuPd_NOPULL)
//#define IOCFG_OUT_PP								IO_CONFIG(GPIO_Mode_OUT, GPIO_Fast_Speed, GPIO_OType_PP, GPIO_PuPd_UP)

void IOGlobalInit(void);
IO_t IOGetByTag(ioTag_t tag);
void IOInit(IO_t io, resourceOwner_e owner, uint8_t index);
void IOConfigGPIO(IO_t io, ioConfig_t cfg);
void IOWrite(IO_t io, bool hi);
bool IORead(IO_t io);
void IOHi(IO_t io);
void IOLo(IO_t io);
void IOToggle(IO_t io);

#endif	// __IO_H
