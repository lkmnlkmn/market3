#include "include.h"

#define false 0
#define true 1
#define DEBUG 0
/******************************************************
//	Company:���ڻö��Ƽ����޹�˾										   //	
//	���ǵĵ���:lobot-zone.taobao.com                  //
//	���ǵĹ�����www.lobot-robot.com                   //
******************************************************/
typedef unsigned char  byte;
uint8_t result_summ[128];
uint8_t current;
int readByte(u16 address)
{
	u8 val;
	IIC_start(); //����
	IIC_send_byte((CAM_DEFAULT_I2C_ADDRESS<<1)); //����дָ��
	IIC_wait_ack(); //Ӧ��
	IIC_send_byte(address & 0x00FFu); //�Ĵ�����ַ
	IIC_wait_ack(); //Ӧ��
	IIC_send_byte((address >> 8) & 0x00FFu); //�Ĵ�����ַ
	IIC_wait_ack(); //Ӧ��
	IIC_stop(); //ֹͣ
	IIC_start(); //��������
	IIC_send_byte((CAM_DEFAULT_I2C_ADDRESS<<1)+1); //���Ͷ�ָ��
	IIC_wait_ack(); //Ӧ��
	val = IIC_read_byte(0); //��ȡһ���ֽ�
	IIC_stop(); //ֹͣ
	return val;
}

void writeByte(u8 address,u8 val)
{
	IIC_start(); //��ʼ�ź�
	IIC_send_byte(0xEE); //����дָ��
	IIC_wait_ack(); //Ӧ��
	IIC_send_byte(address); //�Ĵ�����ַ
	IIC_wait_ack(); //Ӧ��
	IIC_send_byte(val); //д��ֵ
	IIC_wait_ack(); //Ӧ��
	IIC_stop(); //ֹͣ
}
#include "WonderCam.h"

void begin(void) {
}

int readFromAddr(uint16_t addr,  uint8_t *buf, uint16_t leng) {
  int len = 0,i;

  for (i = 0; i < leng; i++) {
	*buf++ = readByte(addr++); //��ȡһ���ֽ�
      ++len;
    }
//  printf("%d",len);
//  if (ls > 0) {
//	*buf++ = IIC_read_byte(0); //��ȡһ���ֽ�
//      ++len;
//	IIC_wait_ack(); //Ӧ��
//    }
  return len;
}

int writeToAddr(uint16_t addr, const uint8_t *buf, uint16_t leng) {
int i;
	IIC_start(); //��ʼ�ź�
	IIC_send_byte((CAM_DEFAULT_I2C_ADDRESS<<1)); //����дָ��
	IIC_wait_ack(); //Ӧ��
	IIC_send_byte(addr & 0x00FFu); //�Ĵ�����ַ
	IIC_wait_ack(); //Ӧ��
	IIC_send_byte((addr >> 8) & 0x00FFu); //�Ĵ�����ַ
	for(i=0;i < leng;i++){
		IIC_wait_ack(); //Ӧ��
		IIC_send_byte(*buf++); //�Ĵ�����ַ
//	printf("%x\r\n",*buf--);

	}
	IIC_wait_ack(); //Ӧ��
	IIC_stop(); //ֹͣ
  return leng;
}

bool firmwareVersion(char* str) {
  readFromAddr(0x0000, str, 16);
  return true;
}

int currentFunc(void) {
  char buf;
  readFromAddr(0x0035, &buf, 1);
  return (int)buf;
}


bool changeFunc(uint8_t new_func) {
  uint8_t count = 0;
  writeToAddr(0x0035, &new_func, 1);
  DelayMs(50);
  while (true) {
    if (currentFunc() != new_func) {
      DelayMs(50);
    } else {
      return true;
    }
    ++count;
    if (count > 80) {
      return false;
    }
  }
}

void setLed(bool new_state) {
  byte buf[3] = {0x30, 0x00, 0x00};
  byte ns_b = new_state ? 1 : 0;
  writeToAddr(0x0030, &ns_b, 1);
}

/*ʶ��������������*/
bool anyFaceDetected() {
  if (current == APPLICATION_FACEDETECT) {
    return result_summ[1] > 0 ? true : false;
  }
  return false;
}

/*ʶ�𵽵���������*/
int numOfTotalFaceDetected() {
  if (current == APPLICATION_FACEDETECT) {
    return (int)result_summ[1];
  }
  return 0;
}

