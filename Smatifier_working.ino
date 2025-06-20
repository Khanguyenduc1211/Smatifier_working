#include "display_module.h"
#include "ui_module.h"
#include "gesture_module.h"
#include "hardware_config.h"
#include <CST816S.h>
#include "gesture_other_module.h"

GestureOtherModule gestureOther;
CST816S touch(TOUCH_SDA, TOUCH_SCL, TOUCH_RST, TOUCH_INT);

DisplayModule display;
UIModule ui;
GestureModule gesture;

int currentScreen = 1;

// Trục dọc: 8-5-1-4-7 (xoay vòng)
int verticalNext(int s) {
  switch(s) {
    case 8: return 5;
    case 5: return 1;
    case 1: return 4;
    case 4: return 7;
    case 7: return 8;
    default: return 1;
  }
}
int verticalPrev(int s) {
  switch(s) {
    case 8: return 7;
    case 7: return 4;
    case 4: return 1;
    case 1: return 5;
    case 5: return 8;
    default: return 1;
  }
}

// Trục ngang: 6-3-1-2 (xoay vòng)
int horizontalNext(int s) {
  switch(s) {
    case 6: return 3;
    case 3: return 1;
    case 1: return 2;
    case 2: return 6;
    default: return 1;
  }
}
int horizontalPrev(int s) {
  switch(s) {
    case 6: return 2;
    case 2: return 1;
    case 1: return 3;
    case 3: return 6;
    default: return 1;
  }
}

void showCurrentScreen() {
  ui.drawScreenByIndex(display, currentScreen, 0, 0);
}

void setup() {
  display.begin();
  Wire.begin(TOUCH_SDA, TOUCH_SCL);
  Wire.setClock(400000);
  pinMode(TOUCH_RST, OUTPUT);
  digitalWrite(TOUCH_RST, LOW); delay(30); digitalWrite(TOUCH_RST, HIGH); delay(150);
  touch.begin();
  touch.disable_auto_sleep();
  showCurrentScreen();
}

void loop() {
  // Xử lý swipe và single tap bằng gesture_module
  uint8_t swipeG = gesture.getGesture(touch);

  // Vuốt trái (Swipe Left, g==3): next trên trục ngang
  if (swipeG == 3) {
    int next = horizontalNext(currentScreen);
    if (next != currentScreen) {
      ui.slideAnimation(display, currentScreen, next, "left", 1);
      currentScreen = next;
      delay(40);
    }
  }
  // Vuốt phải (Swipe Right, g==4): prev trên trục ngang
  else if (swipeG == 4) {
    int next = horizontalPrev(currentScreen);
    if (next != currentScreen) {
      ui.slideAnimation(display, currentScreen, next, "right", 1);
      currentScreen = next;
      delay(40);
    }
  }
  // Vuốt lên (Swipe Up, g==2): prev trên trục dọc
  else if (swipeG == 2) {
    int next = verticalPrev(currentScreen);
    if (next != currentScreen) {
      ui.slideAnimation(display, currentScreen, next, "up", 1);
      currentScreen = next;
      delay(40);
    }
  }
  // Vuốt xuống (Swipe Down, g==1): next trên trục dọc
  else if (swipeG == 1) {
    int next = verticalNext(currentScreen);
    if (next != currentScreen) {
      ui.slideAnimation(display, currentScreen, next, "down", 1);
      currentScreen = next;
      delay(40);
    }
  }

  // Xử lý long press về home bằng gestureOther (cho phép thao tác nhiều lần, trừ khi đang ở màn hình 1)
  uint8_t g = gestureOther.getGesture(touch);
  if (g == 7 && currentScreen != 1) { // Long press về màn hình home (screen 1)
    ui.slideAnimation(display, currentScreen, 1, "right", 1);
    currentScreen = 1;
    delay(40);
  }
}