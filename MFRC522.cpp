#include <Arduino.h>
#include <MFRC522.h>

MFRC522::MFRC522(int chipSelectPin, int NRSTPD){
	_chipSelectPin = chipSelectPin;
	_NRSTPD = NRSTPD;
}

void MFRC522::writeMFRC522(unsigned char addr, unsigned char val) {
    digitalWrite(_chipSelectPin, LOW);

    //address format：0XXXXXX0
    SPI.transfer((addr<<1)&0x7E); 
    SPI.transfer(val);
    
    digitalWrite(_chipSelectPin, HIGH);
}

unsigned char MFRC522::readMFRC522(unsigned char addr)
{
    unsigned char val;

    digitalWrite(_chipSelectPin, LOW);

    //address format：1XXXXXX0
    SPI.transfer(((addr<<1)&0x7E) | 0x80); 
    val = SPI.transfer(0x00);
    
    digitalWrite(_chipSelectPin, HIGH);
    
    return val; 
}

