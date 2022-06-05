//
// Created by alekschamp on 15.05.22.
//

#include <iostream>
#include <random>
#include <functional>
#include <cstring>
#include "Cube.h"


const std::map<Color, std::string> Cube::colorName = Cube::getColorNames();

std::map<Color, std::string> Cube::getColorNames() {
    std::map<Color, std::string> m;
    m[RED] = "RED";
    m[YELLOW] = "YELLOW";
    m[BLUE] = "BLUE";
    m[GREEN] = "GREEN";
    m[ORANGE] = "ORANGE";
    m[WHITE] = "WHITE";
    return m;
}

const std::map<char , Color> Cube::nameColor = Cube::getNameColor();

std::map<char , Color> Cube::getNameColor() {
    std::map<char , Color> m;
    m['R'] = RED;
    m['Y'] = YELLOW;
    m['B'] = BLUE;
    m['G'] = GREEN;
    m['O'] = ORANGE;
    m['W'] = WHITE;
    return m;
}

//const std::map<Color, std::vector<int>> Cube::indexes = Cube::setIndexes();
//
//std::map<Color, std::vector<int>> Cube::setIndexes() {
//    std::map<Color, std::vector<int>> m;
//    m[RED] = "RED";
//    m[YELLOW] = "YELLOW";
//    m[BLUE] = "BLUE";
//    m[GREEN] = "GREEN";
//    m[ORANGE] = "ORANGE";
//    m[WHITE] = "WHITE";
//    return m;
//}

void Cube::draw() {

    glPushMatrix();
    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            for (int k = -size / 2; k < (size + 1) / 2; ++k) {
                if (!bricks[i + size / 2][j + size / 2][k + size / 2].isRot &&
                    (i == -size / 2 || i == (size + 1) / 2 - 1 ||
                     j == -size / 2 || j == (size + 1) / 2 - 1 ||
                     k == -size / 2 || k == (size + 1) / 2 - 1)) {
                    bricks[i + size / 2][j + size / 2][k + size / 2].draw(i * 2, j * 2, k * 2);
                }
            }
        }
    }
    if (rotateAngle[0] != 0) {
        rotateSide(-1, 2, -1, 0);
    }

    if (rotateAngle[1] != 0) {
        rotateSide(0, -1, -1, 1);
    }

    if (rotateAngle[2] != 0) {
        rotateSide(-1, -1, 2, 2);
    }

    if (rotateAngle[3] != 0) {
        rotateSide(2, -1, -1, 3);
    }

    if (rotateAngle[4] != 0) {
        rotateSide(-1, -1, 0, 4);
    }

    if (rotateAngle[5] != 0) {
        rotateSide(-1, 0, -1, 5);
    }
    glPopMatrix();
}

void Cube::F() {
    _f(2, (size + 1) / 2);
    FileManager::out << "F ";
}

void Cube::B() {
    _b(4, 0);
    FileManager::out << "B ";
}

void Cube::L() {
    _l(1, 0);
    FileManager::out << "L ";
}

void Cube::R() {
    _r(3, (size + 1) / 2);
    FileManager::out << "R ";
}

void Cube::U() {
    _u(0, (size + 1) / 2);
    FileManager::out << "U ";
}

void Cube::D() {
    _d(5, 0);
    FileManager::out << "D ";
}

void Cube::f() {
    _b(2, (size + 1) / 2);
    FileManager::out << "F' ";
}

void Cube::b() {
    _f(4, 0);
    FileManager::out << "B' ";
}

void Cube::l() {
    _r(1, 0);
    FileManager::out << "L' ";
}

void Cube::r() {
    _l(3, (size + 1) / 2);
    FileManager::out << "R' ";
}

void Cube::u() {
    _d(0, (size + 1) / 2);
    FileManager::out << "U' ";
}

void Cube::d() {
    _u(5, 0);
    FileManager::out << "D' ";
}

void Cube::resetRotation(int pos) {
    Cube::rotateAngle[pos] = 0;
}

void Cube::resetBlockRotation(int x, int y, int z) {
    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            if (x > -1) {
                bricks[x][i + 1][j + 1].isRot = false;
            }
            if (y > -1) {
                bricks[i + 1][y][j + 1].isRot = false;
            }
            if (z > -1) {
                bricks[i + 1][j + 1][z].isRot = false;
            }
        }
    }

}

void Cube::endRotation(int x, int y, int z, int side) {
    resetBlockRotation(x, y, z);
    resetRotation(side);
}

void Cube::rotateVis(float angle, int side, int x, int y, int z) {
    Cube::rotateAngle[side] = angle;
    setBlockRotation(x, y, z);
}

