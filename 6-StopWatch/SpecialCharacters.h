/*
 * SpecialCharacters.h
 *
 *  Created on: Jul 4, 2023
 *      Author: DeLL
 */

#ifndef SPECIALCHARACTERS_H_
#define SPECIALCHARACTERS_H_

	/* Arrow pattern binary representation */
	uint8 Local_u8ArrowPatternArr[8]= {0b00000100,0b00001110,0b00011111,0b00000100,0b00000100,0b00000100,0b00000100,0b00000000};
	/* Delete Arrow pattern binary representation */
	uint8 Local_u8ArrowPatternDeletedArr[8]= {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};

	uint8 Local_u8HamokshaArr[8]={0x0E,0x0E,0x0E,0x04,0x1F,0x04,0x04,0x1F};
#endif /* SPECIALCHARACTERS_H_ */
