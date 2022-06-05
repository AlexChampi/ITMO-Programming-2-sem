#include <iostream>
#include <thread>
#include <functional>

#include "Window.h"
#include "Camera.h"
#include "Events.h"
#include "Cube.h"
#include "Brick.h"
#include "FileManager.h"
#include "WrapperClass.h"

int WIDTH = 1280;
int HEIGHT = 720;


int main(int argc, char **argv) {
    Cube cube{};
    Window window{argc, argv, WIDTH, HEIGHT, cube};
    Events events{window, cube};

    WrapperClass::Setup(window, events);

    Camera::initialize();


    glutDisplayFunc(WrapperClass::WindowCallback);
    glutIdleFunc(WrapperClass::WindowCallback);
    glutKeyboardFunc(WrapperClass::EventsCallback);
    glutIgnoreKeyRepeat(0);

    glutMainLoop();

    return 0;
}
