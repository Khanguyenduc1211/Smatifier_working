#pragma once
#include "display_module.h"
#include "ui_module.h"
#include "gesture_module.h"
#include "swipe_module.h"
#include "touch_module.h"

extern DisplayModule display;
extern UIModule ui;
extern GestureModule gesture;
extern TouchModule touch;
extern int currentScreen;
extern SwipeModule swipe;