void Cube::setBlockRotation(int x, int y, int z) {
    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            if (x > -1) {
                bricks[x][i + size / 2][j + size / 2].isRot = true;
            }
            if (y > -1) {
                bricks[i + size / 2][y][j + size / 2].isRot = true;
            }
            if (z > -1) {
                bricks[i + size / 2][j + size / 2][z].isRot = true;
            }
        }
    }

}


void Cube::realRotation(int x, int y, int z, int pos, int step) {

    for (int s = 0; s < step; ++s) {

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                tmp[j][size - 1 - i] = (x > -1) ? bricks[x][i][j] : ((y > -1) ? bricks[i][y][j]
                                                                              : bricks[i][j][z]);
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                (x > -1) ? tmp[i][j].XOZ() : (y > -1) ? tmp[i][j].YOZ() : tmp[i][j].XOY();
                ((x > -1) ? bricks[x][i][j] : ((y > -1) ? bricks[i][y][j] : bricks[i][j][z])) = tmp[i][j];
            }
        }

    }
}

void Cube::rotateSide(int x, int y, int z, int pos) {
    glPushMatrix();
    int _x = (x == -1) ? 0 : 1;
    int _y = (y == -1) ? 0 : 1;
    int _z = (z == -1) ? 0 : 1;
    glRotated(rotateAngle[pos], _x, _y, _z);

    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            if (x > -1) {
                bricks[x][i + size / 2][j + size / 2].draw((x == 0) ? -size / 2 * 2 : size / 2 * 2, i * 2, j * 2);
            }
            if (y > -1) {
                bricks[i + size / 2][y][j + size / 2].draw(i * 2, (y == 0) ? -size / 2 * 2 : size / 2 * 2, j * 2);
            }
            if (z > -1) {
                bricks[i + size / 2][j + size / 2][z].draw(i * 2, j * 2, (z == 0) ? -size / 2 * 2 : size / 2 * 2);
            }
        }
    }
    glPopMatrix();


}

void Cube::_f(int pos, int param) {
    realRotation(-1, -1, param, pos, 1);
}

void Cube::_b(int pos, int param) {
    realRotation(-1, -1, param, pos, 3);
}

void Cube::_l(int pos, int param) {
    realRotation(param, -1, -1, pos, 3);
}

void Cube::_r(int pos, int param) {
    realRotation(param, -1, -1, pos, 1);
}

void Cube::_u(int pos, int param) {
    realRotation(-1, param, -1, pos, 3);
}

void Cube::_d(int pos, int param) {
    realRotation(-1, param, -1, pos, 1);
}

void Cube::log() {
    FileManager::out << ++Cube::logCounter << std::endl;
    int cnt = 1;
    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            for (int k = -size / 2; k < (size + 1) / 2; ++k) {
                if (!bricks[i + size / 2][j + size / 2][k + size / 2].isRot &&
                    (i == -size / 2 || i == (size + 1) / 2 - 1 ||
                     j == -size / 2 || j == (size + 1) / 2 - 1 ||
                     k == -size / 2 || k == (size + 1) / 2 - 1)) {

                    FileManager::out << cnt++ << std::endl <<
                                     bricks[i + size / 2][j + size / 2][k + size / 2].getX() << " "
                                     << bricks[i + size / 2][j + size / 2][k + size / 2].getY() << " "
                                     << bricks[i + size / 2][j + size / 2][k + size / 2].getZ() << std::endl;
                    auto temp = bricks[i + size / 2][j + size / 2][k + size / 2].getColors();
                    for (auto it: temp) {
                        FileManager::out << " Side " << it.first << " color " << colorName.at(it.second) << std::endl;
                    }
                }
            }
        }
    }
    FileManager::out << std::endl;
}



std::string Cube::getColors() {
    std::vector<std::string> stringVector(6);
    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            for (int k = -size / 2; k < (size + 1) / 2; ++k) {
                if (i == -size / 2 || i == (size + 1) / 2 - 1 ||
                    j == -size / 2 || j == (size + 1) / 2 - 1 ||
                    k == -size / 2 || k == (size + 1) / 2 - 1) {
                    auto map = bricks[i + size / 2][j + size / 2][k + size / 2].getColors();
                    for (auto it: map) {
                        stringVector[it.first] += Cube::colorName.at(it.second)[0];
                    }
                }
            }
        }
    }
    std::string res;
    for (auto i: stringVector) {
        res += i;
    }
    return res;
}

Cube::Cube() {
    memset(rotateAngle, 0, sizeof(rotateAngle));
}

