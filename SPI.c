/*
 * SPI.c
 */ 
#include "std_macrous.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


void SPI_Masterinit (void){
	DIO_vsetPINDir('B',4,1);
	DIO_vsetPINDir('B',5,1);
	DIO_vsetPINDir('B',7,1);
	/*enable master mode*/
	SET_BIT(SPCR,MSTR);
	/*set clk fos/16 */
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPE);
	/*set ss to high*/
	DIO_write('B',4,1);
}

void SPI_Slaveinit (void){
	SET_BIT(SPCR,SPE);
	/*set MISO as o/p */
	DIO_vsetPINDir('B',6,1);
}

unsigned char SPI_MasterTransmitchar (unsigned char data){
	DIO_write('B',4,0);
	SPDR=data;
	/* wait until transmission finished */
	while (READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}	

unsigned char SPI_SlaveReceivechar (unsigned char data){
	SPDR=data;
	/* wait until data is received */
	while (READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}

void SPI_MasterTransmitstring (unsigned char *ptr){
	while (*ptr != '\0'){
		SPI_MasterTransmitstring(*ptr);
		_delay_ms(300);
		ptr++;
	}
}