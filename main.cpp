/*
	@File 		main.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "i2c.h"

#include "nokia5110.h"

NOKIA5110 nokia5110;

#define MEM_CS					0
#define MEM_WP					1
#define MEM_HOLD				2
#define MEM_SI					3
#define MEM_SO					4
#define MEM_SCK					5

#define MEM_CS_LOW				PORTB &=~(1 << MEM_CS)
#define MEM_CS_HIGH				PORTB |=(1 << MEM_CS)

#define MEM_HOLD_LOW			PORTB &=~(1 << MEM_HOLD)
#define MEM_HOLD_HIGH			PORTB |=(1 << MEM_HOLD)

class MEM
{
	public:
		
		void Serial_Command(const unsigned char cmd);
		void Write_Block(const unsigned int address, const unsigned char data);
		unsigned char Read_Block(const unsigned int address);
		
		void Serial_Write(const unsigned char data);	
		unsigned char Serial_Read();
		
		void Serial_Init();
};

void MEM::Serial_Write(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

unsigned char MEM::Serial_Read()
{
	SPDR = 0;
	while(!(SPSR & (1<<SPIF)));
	return (SPDR);
}


void MEM::Serial_Command(const unsigned char cmd)
{
	MEM_CS_LOW;
		
	Serial_Write( 0x01 );
	Serial_Write( cmd );
		
	MEM_CS_HIGH;
}

unsigned char MEM::Read_Block(const unsigned int address)
{
	MEM_CS_LOW;
	
	Serial_Write( 0x03 );
	Serial_Write( address >> 16);
	Serial_Write( address >> 8);
	Serial_Write( address & 0x0f);
	char data = Serial_Read();
	
	MEM_CS_HIGH;
	
	return data;
	
	
}

void MEM::Write_Block(const unsigned int address, const unsigned char data)
{
	Serial_Command( 0x06 );
	
	MEM_CS_LOW;

	Serial_Write( 0x02 );	
	Serial_Write( address >> 16);
	Serial_Write( address >> 8);
	Serial_Write( address & 0x0f);
	
	Serial_Write( data );	
	
	MEM_CS_HIGH;
	
	Serial_Command( 0x04 );
}

void MEM::Serial_Init()
{
	DDRB |= (1 << MEM_CS);
	DDRB |= (1 << MEM_HOLD);
	DDRB |= (1 << MEM_SO);
	DDRB |= (1 << MEM_SI);
	DDRB |= (1 << MEM_SCK);
	
	//	CHIP SELECT START 1
	//	ACTIVE: LOW
	MEM_CS_HIGH;

	MEM_HOLD_HIGH; 
	
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

#include <stdio.h>

int main(void)
{
	nokia5110.Init();

	MEM memory;
	
	memory.Serial_Init();
	
	memory.Write_Block(0, 127);
	
	char data = memory.Read_Block(0);

	nokia5110.WriteInt(data, 0, 0, Font_Arial_16x16);
	
    while(1);
}
