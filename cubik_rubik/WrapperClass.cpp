//
// Created by alekschamp on 19.05.22.
//

#include "WrapperClass.h"

Window * WrapperClass::window;
Events * WrapperClass::events;

void WrapperClass::WindowCallback() {
    window->renderScene();
}

void WrapperClass::EventsCallback(GLubyte keycode, int x, int y) {
    events->key_callback_press(keycode, x, y);
}

void WrapperClass::Setup(Window &window_, Events &events_) {
    window = &window_;
    events = &events_;
}

