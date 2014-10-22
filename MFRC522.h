/*
 * MFRC522 for Arduino
 */
 
#ifndef MFRC522_h
#define MFRC522_h


#include <Arduino.h>
#include <SPI.h>

/*
 * 定义
 */
#define     MAX_LEN               16                 // 数组最大长度

// MFRC522命令字
#define     PCD_IDLE              0x00               // 无动作，取消当前命令
#define     PCD_AUTHENT           0x0E               // 验证密钥
#define     PCD_RECEIVE           0x08               // 接收数据
#define     PCD_TRANSMIT          0x04               // 发送数据
#define     PCD_TRANSCEIVE        0x0C               // 发送并接收数据
#define     PCD_RESETPHASE        0x0F               // 复位
#define     PCD_CALCCRC           0x03               // CRC计算

// Mifare_One卡片命令字
#define     PICC_REQIDL           0x26               // 寻天线区内未进入休眠状态
#define     PICC_REQALL           0x52               // 寻天线区内全部卡
#define     PICC_ANTICOLL         0x93               // 防冲撞
#define     PICC_SElECTTAG        0x93               // 选卡
#define     PICC_AUTHENT1A        0x60               // 验证A密钥
#define     PICC_AUTHENT1B        0x61               // 验证B密钥
#define     PICC_READ             0x30               // 读块
#define     PICC_WRITE            0xA0               // 写块
#define     PICC_DECREMENT        0xC0               
#define     PICC_INCREMENT        0xC1               
#define     PICC_RESTORE          0xC2               // 调块数据到缓冲区
#define     PICC_TRANSFER         0xB0               // 保存缓冲区中数据
#define     PICC_HALT             0x50               // 休眠

// 与MFRC522通讯时返回的错误代码
#define     MI_OK                 0
#define     MI_NOTAGERR           1
#define     MI_ERR                2

//------------------MFRC522寄存器---------------
// Page 0:Command and Status
#define     Reserved00            0x00    
#define     CommandReg            0x01    
#define     CommIEnReg            0x02    
#define     DivlEnReg             0x03    
#define     CommIrqReg            0x04    
#define     DivIrqReg             0x05
#define     ErrorReg              0x06    
#define     Status1Reg            0x07    
#define     Status2Reg            0x08    
#define     FIFODataReg           0x09
#define     FIFOLevelReg          0x0A
#define     WaterLevelReg         0x0B
#define     ControlReg            0x0C
#define     BitFramingReg         0x0D
#define     CollReg               0x0E
#define     Reserved01            0x0F

// Page 1:Command     
#define     Reserved10            0x10
#define     ModeReg               0x11
#define     TxModeReg             0x12
#define     RxModeReg             0x13
#define     TxControlReg          0x14
#define     TxAutoReg             0x15
#define     TxSelReg              0x16
#define     RxSelReg              0x17
#define     RxThresholdReg        0x18
#define     DemodReg              0x19
#define     Reserved11            0x1A
#define     Reserved12            0x1B
#define     MifareReg             0x1C
#define     Reserved13            0x1D
#define     Reserved14            0x1E
#define     SerialSpeedReg        0x1F

// Page 2:CFG    
#define     Reserved20            0x20  
#define     CRCResultRegM         0x21
#define     CRCResultRegL         0x22
#define     Reserved21            0x23
#define     ModWidthReg           0x24
#define     Reserved22            0x25
#define     RFCfgReg              0x26
#define     GsNReg                0x27
#define     CWGsPReg              0x28
#define     ModGsPReg             0x29
#define     TModeReg              0x2A
#define     TPrescalerReg         0x2B
#define     TReloadRegH           0x2C
#define     TReloadRegL           0x2D
#define     TCounterValueRegH     0x2E
#define     TCounterValueRegL     0x2F

// Page 3:TestRegister     
#define     Reserved30            0x30
#define     TestSel1Reg           0x31
#define     TestSel2Reg           0x32
#define     TestPinEnReg          0x33
#define     TestPinValueReg       0x34
#define     TestBusReg            0x35
#define     AutoTestReg           0x36
#define     VersionReg            0x37
#define     AnalogTestReg         0x38
#define     TestDAC1Reg           0x39  
#define     TestDAC2Reg           0x3A   
#define     TestADCReg            0x3B   
#define     Reserved31            0x3C   
#define     Reserved32            0x3D   
#define     Reserved33            0x3E   
#define     Reserved34            0x3F
//-----------------------------------------------

class MFRC522 {
public:
  // 构造
  MFRC522(int chipSelectPin, int NRSTPD);

//  // 卡校验
//  bool isCard();
//
//  // 读卡序列号
//  bool readCardSerial();
//
//  // 卡初始化
//  void init();
//
//  // 卡重置
//  void reset();
//
//  // 设置掩码
//  void setBitMask(unsigned char reg, unsigned char mask);
//
//  // 清除掩码
//  void clearBitMask(unsigned char reg, unsigned char mask);
//
//  // 打开天线
//  void antennaOn(void);
//
//  // 关闭天线
//  void antennaOff(void);
//
//  // 计算CRC
//  void calculateCRC(unsigned char *pIndata, unsigned char len, unsigned char *pOutData);
//
  // 写卡
  void writeMFRC522(unsigned char addr, unsigned char val);

  // 读卡
  unsigned char readMFRC522(unsigned char addr);
//
//  // 寻卡
//  unsigned char MFRC522Request(unsigned char reqMode, unsigned char *tagType);
//
//  // RC522与ISO14443卡通讯
//  unsigned char MFRC522ToCard(unsigned char command, unsigned char *sendData, unsigned char sendLen, unsigned char *backData, unsigned int *backLen);
//
//  // 防冲突检测
//  unsigned char anticoll(unsigned char *serNum);
//
//  // 验证卡片密码
//  unsigned char auth(unsigned char authMode, unsigned char blockAddr, unsigned char *sectorkey, unsigned char *serNum);
//
//  // 读块数据
//  unsigned char read(unsigned char blockAddr, unsigned char *recvData);
//
//  // 写块数据
//  unsigned char write(unsigned char blockAddr, unsigned char *writeData);
//
//  // 选卡，读取卡存储器容量
//  unsigned char selectTag(unsigned char *serNum);
//
//  // 卡休眠
//  void halt();
//
  // 4字节卡序列号，第5字节为校验字节
  unsigned char serNum[5];

private:
  int _chipSelectPin;
  int _NRSTPD;
  
};


#endif

