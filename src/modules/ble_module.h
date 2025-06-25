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
    bool connected = false;

    void begin(const char* tenThietBi = "ESP32C3-BLE");
    void scanDevices();
    bool isConnected() const { return connected; }
};

// Đối tượng BLE toàn cục (có thể dùng bên ngoài)
extern BLEModule bleModule;

// Hàm cho RTOS task
#ifdef __cplusplus
extern "C" {
#endif

void ble_init(void);
void ble_update(void);
bool ble_is_connected(void); // <--- Thêm hàm này cho UI gọi

#ifdef __cplusplus
}
#endif