#pragma once

#include <CST816S.h>

// Module này nhận diện đầy đủ gesture: swipe, single tap, double tap, long press.
// Bạn phải tạo đối tượng CST816S touch(...) ở file main.cpp và gọi touch.begin() trước khi sử dụng module này.

class GestureModule {
public:
    // Hàm này nên được gọi mỗi vòng lặp, chỉ trả về gestureID khác 0 nếu vừa có cử chỉ mới
    // Giá trị trả về là gestureID thực tế, trùng với CST816S:
    // 0x01: SWIPE DOWN, 0x02: SWIPE UP, 0x03: SWIPE LEFT, 0x04: SWIPE RIGHT
    // 0x05: SINGLE TAP, 0x0B: DOUBLE TAP, 0x0C: LONG PRESS
    // 0: Không có gesture mới
    uint8_t getGesture(CST816S &touch);

    // Trả về chuỗi mô tả tên gesture
    const char* gestureString(uint8_t gesture);
};