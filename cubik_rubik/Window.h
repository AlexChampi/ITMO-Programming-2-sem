//
// Created by alekschamp on 15.05.22.
//

#ifndef CUBIK_RUBIK_WINDOW_H
#define CUBIK_RUBIK_WINDOW_H

#include <GL/glut.h>
#include "Cube.h"

class Window {
private:
    Cube * cube = nullptr;
public:
    int width;
    int height;
public:

    int window;

    Window(int argc, char **argv, int Width, int Height, Cube & cubbe);
//    Window(const Window & window);

    void terminate();

    void renderScene();
};

//wind.render
#endif //CUBIK_RUBIK_WINDOW_H
