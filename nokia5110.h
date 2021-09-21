/*
	@File 		nokia5110.h
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/ 


#ifndef NOKIA5110_H_
#define NOKIA5110_H_

#include "My_Fonts/Font_0.h"
#include "My_Fonts/Font_1.h"
#include "My_Fonts/Font_2.h"

// FONTS
#include "Fonts/Font_11x14.h"

#include "Fonts_32_256/Arial_10x14.h"

#include "Fonts/Arial_10x10.h"
#include "Fonts/Arial_12x12.h"
#include "Fonts/Arial_13x13.h"
#include "Fonts/Arial_16x16.h"

#include "Fonts/Arial_Bold_10x11.h"
#include "Fonts/Arial_Bold_16x17.h"
#include "Fonts/Times_New_Roman_Bold_12x11.h"

#include "Fonts/Calibri_9x10.h"
#include "Fonts/Tahoma_10x11.h"
#include "Fonts/Times_New_Roman_11x12.h"

#include "Fonts/Ms_Serif.h"
#include "Fonts/Verdana_11x11.h"
#include "Fonts/Arial_Italic_11x12.h"

#define NOKIA5110_SCE			0
#define NOKIA5110_DC			1
#define NOKIA5110_MOSI			2
#define NOKIA5110_SCK			3

#define NOKIA5110_SCE_CLEAR		PORTC &=(unsigned char)~(1<<NOKIA5110_SCE)
#define NOKIA5110_SCE_SET		PORTC |=(1<<NOKIA5110_SCE)

#define NOKIA5110_DC_CLEAR		PORTC &=(unsigned char)~(1<<NOKIA5110_DC)
#define NOKIA5110_DC_SET		PORTC |=(1<<NOKIA5110_DC)

#define NOKIA5110_SCK_CLEAR		PORTC &=(unsigned char)~(1<<NOKIA5110_SCK)
#define NOKIA5110_SCK_SET		PORTC |=(1<<NOKIA5110_SCK)

#define NOKIA5110_SDI_CLEAR		PORTC &=(unsigned char)~(1<<NOKIA5110_MOSI)
#define NOKIA5110_SDI_SET		PORTC |=(1<<NOKIA5110_MOSI)

class NOKIA5110
{
	public:
		void spi_init();
		void spi_write(const char data);
		void Font8x8(const char data);
	
	
		void Init();
		void Cmd(unsigned char cmd);
		void Char(unsigned char data);
		void Set_Cursor(unsigned int x, unsigned int y);
		
		void WriteString(const char * data, unsigned int x, unsigned int y, const unsigned char Font[]);
		void WriteChar(unsigned char data, const unsigned char Font[]);
		void WriteInt(unsigned int data, unsigned int x, unsigned int y, const unsigned char Font[]);
		
		unsigned int Y;
		unsigned int X;
};


#endif /* NOKIA5110_H_ */
