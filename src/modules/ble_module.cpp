#include "ble_module.h"

// Đối tượng BLE toàn cục
BLEModule bleModule;

// Callbacks cho BLE Server
class ServerCallbacks : public NimBLEServerCallbacks {
public:
    // KHÔNG dùng override nếu báo lỗi
    void onConnect(NimBLEServer* pServer) {
        bleModule.connected = true;
    }
    void onDisconnect(NimBLEServer* pServer) {
        bleModule.connected = false;
    }
};

void BLEModule::begin(const char* tenThietBi) {
    NimBLEDevice::init(tenThietBi);
    NimBLEServer* pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    pBLEScan = NimBLEDevice::getScan();
    pBLEScan->setActiveScan(true);
}

void BLEModule::scanDevices() {
    deviceCount = 0;
    pBLEScan->start(BLE_SCAN_TIME, false);
    NimBLEScanResults foundDevices = pBLEScan->getResults();
    int n = foundDevices.getCount();
    for (int i = 0; i < n && deviceCount < MAX_BLE_DEVICES; i++) {
        const NimBLEAdvertisedDevice* d = foundDevices.getDevice(i);
        String name = d->haveName() ? String(d->getName().c_str()) : "(Không tên)";
        deviceName[deviceCount++] = name;
    }
    if (deviceCount == 0)
        deviceName[0] = "Không tìm thấy BLE";
}

void ble_init() {
    bleModule.begin("ESP32C3-BLE");
}

void ble_update() {
    bleModule.scanDevices();
    vTaskDelay(pdMS_TO_TICKS(SCAN_PERIOD));
}

bool ble_is_connected() {
    return bleModule.isConnected();
}