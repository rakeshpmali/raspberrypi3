/** SPI protocol to send APDU to slave.
 *  Master to slave: [LEN][Tx-APDU]
 *  Slave to master: [LEN][Rx-Response]
 *  
 *  Default data is 00, which indicates slave not ready.
 *  
 *  At present Slave only supports two INS
 *  INS = 0, indicates ENCRYPTION.
 *  INS = 1, indicates DECRYPTION.
 *  Any other data will respond with same data as sent in APDU.
 */

/**
 * Interface details:
 * 
 *  +--------------+--------------+--------------+
 *  |      RR      |     MCU      |   Function   |
 *  +==============+==============+==============+
 *  |      7       |      D7      |     MOSI     |
 *  +--------------+--------------+--------------+
 *  |      8       |     GND      |      GND     |
 *  +--------------+--------------+--------------+
 *  |     15       |      D8      |      nCS     |
 *  +--------------+--------------+--------------+
 *  |     29       |      D5      |      CLK     |
 *  +--------------+--------------+--------------+
 *  |     30       |    D1(D2)    |   ISO_RESET  |
 *  +--------------+--------------+--------------+
 *  |     33       |     3V3      |      VCC     |
 *  +--------------+--------------+--------------+
 *  |     34       |      D6      |     MISO     |
 *  +==============+==============+==============+
 */
 
#include <SPI.h>

#define FLASH_PIN 0
#define UICC_RESET 5

#define LEN 0
#define CLA 1
#define INS 2
#define P1  3
#define P2  4
#define P3  5

#define DUMMY 0

#define CS_LOW
#define CS_HIGH

#define INS_ENCRYPTION 0
#define INS_DECRYPTION 1

unsigned char g_apduTx[] = {21, 0x01, 0x02, 0x03, 0x04, 0x10,
                          0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
                          0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78, 0x89};
unsigned char g_rxData[0x20];

unsigned int len = 1;
boolean loopHere = false;
unsigned char serData[20] = {0, 0x01, 0x00, 0x00, 0x00, 0x00};

void performUiccReset(void){
  digitalWrite(UICC_RESET, 0);
  delay(100);
  digitalWrite(UICC_RESET, 1);
}

void setup() {
  // put your setup code here, to run once:

  pinMode(FLASH_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  pinMode(UICC_RESET, OUTPUT); 

  Serial.begin(9600);

  //spi.setup(1, spi.MASTER, spi.CPOL_HIGH, spi.CPHA_HIGH, 8, 20, spi.FULLDUPLEX);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setFrequency(10000);
  
  performUiccReset();
}

/**
 * Receives data from Slave.
 * Fist loop waits till slave sends [LEN].
 * Second loop waits till [LEN] bytes are received from slave.
 * The second loop considers that, slave is ready with data, and each SPI transfer will return valid data.
 * @param resp Buffer to hold response.
 * @param len Pointer to return response length.
 */
void rx_spi(unsigned char* resp, unsigned int* len){
  unsigned int rxBytes = 0;
  // receiving 00 from slave is indication for not ready signal.
  do{
    delay(10);
    *len = SPI.transfer(DUMMY);
  }while(*len == DUMMY);

  // Debug code
  Serial.print("-");
  Serial.print(*len);
  Serial.print(" ");

  // *len has length of data being sent from slave.
  do{
    unsigned char retVal = SPI.transfer(DUMMY);
    resp[rxBytes] = retVal;
    rxBytes++;
  }while(rxBytes != *len);
}

/**
 * This function sends APDU and gets response from slave.
 * @param apdu APDU to be sent to slave in [LEN][APDU] format.
 * @param rxLen pointer which holds response length.
 * @param resp buffer which holds response.
 */
void send_iso_case_4(unsigned char* apdu, unsigned int* rxLen, unsigned char* resp){
  unsigned int i;
  CS_LOW;

  // Loop to transfer [LEN][APDU]
  for(i = 0; i < g_apduTx[0]+1; i++){
    SPI.transfer(g_apduTx[i]);
    Serial.print(g_apduTx[i]);
    Serial.print("+");
  }

  delay(10);

  // Function to get [LEN][Response]
  rx_spi(g_rxData, rxLen);

  // Debug print
  for(i = 0; i < *rxLen; i++){
    Serial.print(resp[i], HEX);
    Serial.print(" ");
  }

  CS_HIGH;
}

void loop() {
  if(Serial.available()){
    loopHere = true;
    do{
      int data = Serial.read();
      if(data == '\n'){
        // end of data.
        serData[0] = len + 5 + 1;
        serData[INS] = INS_ENCRYPTION;
        serData[P3] = len;
        send_iso_case_4(serData, &len, g_rxData);
        Serial.println("...end");
        loopHere = false;
        len = 1;
      } else {
        serData[len++] = data;
      }
    }while(loopHere);
  }

  if(digitalRead(FLASH_PIN)){
      digitalWrite(LED_BUILTIN, 1);
    } else {
      unsigned int rxLen = 6;
      unsigned int i;
      digitalWrite(LED_BUILTIN, 0);
      //SPI.transfer(0xAA);  
      g_apduTx[INS] = 2;
      send_iso_case_4(g_apduTx, &rxLen, g_rxData);
      Serial.print(rxLen);
      Serial.println("...end");
      delay(10);

      
      g_apduTx[INS] = INS_ENCRYPTION;
      send_iso_case_4(g_apduTx, &rxLen, g_rxData);
      Serial.print(rxLen);
      Serial.println("...end");
      delay(10);

      g_apduTx[INS] = INS_ENCRYPTION;
      send_iso_case_4(g_apduTx, &rxLen, g_rxData);
      Serial.print(rxLen);
      Serial.println("...end");
      delay(10);     
      
      g_apduTx[INS] = INS_DECRYPTION;
      send_iso_case_4(g_apduTx, &rxLen, g_rxData);
      Serial.print(rxLen);
      Serial.println("...end");

      g_apduTx[LEN] = 21-12;
      g_apduTx[P3] = 16-12;
      g_apduTx[INS] = INS_DECRYPTION;
      send_iso_case_4(g_apduTx, &rxLen, g_rxData);
      Serial.print(rxLen);
      Serial.println("...end");      

      g_apduTx[LEN] = 21-12;
      g_apduTx[P3] = 16-12;
      g_apduTx[INS] = INS_ENCRYPTION;
      send_iso_case_4(g_apduTx, &rxLen, g_rxData);
      Serial.print(rxLen);
      Serial.println("...end");
      delay(10);

      g_apduTx[LEN] = 21;
      g_apduTx[P3] = 16;
      
      delay(1000);
    }
}
