/*
 * This sketch creates a BLE server on the ESP32 board that emulates the characteristics and services of the DT78 watch
 * this will enable the ESP32 connect to the WearFit 2.0 app
 * 
 */

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#define BUILTINLED 2

// // HW21 Paramters
// uint8_t cmd1[] = { 0xab, 0x00, 0x04, 0xff, 0x87, 0x80, 0x01}; // unknown
// uint8_t id[] = { 0xab, 0x00, 0x11, 0xff, 0x92, 0xc0, 0x01, 0x01, 0x00, 0x87, 0x53, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xe2, 0x07, 0x80}; //identifier
// uint8_t st[] = { 0xab, 0x00, 0x11, 0xff, 0x9b, 0x00, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //Settings

// X8 Ultra Paramters
uint8_t cmd1[] = { 0xab, 0x00, 0x04, 0xff, 0x87, 0x80, 0x01}; // unknown
uint8_t id[] = { 0xab, 0x00, 0x11, 0xff, 0x92, 0xc0, 0x01, 0x01, 0x00, 0x89, 0x3c, 0x01, 0x00, 0x00, 0x00, 0x28, 0x00, 0xe2, 0x15, 0x80}; //identifier
uint8_t st[] = { 0xab, 0x00, 0x11, 0xff, 0x9b, 0x00, 0x20, 0x01, 0xb6, 0x87, 0xdb, 0x12, 0x20, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //Settings

uint8_t resp[] = {0xab, 0x00, 0x06, 0xff, 0xa7, 0x80, 0x02, 0x05, 0x07};


uint8_t bat80[] = {0xAB, 0x00, 0x05, 0xFF, 0x91, 0x80, 0x00, 0x50}; //bat 80%

static bool rsp = false;

#define SERVICE_UUID        "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID_RX "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID_TX "6e400003-b5a3-f393-e0a9-e50e24dcca9e"

#define WEARFIT_UUID "0000fee7-0000-1000-8000-00805f9b34fb"
#define ANCS_UUID "7905f431-b5ce-4e99-a40f-4b1e122d00d0"

static BLECharacteristic* pCharacteristicTX;
static BLECharacteristic* pCharacteristicRX;
static bool deviceConnected = false;

class MyServerCallbacks: public BLEServerCallbacks{
  void onConnect(BLEServer* pServer){
    deviceConnected = true;
  }
  void onDisconnect(BLEServer* pServer){
    deviceConnected = false;
    pServer->startAdvertising();
  }
};

class MyCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic){
    uint8_t* pData;
    std::string value = pCharacteristic->getValue();
    int len = value.length();
    pData = pCharacteristic->getData();
    if (pData != NULL){
      // Serial.print("Notify callback for characteristic ");
      // Serial.print(pCharacteristic->getUUID().toString().c_str());
      // Serial.print(" of data length ");
      // Serial.println(len);
      Serial.print("RX  ");
      for (int i = 0; i < len; i++){
        Serial.printf("%02X ", pData[i]);
      }
      Serial.println();

      if (pData[0] == 0xAB){
        switch (pData[4]){
          case 0xA7:
          rsp = true;
          break;
        }
      }
      
    }
      
  }

  void onNotify(BLECharacteristic *pCharacteristic){
    uint8_t* pData;
    std::string value = pCharacteristic->getValue();
    int len = value.length();
    pData = pCharacteristic->getData();
    if (pData != NULL){
      // Serial.print("Notify callback for characteristic ");
      // Serial.print(pCharacteristic->getUUID().toString().c_str());
      // Serial.print(" of data length ");
      // Serial.println(len);
      Serial.print("TX  ");
      for (int i = 0; i < len; i++){
        Serial.printf("%02X ", pData[i]);
      }
      Serial.println();
      
    }
      
  }
};

void initBLE(){
  BLEDevice::init("X8 Ultra");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristicTX = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_TX,
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );
  pCharacteristicRX = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_RX,
                                         BLECharacteristic::PROPERTY_WRITE |
                                         BLECharacteristic::PROPERTY_WRITE_NR
                                       );
  pCharacteristicRX->setCallbacks(new MyCallbacks());
  pCharacteristicTX->setCallbacks(new MyCallbacks());
  pCharacteristicTX->addDescriptor(new BLE2902());
  

  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(ANCS_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(BUILTINLED, OUTPUT);

  initBLE();
}

void loop() {

  if (deviceConnected){
    digitalWrite(BUILTINLED, HIGH);

    if (rsp){
      rsp = false;
      pCharacteristicTX->setValue(resp, 9);
      pCharacteristicTX->notify();
    }
    
    if (Serial.available() > 0){
      String dat = Serial.readStringUntil('\n');
      if (dat == "BAT"){
        pCharacteristicTX->setValue(bat80, 8);
        pCharacteristicTX->notify();
        Serial.println("Sent Battery level");
      }
      if (dat == "CMD"){
        pCharacteristicTX->setValue(cmd1, 7);
        pCharacteristicTX->notify();
        delay(200);
        pCharacteristicTX->setValue(bat80, 8);
        pCharacteristicTX->notify();
        delay(200);
        pCharacteristicTX->setValue(id, 20);
        pCharacteristicTX->notify();
        delay(200);
        pCharacteristicTX->setValue(st, 20);
        pCharacteristicTX->notify();
        delay(200);
        Serial.println("Sent parameters");

      }
    }
  } else {
    digitalWrite(BUILTINLED, LOW);
  }
    
  delay(10);
}




