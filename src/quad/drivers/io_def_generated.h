#ifndef __IODEF_GENERATED_H
#define __IODEF_GENERATED_H

#include "target.h"
#include "iodef.h"
#include "utils.h"

#if defined(TARGET_IO_PORTA)
#define DEFIO_PORT_A_USED_MASK			TARGET_IO_PORTA
#define DEFIO_PORT_A_USED_COUNT			BITCOUNT(DEFIO_PORT_A_USED_MASK)
#else
#define DEFIO_PORT_A_USED_MASK			0
#define DEFIO_PORT_A_USED_COUNT			0
#endif
#define DEFIO_PORT_A_OFFSET				(0)

#if defined(TARGET_IO_PORTB)
#define DEFIO_PORT_B_USED_MASK			TARGET_IO_PORTB
#define DEFIO_PORT_B_USED_COUNT			BITCOUNT(DEFIO_PORT_B_USED_MASK)
#else
#define DEFIO_PORT_B_USED_MASK			0
#define DEFIO_PORT_B_USED_COUNT			0
#endif
#define DEFIO_PORT_B_OFFSET				(DEFIO_PORT_A_USED_COUNT)

#if defined(TARGET_IO_PORTC)
#define DEFIO_PORT_C_USED_MASK			TARGET_IO_PORTC
#define DEFIO_PORT_C_USED_COUNT			BITCOUNT(DEFIO_PORT_C_USED_MASK)
#else
#define DEFIO_PORT_C_USED_MASK			0
#define DEFIO_PORT_C_USED_COUNT			0
#endif
#define DEFIO_PORT_C_OFFSET				(DEFIO_PORT_A_USED_COUNT + DEFIO_PORT_B_USED_COUNT)

#if defined(TARGET_IO_PORTD)
#define DEFIO_PORT_D_USED_MASK			TARGET_IO_PORTD
#define DEFIO_PORT_D_USED_COUNT			BITCOUNT(DEFIO_PORT_D_USED_MASK)
#else
#define DEFIO_PORT_D_USED_MASK			0
#define DEFIO_PORT_D_USED_COUNT			0
#endif
#define DEFIO_PORT_D_OFFSET				(DEFIO_PORT_A_USED_COUNT + DEFIO_PORT_B_USED_COUNT + DEFIO_PORT_C_USED_COUNT)

/* DEFIO_GPIOID__<port> maps to port index */
#define DEFIO_GPIOID__A					0
#define DEFIO_GPIOID__B					1
#define DEFIO_GPIOID__C					2
#define DEFIO_GPIOID__D					3
#define DEFIO_GPIOID__E					4
#define DEFIO_GPIOID__F					5
#define DEFIO_GPIOID__G					6

/* LED4 */
#if DEFIO_PORT_D_USED_MASK & BIT(12)
#define DEFIO_TAG__PD12					DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 12)
#else
#define DEFIO_TAG__PD12					defio_error_PD12_is_not_supported_on_TARGET
#endif

/* LED3 */
#if DEFIO_PORT_D_USED_MASK & BIT(13)
#define DEFIO_TAG__PD13					DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 13)
#else
#define DEFIO_TAG__PD13					defio_error_PD13_is_not_supported_on_TARGET
#endif

/* LED5 */
#if DEFIO_PORT_D_USED_MASK & BIT(14)
#define DEFIO_TAG__PD14					DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 14)
#else
#define DEFIO_TAG__PD14					defio_error_PD14_is_not_supported_on_TARGET
#endif

/* LED6 */
#if DEFIO_PORT_D_USED_MASK & BIT(15)
#define DEFIO_TAG__PD15					DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 15)
#else
#define DEFIO_TAG__PD15					defio_error_PD15_is_not_supported_on_TARGET
#endif

#define DEFIO_IO_USED_COUNT				(DEFIO_PORT_A_USED_COUNT + DEFIO_PORT_B_USED_COUNT + DEFIO_PORT_C_USED_COUNT + DEFIO_PORT_D_USED_COUNT)

/* 
 *	DEFIO_PORT_USED_LIST 	- comma separated list of bitmask for all used ports
 *  DEFIO_PORT_OFFSET_LIST 	- comma separated list of port offsets (count of pins before this port)
 *  unused ports on the end of list are skipped
 */
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_D_USED_COUNT > 0
#define DEFIO_PORT_USED_COUNT			4
#define DEFIO_PORT_USED_LIST			DEFIO_PORT_A_USED_MASK, DEFIO_PORT_B_USED_MASK, DEFIO_PORT_C_USED_MASK, DEFIO_PORT_D_USED_MASK
#define DEFIO_PORT_OFFSET_LIST			DEFIO_PORT_A_OFFSET, DEFIO_PORT_B_OFFSET, DEFIO_PORT_C_OFFSET, DEFIO_PORT_D_OFFSET
#endif

#if !defined DEFIO_PORT_USED_LIST
# warning "No pins are defined. Did you forget to define TARGET_TO_PORTx in target.h"
#define DEFIO_PORT_USED_COUNT			0
#define DEFIO_PORT_USED_LIST			/* empty */
#define DEFIO_PORT_OFFSET_LIST			/* empty */
#endif

#endif	// __IODEF_GENERATED_H