bool anyLearnedFaceDetected() {
  if (current == APPLICATION_FACEDETECT) {
    return result_summ[2] > 0 ? true : false;
  }
  return false;
}

int numOfTotalLearnedFaceDetected() {
  if (current == APPLICATION_FACEDETECT) {
    return (int)result_summ[2];
  }
  return 0;
}

bool anyUnlearnedFaceDetected() {
  if (current == APPLICATION_FACEDETECT) {
    return result_summ[3] > 0 ? true : false;
  }
  return false;
}

int numOfTotalUnlearnedFaceDetected() {
  if (current == APPLICATION_FACEDETECT) {
    return (int)result_summ;
  }
  return 0;
}

bool faceOfIdDetected(uint8_t id) {
  if (current == APPLICATION_FACEDETECT) {
    for (int i = 4; i < 4 + 29; ++i) {
      if (result_summ[i] == id) {
        return true;
      }
    }
  }
  return false;
}

/*����ָ��ID������ */
bool getFaceOfId(uint8_t id,struct   WonderCamFaceDetectResult *p) {
  memset(p, 0, sizeof(struct  WonderCamFaceDetectResult));
  if (current != APPLICATION_FACEDETECT) {
    return false;
  }
  for (int i = 4; i < 4 + 29; ++i) {
    if (result_summ[i] == id) {
      uint16_t index = i - 4;
      index = 0x30 + index * 16;
      readFromAddr(0x0400 + index, (void*)p, 16);
      return true;
    }
  }
  return false;
}

/*����ָ����ŵ�û��ID������*/
bool getFaceOfIndex(uint8_t index,struct   WonderCamFaceDetectResult *p) {
  memset(p, 0, sizeof(struct  WonderCamFaceDetectResult));
  if (current != APPLICATION_FACEDETECT) {
    return false;
  }
  for (int i = 4; i < 4 + 29; ++i) {
    if (result_summ[i] == 0xFF) {
      --index;
      if (index == 0) {
        uint16_t index_ = i - 4;
        index_ = 0x30 + index_ * 16;
        readFromAddr(0x0400 + index_, (void*)p, 16);
        return true;
      }
    }
  }
  return false;
}

/* ʶ��������Ʒ��*/
bool anyObjDetected() {
  if (current != APPLICATION_OBJDETECT) {
    return false;
  }
  return result_summ[1] > 0 ? true : false;
}

int numOfObjDetected() {
  if (current != APPLICATION_OBJDETECT) {
    return 0;
  }
  return (int8_t)(result_summ[1]);
}

bool objIdDetected(uint8_t id) {
  if (current != APPLICATION_OBJDETECT) {
    return false;
  }
  for (int i = 2; i < 2 + 29; ++i) {
    if (result_summ[i] == id) {
      return true;
    }
  }
  return false;
}

int numOfObjIdDetected(uint8_t id) {
  if (current != APPLICATION_OBJDETECT) {
    return 0;
  }
  int count = 0;
  for (int i = 2; i < 2 + 29; ++i) {
    if (result_summ[i] == id) {
      ++count;
    }
  }
  return count;
}

bool objDetected(uint8_t id, uint8_t index, struct  WonderCamObjDetectResult *p) {
  memset(p, 0, sizeof(struct  WonderCamObjDetectResult));
  if (current != APPLICATION_OBJDETECT) {
    return false;
  }
  for(int i = 2; i < 2 + 29; ++i) {
    if(result_summ[i] ==id) {
      --index;
    }
    if(index == 0) {
      int r = readFromAddr(0x0800 + 48 + ((i - 2) * 16), (uint8_t*)p, 16);
      if(r != 16) {
        return false;
      }
      return true;
    }
  }
}
//
int classIdOfMaxProb() {
  if (current != APPLICATION_CLASSIFICATION) {
    return 0;
  }
  return (int8_t)result_summ[1];
}
//
float classMaxProb() {
  uint16_t prob_u16;
  if (current != APPLICATION_CLASSIFICATION) {
    return 0;
  }
  memcpy(&prob_u16, &result_summ[2], 2);
  return ((float)((int)(prob_u16))) / 10000.0;
}
//
float classProbOfId(uint8_t id) {
  uint16_t prob_u16;
  if (current != APPLICATION_CLASSIFICATION) {
    return 0;
  }
  memcpy(&prob_u16, &result_summ[16 + (id - 1) * 4], 2);
  return ((float)((int)(prob_u16))) / 10000.0;
}

