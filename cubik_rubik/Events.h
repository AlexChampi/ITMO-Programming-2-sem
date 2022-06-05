//
// Created by alekschamp on 15.05.22.
//

#ifndef CUBIK_RUBIK_EVENTS_H
#define CUBIK_RUBIK_EVENTS_H

#include <GL/glut.h>
#include <cstring>

#include "Window.h"
#include "Cube.h"
#include "EventHelper.h"

class Events {
private:
    Window * window = nullptr;
    Cube * cube = nullptr;
    void rotate(int x, int y, int z, float angle, int side);

    void F();
    void R();
    void B();
    void L();
    void U();
    void D();
    void f();
    void r();
    void b();
    void l();
    void u();
    void d();

    void X();
    void Y();
    void x();
    void y();

    void solve();
    void cross();
    void cornerCross();
    void secondLayer();

    bool isCrossready();
public:
    Events(Window &window, Cube &cube);

//    Events(const Events &events);

    void key_callback_press(GLubyte keycode, int x, int y);

    void shuffle();

    bool iscornerCross();

    bool isSecondLayer();

    void upperCross();

    bool isUpperCross();

    void setUpeerCross();

    void setUpperCorners();

    void temp();

    bool checkSum();

    bool isReady();

    void setAllCorners();
};


#endif //CUBIK_RUBIK_EVENTS_H
