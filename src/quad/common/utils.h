#ifndef __UTILS_H
#define __UTILS_H

#define ARRAYLEN(x)					(sizeof(x) / sizeof((x)[0]))
#define ARRAYEND(x)					(&(x)[ARRAYLEN(x)])

#define CONCAT_HELPER(x, y)			x ## y
#define CONCAT(x, y)				CONCAT_HELPER(x, y)

#define BIT(x)						(1 << (x))

#define BX_(x)						((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))
#define BITCOUNT(x)					(((BX_(x) + (BX_(x) >> 4)) & 0x0F0F0F0F) % 255)


/*
 * https://groups.google.com/forum/?hl=en#!msg/comp.lang.c/attFnqwhvGk/sGBKXvIkY3AJ
 * Return (v ? floor(log2(v)) : 0) when 0 <= v < 1<<[8, 16, 32, 64].
 * Inefficient algorithm, intended for compile-time constants.
 */
 #define LOG2_8BIT(v)				(8 - 90 / (((v) / 4 + 14) | 1) - 2 / ((v) / 2 + 1))
 #define LOG2_16BIT(v)				(8 * ((v) > 255/* 2^8 */) + LOG2_8BIT((v) >> 8 * ((v) > 255)))
 #define LOG2_32BIT(v)				(16 * ((v) > 65535L/* 2^16 */) + LOG2_16BIT((v) * 1L >> 16 * ((v) > 65535L)))

#endif	// __UTILS_H