int featureIdOfMaxProb() {
  if (current != APPLICATION_FEATURELEARNING) {
    return 0;
  }
  return (int8_t)result_summ[1];
}

float featureMaxProb() {
  uint16_t prob_u16;
  if (current != APPLICATION_FEATURELEARNING) {
    return 0;
  }
  memcpy(&prob_u16, &result_summ[2], 2);
  return ((float)((int)(prob_u16))) / 10000.0;
}

float featureProbOfId(uint8_t id) {
  uint16_t prob_u16;
  if (current != APPLICATION_FEATURELEARNING) {
    return 0;
  }
  memcpy(&prob_u16, &result_summ[16 + (id - 1) * 4], 2);
  return ((float)((int)(prob_u16))) / 10000.0;
}


bool anyTagDetected(void) {
  if (current != APPLICATION_APRILTAG) {
    return false;
  }
  return result_summ[1] > 0 ? true : false;
}

int numOfTotalTagDetected(void) {
  if (current != APPLICATION_APRILTAG) {
    return 0;
  }
  return result_summ[1];
}

bool tagIdDetected(uint16_t id) {
  if (current != APPLICATION_APRILTAG) {
    return false;
  }
  int num = result_summ[1];
  for (int i=2; i < 2 + num; ++i) {
    if (result_summ[i] == id) {
      return true;
    }
  }
  return false;
}

int numOfTagIdDetected(uint16_t id) {
  int count = 0;
  if (current != APPLICATION_APRILTAG) {
    return 0;
  }
  int num = result_summ[1];
  for (int i = 2; i < 2 +  num; ++i) {
    if (result_summ[i] == id) {
      ++count;
    }
  }
  return count;
}

bool tagId(uint16_t id, int index,struct  WonderCamAprilTagResult *p) {
  memset(p, 0, 32);
  if (current != APPLICATION_APRILTAG) {
    return false;
  }
  int num = result_summ[1];
  for (int i = 2; i < 2 + num; ++i) {
    if (result_summ[i] == id) {
      --index;
      if (index == 0) {
        readFromAddr(0x1E00 + 0x30 + 0x32 * (i - 2), (void*)p, 32);
        return true;
      }
    }
  }
  return false;
}



//�Ƿ�ɨ�赽QRCode
bool qrCodeDetected(void) {

  if (current != APPLICATION_QRCODE) {
    return false;
  }
  return result_summ[1] > 0 ? true : false;
}

//QRCode�����ݳ���
int qrCodeDataLength(void) {
struct  WonderCamQrCodeResultSumm *p = (void*)result_summ;
  if (current != APPLICATION_QRCODE) {
    return 0;
  }
  return (int)p->len;
}

//��ȡQrcode������
int qrCodeData(uint8_t *buf) {
  int len, ret;
struct  WonderCamQrCodeResultSumm *p = (void*)result_summ;
  len = p->len;
  buf[0] = '\0';
  if (current != APPLICATION_QRCODE) {
    return 0;
  }
  if (!qrCodeDetected()) {
    return 0;
  }
  ret = readFromAddr(0x1800 + 48, buf, len);
  return ret;
}

//�Ƿ�ɨ�赽barCode
bool barCodeDetected(void) {

  if (current != APPLICATION_BARCODE) {
    return false;
  }
  return result_summ[1] > 0 ? true : false;
}

//BarCode�����ݳ���
int barCodeDataLength(void) {
struct  WonderCamQrCodeResultSumm *p = (void*)result_summ;
  if (current != APPLICATION_BARCODE) {
    return 0;
  }
  return (int)p->len;
}

//��ȡBarcode������
int barCodeData(uint8_t *buf) {
  int len, ret;
struct  WonderCamQrCodeResultSumm *p = (void*)result_summ;
  len = p->len;
  buf[0] = '\0';
  if (current != APPLICATION_BARCODE) {
    return 0;
  }
  if (!barCodeDetected()) {
    return 0;
  }
  ret = readFromAddr(0x1C00 + 48, buf, len);
  return ret;
}

