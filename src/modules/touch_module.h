#pragma once
#include <CST816S.h>
#include <Wire.h>

class TouchModule {
public:
    TouchModule(int sda, int scl, int rst, int int_pin);
    void begin();
    // Trả về true nếu có chạm, trả về tọa độ x, y
    bool getTouch(int &x, int &y);
    // Trả về tham chiếu đối tượng CST816S bên trong
    CST816S& getCST816S();
private:
    CST816S touch;
    int sda, scl, rst, int_pin;
};