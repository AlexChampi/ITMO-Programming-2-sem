//
// Created by alekschamp on 15.05.22.
//

#include "Window.h"



void Window::terminate() {
    glutDestroyWindow(window);
    exit(0);
}

void Window::renderScene() {
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotated(cube->angleX, 0, 1, 0);
    glRotated(cube->angleY, 1, 0, 0);
    cube->draw();
    glPopMatrix();
    glutSwapBuffers();
}

Window::Window(int argc, char **argv, int Width, int Height, Cube & cube): cube(&cube) {
    width = Width;
    height = Height;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(Width, Height);
    Window::window = glutCreateWindow("CUBIC👬");
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

}

//Window::Window(const Window &window) = default;
