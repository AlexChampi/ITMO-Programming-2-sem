//
// Created by alekschamp on 15.05.22.
//

#include "Brick.h"


void Brick::draw(GLint x, GLint y, GLint z) {
    color.clear();
    Brick::x = x;
    Brick::y = y;
    Brick::z = z;
    glPushMatrix();
    glTranslatef(x, y, z);


    glBegin(GL_QUADS);
    {
        //up +++++++++++++++
        glColor3ubv(convert_color(0));
        glVertex3f(-0.9f, 1.0f, 0.9f);
        glVertex3f(-0.9f, 1.0f, -0.9);
        glVertex3f(0.9f, 1.0f, -0.9);
        glVertex3f(0.9f, 1.0f, 0.9);

        //left
        glColor3ubv(convert_color(1));
        glVertex3f(-1.0f, -0.9f, -0.9f);
        glVertex3f(-1.0f, 0.9f, -0.9);
        glVertex3f(-1.0f, 0.9f, 0.9);
        glVertex3f(-1.0f, -0.9f, 0.9);

        //front +++++++
        glColor3ubv(convert_color(2));
        glVertex3f(-0.9f, -0.9f, 1.0f);
        glVertex3f(-0.9f, 0.9f, 1.0);
        glVertex3f(0.9f, 0.9f, 1.0);
        glVertex3f(0.9f, -0.9f, 1.0);

        //right ++++++++++
        glColor3ubv(convert_color(3));
        glVertex3f(1.0f, -0.9f, -0.9f);
        glVertex3f(1.0f, 0.9f, -0.9);
        glVertex3f(1.0f, 0.9f, 0.9);
        glVertex3f(1.0f, -0.9f, 0.9);

        //back
        glColor3ubv(convert_color(4));
        glVertex3f(-0.9f, -0.9f, -1.0f);
        glVertex3f(-0.9f, 0.9f, -1.0);
        glVertex3f(0.9f, 0.9f, -1.0);
        glVertex3f(0.9f, -0.9f, -1.0);

        //down
        glColor3ubv(convert_color(5));
        glVertex3f(-0.9f, -1.0f, 0.9f);
        glVertex3f(-0.9f, -1.0f, -0.9);
        glVertex3f(0.9f, -1.0f, -0.9);
        glVertex3f(0.9f, -1.0f, 0.9);

    }
    glEnd();
    glBegin(GL_QUADS);
    {
        glColor3f(0, 0, 0);

        glVertex3f(-1, -1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -0.9, 1);
        glVertex3f(-1, -0.9, 1);

        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(0.9, 1, 1);
        glVertex3f(0.9, -1, 1);

        glVertex3f(-1, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 0.9, 1);
        glVertex3f(-1, 0.9, 1);

        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-0.9, 1, 1);
        glVertex3f(-0.9, -1, 1);

        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, 0.9);
        glVertex3f(1, -1, 0.9);

        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 0.9, -1);
        glVertex3f(1, 0.9, 1);

        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -1, -0.9);
        glVertex3f(1, 1, -0.9);

        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -0.9, -1);
        glVertex3f(1, -0.9, 1);

        glVertex3f(-1, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, 0.9);
        glVertex3f(-1, 1, 0.9);

        glVertex3f(-1, 1, 1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-0.9, 1, -1);
        glVertex3f(-0.9, 1, 1);

        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, -0.9);
        glVertex3f(-1, 1, -0.9);

        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
        glVertex3f(0.9, 1, -1);
        glVertex3f(0.9, 1, 1);

        glVertex3f(-1, -1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-0.9, 1, -1);
        glVertex3f(-0.9, -1, -1);

        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 0.9, -1);
        glVertex3f(-1, 0.9, -1);

        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(0.9, 1, -1);
        glVertex3f(0.9, -1, -1);

        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -0.9, -1);
        glVertex3f(-1, -0.9, -1);

        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-0.9, -1, -1);
        glVertex3f(-0.9, -1, 1);

        glVertex3f(-1, -1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, 0.9);
        glVertex3f(-1, -1, 0.9);

        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(0.9, -1, -1);
        glVertex3f(0.9, -1, 1);

        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -1, -0.9);
        glVertex3f(-1, -1, -0.9);

        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);
        glVertex3f(-1, 1, 0.9);
        glVertex3f(-1, -1, 0.9);

        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, -0.9, -1);
        glVertex3f(-1, -0.9, 1);

        glVertex3f(-1, -1, -1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, -0.9);
        glVertex3f(-1, -1, -0.9);

        glVertex3f(-1, 1, 1);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 0.9, -1);
        glVertex3f(-1, 0.9, 1);
