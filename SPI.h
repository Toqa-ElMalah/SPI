/*
 * SPI.h
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_Masterinit (void);
void SPI_Slaveinit (void);
unsigned char SPI_MasterTransmitchar (unsigned char data);
unsigned char SPI_SlaveReceivechar (unsigned char data);
void SPI_MasterTransmitstring (unsigned char *ptr);

#endif /* SPI_H_ */