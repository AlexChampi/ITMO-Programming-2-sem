//
// Created by alekschamp on 19.05.22.
//

#ifndef CUBIK_RUBIK_WRAPPERCLASS_H
#define CUBIK_RUBIK_WRAPPERCLASS_H

#include "Window.h"
#include "Events.h"

class WrapperClass {
private:
    static Events * events;
    static Window * window;
public:
    static void WindowCallback();
    static void EventsCallback(GLubyte keycode, int x, int y);
    static void Setup(Window & window, Events & events);
};


#endif //CUBIK_RUBIK_WRAPPERCLASS_H
