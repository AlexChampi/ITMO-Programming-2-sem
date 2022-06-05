//
// Created by alekschamp on 15.05.22.
//

#include <GL/glut.h>
#include "Camera.h"

int Camera::initialize() {
    glutReshapeFunc(set_up);
    return 0;
}

void Camera::set_up(int width, int height) {

    if (height <= 0) height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (double) width / (double) height, 1.0, 1000.0);
    gluLookAt(16, 10, 15, 0, 1, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

}
