/*
 * common.h
 *
 *  Created on: 29 апр. 2018 г.
 *      Author: res
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>

#define MAKE_STR2(val)	#val
#define MAKE_STR(val)	MAKE_STR2(val)

void print_hex_word(const unsigned char* const ptr, uint32_t size);

#endif /* COMMON_H_ */