/* �Ƿ�ʶ������ɫ */
bool anyColorDetected(void) {
  if (current != APPLICATION_COLORDETECT) {
    return false;
  }
  return result_summ[1] > 0 ? true : false;
}

/* ʶ�𵽵���ɫ���� */
int numOfColorDetected(void) {
  if (current != APPLICATION_COLORDETECT) {
    return 0;
  }
  return result_summ[1];
}

/* �Ƿ�ʶ����ָ����ɫ*/
bool colorIdDetected(uint8_t id) {
	int i,num;
  if (current != APPLICATION_COLORDETECT) {
    return false;
  }
   num = result_summ[1];
  for ( i = 2; i < 2 + num; ++i) {
    if (result_summ[i] == id) {
      return true;
    }
  }
  return false;
}

/* ��ȡָ����ʶ�𵽵���ɫ��λ������ */
bool colorId(uint8_t id, struct WonderCamColorDetectResult *p) {
	int num,i,r;
  memset(p, 0, sizeof(struct WonderCamColorDetectResult));
  if (current != APPLICATION_COLORDETECT) {
    return false;
  }
  if (!anyColorDetected()) {
    return false;
  }
   num = result_summ[1];
  for ( i = 2; i < 2 + num; ++i) {
    if (result_summ[i] == id) {
       r = readFromAddr(0x1000 + 48 + (16 * (i - 2)), (void*)p, 16);
      return r == 16 ? true : false;
    }
  }
}

/* �Ƿ�ʶ������ */
bool anyLineDetected(void) {
  if (current != APPLICATION_LINEFOLLOW) {
    return false;
  }
  return result_summ[1] > 0 ? true : false;
}

/* ʶ�𵽵������� */
int numOfLineDetected(void) {
  if (current != APPLICATION_LINEFOLLOW) {
    return 0;
  }
  return result_summ[1];
}

/* �Ƿ�ʶ����ָ����*/
bool lineIdDetected(uint8_t id) {
	int i,num;
  if (current != APPLICATION_LINEFOLLOW) {
    return false;
  }
   num = result_summ[1];
  for (i = 2; i < 2 + num; ++i) {
    if (result_summ[i] == id) {
      return true;
    }
  }
  return false;
}

/* ��ȡָ����ʶ�𵽵���λ������ */
bool lineId(uint8_t id, struct WonderCamLineResult *p) {
  memset(p, 0, sizeof(struct WonderCamLineResult));
  if (current != APPLICATION_LINEFOLLOW) {
    return false;
  }
  if (!anyLineDetected()) {
    return false;
  }
  int num = result_summ[1];
  for (int i = 2; i < 2 + num; ++i) {
    if (result_summ[i] == id) {
      int r = readFromAddr(0x1400 + 48 + (16 * (i - 2)), (void*)p, 16);
      if (r != 16) {
        return false;
      }
      p->angle = p->angle > 90 ? p->angle - 180 : p->angle;
      p->offset = abs(p->offset) - 160;
      return true;
    }
  }
}

//���½��
bool updateResult(void) {
  readFromAddr(0x0035, &current, 1);
  switch (current) {
    case APPLICATION_FACEDETECT: {
        readFromAddr(0x0400, result_summ, 48);
        break;
      };
    case APPLICATION_OBJDETECT: {
        readFromAddr(0x0800, result_summ, 48);
        break;
      }
    case APPLICATION_CLASSIFICATION: {
        readFromAddr(0x0C00, result_summ, 128);
        break;
      }
    case APPLICATION_FEATURELEARNING: {
        readFromAddr(0x0E00, result_summ, 64);
        break;
      }
    case APPLICATION_COLORDETECT: {
        readFromAddr(0x1000, result_summ, 48);
        break;
      }
    case APPLICATION_LINEFOLLOW: {
        readFromAddr(0x1400, result_summ, 48);
        break;
      }
    case APPLICATION_APRILTAG: {
        readFromAddr(0x1E00, result_summ, 48);
        break;
      }
    case APPLICATION_QRCODE: {
        readFromAddr(0x1800, result_summ, 48);
        break;
      }
    case APPLICATION_BARCODE: {
        readFromAddr(0x1C00, result_summ, 48);
      }
    default: {
        break;
      }
  }
     

#if DEBUG  
  for(int i =0; i <= 48; i++){
  	printf("%x",result_summ[i]);
	  }
	  printf("\r\n");
#endif
  return true;
}