//        glVertex3f()
    }

    glEnd();
//    glRotated(rotateAngel, 0, 0, 1);
    glPopMatrix();


}

GLubyte *Brick::set_dark() {
    current_colors[0] = 0;
    current_colors[1] = 0;
    current_colors[2] = 0;
    return current_colors;
}

GLubyte *Brick::paint(int position) {
    current_colors[0] = colors[position] >> 16;
    current_colors[1] = colors[position] >> 8;
    current_colors[2] = colors[position];
    color[position] = colors[position];
    return current_colors;
}

GLubyte *Brick::convert_color(int position) {
//    if (x == -2) {
//        if (y == -2) {
//            if (z == -2) {
//                if (position == 4 || position == 5 || position == 1) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 1 || position == 5) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 5 || position == 1) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//        if (y == 0) {
//            if (z == -2) {
//                if (position == 1 || position == 4) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 1) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 1) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//
//        if (y == 2) {
//            if (z == -2) {
//                if (position == 4 || position == 1 || position == 0) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 1 || position == 0) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 0 || position == 1) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//    }
//
//
//    if (x == 0) {
//        if (y == -2) {
//            if (z == -2) {
//                if (position == 4 || position == 5) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 5) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 5) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//        if (y == 0) {
//            if (z == -2) {
//                if (position == 4) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                return set_dark();
//            }
//            if (z == 2) {
//                if (position == 2) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//
//        if (y == 2) {
//            if (z == -2) {
//                if (position == 4 || position == 0) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 0) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 0) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//    }
//    if (x == 2) {
//        if (y == -2) {
//            if (z == -2) {
//                if (position == 4 || position == 5 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 5 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 5 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//        if (y == 0) {
//            if (z == -2) {
//                if (position == 4 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//
//        if (y == 2) {
//            if (z == -2) {
//                if (position == 4 || position == 0 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 0) {
//                if (position == 0 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//            if (z == 2) {
//                if (position == 2 || position == 0 || position == 3) {
//                    return paint(position);
//                } else {
//                    return set_dark();
//                }
//            }
//        }
//    }
    current_colors[0] = colors[position] >> 16;
    current_colors[1] = colors[position] >> 8;
    current_colors[2] = colors[position];

    return current_colors;
}

void Brick::XOY() {
    auto temp = colors[0];
    colors[0] = colors[1];
    colors[1] = colors[5];
    colors[5] = colors[3];
    colors[3] = temp;
//    draw(x, y, z);
}

void Brick::XOZ() {
    auto temp = colors[0];
    colors[0] = colors[2];
    colors[2] = colors[5];
    colors[5] = colors[4];
    colors[4] = temp;
//    draw(x, y, z);
}

void Brick::YOZ() {
    auto temp = colors[2];
    colors[2] = colors[1];
    colors[1] = colors[4];
    colors[4] = colors[3];
    colors[3] = temp;
//    draw(x, y, z);
}

GLint Brick::getX() {
    return x;
}

GLint Brick::getY() {
    return y;
}

GLint Brick::getZ() {
    return z;
}

std::map<int, Color> Brick::getColors() {
    return color;
}

void Brick::setColors(Color colors[6]) {
    for (int i = 0; i < 6; ++i) {
        this->colors[i] = colors[i];
    }
}