void Cube::readFile() {
    std::string colors;
    while (FileManager::in) {
        char a;
        FileManager::in >> a;
        if (a != ' ' && a != '\n')
            colors += a;
    }
    colors.pop_back();


    for (int i = -size / 2; i < (size + 1) / 2; ++i) {
        for (int j = -size / 2; j < (size + 1) / 2; ++j) {
            for (int k = -size / 2; k < (size + 1) / 2; ++k) {
                if (i == -size / 2 || i == (size + 1) / 2 - 1 ||
                    j == -size / 2 || j == (size + 1) / 2 - 1 ||
                    k == -size / 2 || k == (size + 1) / 2 - 1) {
                    Color * res = setColor(i, j, k, colors);
                    bricks[i + size / 2][j + size / 2][k + size / 2].setColors(res);
                }
            }
        }
    }

    std::cout << colors;
//    exit(1);
}

Color *Cube::setColor(int i, int j, int k, std::string & c) {
    Color * color = new Color[6];
    if (i == -1) {
        if (j == -1) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[6]);
                color[1] = Cube::nameColor.at(c[35]);
                color[2] = Cube::nameColor.at(c[36]);
                color[3] = Cube::nameColor.at(c[39]);
                color[4] = Cube::nameColor.at(c[44]);
                color[5] = Cube::nameColor.at(c[45]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[3]);
                color[1] = Cube::nameColor.at(c[34]);
                color[2] = Cube::nameColor.at(c[36]);
                color[3] = Cube::nameColor.at(c[40]);
                color[4] = Cube::nameColor.at(c[44]);
                color[5] = Cube::nameColor.at(c[48]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[0]);
                color[1] = Cube::nameColor.at(c[33]);
                color[2] = Cube::nameColor.at(c[36]);
                color[3] = Cube::nameColor.at(c[41]);
                color[4] = Cube::nameColor.at(c[44]);
                color[5] = Cube::nameColor.at(c[51]);
            }
        }
        if (j == 0) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[6]);
                color[1] = Cube::nameColor.at(c[23]);
                color[2] = Cube::nameColor.at(c[24]);
                color[3] = Cube::nameColor.at(c[27]);
                color[4] = Cube::nameColor.at(c[32]);
                color[5] = Cube::nameColor.at(c[45]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[3]);
                color[1] = Cube::nameColor.at(c[22]);
                color[2] = Cube::nameColor.at(c[24]);
                color[3] = Cube::nameColor.at(c[28]);
                color[4] = Cube::nameColor.at(c[32]);
                color[5] = Cube::nameColor.at(c[48]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[0]);
                color[1] = Cube::nameColor.at(c[21]);
                color[2] = Cube::nameColor.at(c[24]);
                color[3] = Cube::nameColor.at(c[29]);
                color[4] = Cube::nameColor.at(c[32]);
                color[5] = Cube::nameColor.at(c[51]);
            }
        }
        if (j == 1) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[6]);
                color[1] = Cube::nameColor.at(c[11]);
                color[2] = Cube::nameColor.at(c[12]);
                color[3] = Cube::nameColor.at(c[15]);
                color[4] = Cube::nameColor.at(c[20]);
                color[5] = Cube::nameColor.at(c[45]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[3]);
                color[1] = Cube::nameColor.at(c[10]);
                color[2] = Cube::nameColor.at(c[12]);
                color[3] = Cube::nameColor.at(c[16]);
                color[4] = Cube::nameColor.at(c[20]);
                color[5] = Cube::nameColor.at(c[48]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[0]);
                color[1] = Cube::nameColor.at(c[9]);
                color[2] = Cube::nameColor.at(c[12]);
                color[3] = Cube::nameColor.at(c[17]);
                color[4] = Cube::nameColor.at(c[20]);
                color[5] = Cube::nameColor.at(c[51]);
            }
        }
    }

    if (i == 0) {
        if (j == -1) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[7]);
                color[1] = Cube::nameColor.at(c[35]);
                color[2] = Cube::nameColor.at(c[37]);
                color[3] = Cube::nameColor.at(c[39]);
                color[4] = Cube::nameColor.at(c[43]);
                color[5] = Cube::nameColor.at(c[46]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[4]);
                color[1] = Cube::nameColor.at(c[34]);
                color[2] = Cube::nameColor.at(c[37]);
                color[3] = Cube::nameColor.at(c[40]);
                color[4] = Cube::nameColor.at(c[43]);
                color[5] = Cube::nameColor.at(c[49]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[1]);
                color[1] = Cube::nameColor.at(c[33]);
                color[2] = Cube::nameColor.at(c[37]);
                color[3] = Cube::nameColor.at(c[41]);
                color[4] = Cube::nameColor.at(c[43]);
                color[5] = Cube::nameColor.at(c[52]);
            }
        }
        if (j == 0) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[7]);
                color[1] = Cube::nameColor.at(c[23]);
                color[2] = Cube::nameColor.at(c[25]);
                color[3] = Cube::nameColor.at(c[27]);
                color[4] = Cube::nameColor.at(c[31]);
                color[5] = Cube::nameColor.at(c[46]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[4]);
                color[1] = Cube::nameColor.at(c[22]);
                color[2] = Cube::nameColor.at(c[25]);
                color[3] = Cube::nameColor.at(c[28]);
                color[4] = Cube::nameColor.at(c[31]);
                color[5] = Cube::nameColor.at(c[49]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[1]);
                color[1] = Cube::nameColor.at(c[21]);
                color[2] = Cube::nameColor.at(c[25]);
                color[3] = Cube::nameColor.at(c[29]);
                color[4] = Cube::nameColor.at(c[31]);
                color[5] = Cube::nameColor.at(c[52]);
            }
        }
        if (j == 1) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[7]);
                color[1] = Cube::nameColor.at(c[11]);
                color[2] = Cube::nameColor.at(c[13]);
                color[3] = Cube::nameColor.at(c[15]);
                color[4] = Cube::nameColor.at(c[19]);
                color[5] = Cube::nameColor.at(c[47]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[4]);
                color[1] = Cube::nameColor.at(c[10]);
                color[2] = Cube::nameColor.at(c[13]);
                color[3] = Cube::nameColor.at(c[16]);
                color[4] = Cube::nameColor.at(c[19]);
                color[5] = Cube::nameColor.at(c[50]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[1]);
                color[1] = Cube::nameColor.at(c[9]);
                color[2] = Cube::nameColor.at(c[13]);
                color[3] = Cube::nameColor.at(c[17]);
                color[4] = Cube::nameColor.at(c[19]);
                color[5] = Cube::nameColor.at(c[53]);
            }
        }
    }
    if (i == 1) {
        if (j == -1) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[8]);
                color[1] = Cube::nameColor.at(c[35]);
                color[2] = Cube::nameColor.at(c[38]);
                color[3] = Cube::nameColor.at(c[39]);
                color[4] = Cube::nameColor.at(c[42]);
                color[5] = Cube::nameColor.at(c[47]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[5]);
                color[1] = Cube::nameColor.at(c[34]);
                color[2] = Cube::nameColor.at(c[38]);
                color[3] = Cube::nameColor.at(c[40]);
                color[4] = Cube::nameColor.at(c[42]);
                color[5] = Cube::nameColor.at(c[50]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[2]);
                color[1] = Cube::nameColor.at(c[33]);
                color[2] = Cube::nameColor.at(c[38]);
                color[3] = Cube::nameColor.at(c[41]);
                color[4] = Cube::nameColor.at(c[42]);
                color[5] = Cube::nameColor.at(c[53]);
            }
        }
        if (j == 0) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[8]);
                color[1] = Cube::nameColor.at(c[23]);
                color[2] = Cube::nameColor.at(c[26]);
                color[3] = Cube::nameColor.at(c[27]);
                color[4] = Cube::nameColor.at(c[30]);
                color[5] = Cube::nameColor.at(c[47]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[5]);
                color[1] = Cube::nameColor.at(c[22]);
                color[2] = Cube::nameColor.at(c[26]);
                color[3] = Cube::nameColor.at(c[28]);
                color[4] = Cube::nameColor.at(c[30]);
                color[5] = Cube::nameColor.at(c[50]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[2]);
                color[1] = Cube::nameColor.at(c[21]);
                color[2] = Cube::nameColor.at(c[26]);
                color[3] = Cube::nameColor.at(c[29]);
                color[4] = Cube::nameColor.at(c[30]);
                color[5] = Cube::nameColor.at(c[53]);
            }
        }
        if (j == 1) {
            if (k == 1) {
                color[0] = Cube::nameColor.at(c[8]);
                color[1] = Cube::nameColor.at(c[11]);
                color[2] = Cube::nameColor.at(c[14]);
                color[3] = Cube::nameColor.at(c[15]);
                color[4] = Cube::nameColor.at(c[18]);
                color[5] = Cube::nameColor.at(c[47]);
            }
            if (k == 0) {
                color[0] = Cube::nameColor.at(c[5]);
                color[1] = Cube::nameColor.at(c[10]);
                color[2] = Cube::nameColor.at(c[14]);
                color[3] = Cube::nameColor.at(c[16]);
                color[4] = Cube::nameColor.at(c[18]);
                color[5] = Cube::nameColor.at(c[50]);
            }
            if (k == -1) {
                color[0] = Cube::nameColor.at(c[2]);
                color[1] = Cube::nameColor.at(c[9]);
                color[2] = Cube::nameColor.at(c[14]);
                color[3] = Cube::nameColor.at(c[17]);
                color[4] = Cube::nameColor.at(c[18]);
                color[5] = Cube::nameColor.at(c[53]);
            }
        }
    }
    return color;
}


