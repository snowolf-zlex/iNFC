/** 
 * NFC for Arduino
 * 免接触式射频识别（RFID）
 * Near Field Communication
 */

#include <SPI.h> 
#include <MFRC522.h>

// 引脚初始化
const int CHIP_SELECT_PIN = 10;
const int NRSTPD = 5;

MFRC522 rfid(CHIP_SELECT_PIN, NRSTPD);

void setup() {
  Serial.begin(9600);
  SPI.begin();

  pinMode(CHIP_SELECT_PIN, OUTPUT);
  digitalWrite(CHIP_SELECT_PIN, LOW);
  pinMode(NRSTPD, OUTPUT);
}

void loop(){ 
}


void showCardID(unsigned char *id) {
    int IDlen = 4;
    for(int i = 0; i<IDlen; i++){
        Serial.print(0x0F & (id[i]>>4), HEX);
        Serial.print(0x0F & id[i],HEX);
    }
    Serial.println("");
}


void showCardType(unsigned char *type) {
    Serial.print("Card type: ");
    if(type[0]==0x04&&type[1]==0x00) { 
        Serial.println("MFOne-S50");
    } else if(type[0]==0x02&&type[1]==0x00) {
        Serial.println("MFOne-S70");
    } else if(type[0]==0x44&&type[1]==0x00) {
        Serial.println("MF-UltraLight");
    } else if(type[0]==0x08&&type[1]==0x00) {
        Serial.println("MF-Pro");
    } else if(type[0]==0x44&&type[1]==0x03) {
        Serial.println("MF Desire");
    } else {
        Serial.println("Unknown");
    }
}

