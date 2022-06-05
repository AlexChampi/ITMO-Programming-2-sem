//
// Created by alekschamp on 15.05.22.
//

#ifndef CUBIK_RUBIK_BRICK_H
#define CUBIK_RUBIK_BRICK_H

#include <GL/glut.h>
#include <map>

enum Color {
    RED = 16711680, GREEN = 65280, BLUE = 255, YELLOW = 16776960, ORANGE = 16731904, WHITE = 16777215
};


class Brick {
private:
    GLubyte *set_dark();
    GLubyte *paint(int position);

    GLubyte *convert_color(int position);
    GLubyte current_colors[3];
    Color colors[6] = {YELLOW, BLUE, RED, GREEN, ORANGE, WHITE};
    GLint x, y, z;

    std::map<int, Color> color;
public:
    bool isRot = false;

    void draw(GLint x, GLint y, GLint z);

    void XOY();
    void XOZ();
    void YOZ();

    int getX();
    int getY();
    int getZ();
    std::map<int, Color> getColors();
    void setColors(Color colors[6]);


};


#endif //CUBIK_RUBIK_BRICK_H
