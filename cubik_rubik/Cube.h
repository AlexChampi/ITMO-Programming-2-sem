//
// Created by alekschamp on 15.05.22.
//

#ifndef CUBIK_RUBIK_CUBE_H
#define CUBIK_RUBIK_CUBE_H

#include "Brick.h"
#include "FileManager.h"

class Cube {
private:
    static const int size = 3;
    static const int speed = 3;
    Brick bricks[size][size][size];
public:
    Cube();

private:
    Brick tmp[size][size];

    void setBlockRotation(int x, int y, int z);

    void realRotation(int x, int y, int z, int pos, int step);

    void rotateSide(int x, int y, int z, int pos);

    void resetRotation(int pos);

    void resetBlockRotation(int x, int y, int z);

    void _f(int pos, int param);

    void _b(int pos, int param);

    void _l(int pos, int param);

    void _r(int pos, int param);

    void _u(int pos, int param);

    void _d(int pos, int param);

    int logCounter = 0;

    static std::map<Color, std::string> getColorNames();
    static const std::map<Color, std::string> colorName;
//    static const std::map<Color, std::vector<int>> indexes;
//    static std::map<Color, std::vector<int>> setIndexes();

public:
    GLfloat angleX = 0;
    GLfloat angleY = 0;
    GLfloat rotateAngle[6];

    void draw();

    std::string getColors();

    void F();

    void B();

    void L();

    void R();

    void U();

    void D();

    void f();

    void b();

    void l();

    void r();

    void u();

    void d();

    void rotateVis(float angle, int side, int x, int y, int z);
    void endRotation(int x, int y, int z, int side);

    void readFile();
    void log();

    static std::map<char , Color> getNameColor();

    static const std::map<char , Color> nameColor;

    Color *setColor(int i, int j, int k, std::string & colors);
};


#endif //CUBIK_RUBIK_CUBE_H
