#pragma once

#include <NimBLEDevice.h>

#define BLE_SCAN_TIME 4
#define SCAN_PERIOD 10000
#define MAX_BLE_DEVICES 5

class BLEModule {
public:
  NimBLEScan* pBLEScan = nullptr;
  String deviceName[MAX_BLE_DEVICES];
  int deviceCount = 0;

  void begin(const char* tenThietBi = "ESP32C3-BLE") {
    NimBLEDevice::init(tenThietBi);
    pBLEScan = NimBLEDevice::getScan();
    pBLEScan->setActiveScan(true);
  }

  void scanDevices() {
    deviceCount = 0;
    pBLEScan->start(BLE_SCAN_TIME, false);  // hàm này trả về bool, không trả về kết quả scan
    NimBLEScanResults foundDevices = pBLEScan->getResults();  // phải lấy kết quả scan ở đây
    int n = foundDevices.getCount();
    for (int i = 0; i < n && deviceCount < MAX_BLE_DEVICES; i++) {
      const NimBLEAdvertisedDevice* d = foundDevices.getDevice(i);  // dùng const pointer
      String name = d->haveName() ? String(d->getName().c_str()) : "(Không tên)";
      deviceName[deviceCount++] = name;
    }
    if (deviceCount == 0)
      deviceName[0] = "Không tìm thấy BLE";
  }
};