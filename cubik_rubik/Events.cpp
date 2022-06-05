//
// Created by alekschamp on 15.05.22.
//

#include <iostream>
#include "Events.h"

int speed = 3;

void Events::key_callback_press(GLubyte keycode, int x, int y) {

    switch (keycode) {
        case 'I' :
            cube->readFile();
            break;

        case 'T':
            this->Y();
            this->Y();
            for (int i = 0; i < 500; ++i) {
                shuffle();
                solve();
                if (!isReady()) {
                    std::cout << i << '\n';
                    std::cout << cube->getColors();
                    break;
                }
            }
            std::cout << "GOOD";
//            exit(0);
            break;

        case 27:
            window->terminate();
            break;
        case 'X':
            Events::X();
            break;
        case 'x':
            Events::x();
            break;
        case 'Y':
            Events::Y();
            break;
        case 'y':
            Events::y();
            break;
        case 'F':
            Events::F();
            break;
        case 'B':
            Events::B();
            break;
        case 'R':
            Events::R();
            break;
        case 'L':
            Events::L();
            break;
        case 'U':
            Events::U();
            break;
        case 'D':
            Events::D();
            break;
        case 'f':
            Events::f();
            break;
        case 'b':
            Events::b();
            break;
        case 'r':
            Events::r();
            break;
        case 'l':
            Events::l();
            break;
        case 'u':
            Events::u();
            break;
        case 'd':
            Events::d();
            break;
        case 'w':
            cube->log();
            break;
        case 's':
            Events::shuffle();
            break;
        case 'p':
            Events::solve();
            break;
    }
}

void Events::rotate(int x, int y, int z, float angle, int side) {
    int sign = (angle > 0) ? 1 : -1;
    float temp = cube->rotateAngle[side] - sign * 90;
    EventHelper eventHelper(temp, temp);
    while (eventHelper.isValid()) {
        eventHelper.angle += sign * speed;
        cube->rotateVis(eventHelper.angle, side, x, y, z);
        window->renderScene();
    }
    cube->endRotation(x, y, z, side);
}

void Events::F() {
    cube->F();
    Events::rotate(-1, -1, 2, -90, 2);
}

void Events::R() {
    cube->R();
    Events::rotate(2, -1, -1, -90, 3);
}

void Events::B() {
    cube->B();
    Events::rotate(-1, -1, 0, 90, 4);
}

void Events::L() {
    cube->L();
    Events::rotate(0, -1, -1, 90, 1);
}

void Events::U() {
    cube->U();
    Events::rotate(-1, 2, -1, -90, 0);
}

void Events::D() {
    cube->D();
    Events::rotate(-1, 0, -1, 90, 5);
}

void Events::f() {
    cube->f();
    Events::rotate(-1, -1, 2, 90, 2);
}

void Events::r() {
    cube->r();
    Events::rotate(2, -1, -1, 90, 3);
}

void Events::b() {
    cube->b();
    Events::rotate(-1, -1, 0, -90, 4);
}

void Events::l() {
    cube->l();
    Events::rotate(0, -1, -1, -90, 1);

}

void Events::u() {
    cube->u();
    Events::rotate(-1, 2, -1, 90, 0);

}

void Events::d() {
    cube->d();
    Events::rotate(-1, 0, -1, -90, 5);
}

void Events::X() {
    float temp = cube->angleX;
    for (float i = temp; i <= temp + 90; i += speed) {
        cube->angleX = i;
        window->renderScene();
    }
}

void Events::Y() {
    float temp = cube->angleY;
    for (float i = temp; i >= temp - 90; i -= speed) {
        cube->angleY = i;
        window->renderScene();
    }
}

void Events::x() {
    float temp = cube->angleX;
    for (float i = temp; i >= temp - 90; i -= speed) {
        cube->angleX = i;
        window->renderScene();
    }
}

void Events::y() {
    float temp = cube->angleY;
    for (float i = temp; i <= temp + 90; i += speed) {
        cube->angleY = i;
        window->renderScene();
    }
}

Events::Events(Window &window, Cube &cube) : window(&window), cube(&cube) {}


