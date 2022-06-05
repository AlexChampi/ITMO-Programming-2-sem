//
// Created by alekschamp on 18.05.22.
//

#include <random>
#include <array>
#include <functional>
#include <iostream>
#include "Events.h"


bool Events::isCrossready() {
    std::string status = cube->getColors();
    bool res = (status[50] == status[52]) && (status[52] == status[48]) && (status[48] == status[46]) &&
               (status[21] == status[22]) && (status[10] == status[13]) && (status[28] == status[31]) &&
               (status[39] == status[40]) && (status[50] == 'W') && (status[22] == 'R') && (status[31] == 'G') &&
               (status[40] == 'O') && (status[13] == 'B');
    return res;
}

bool Events::iscornerCross() {
    std::string status = cube->getColors();
    bool res = (status[50] == status[52]) && (status[52] == status[48]) && (status[48] == status[46]) &&
               (status[21] == status[22]) && (status[10] == status[13]) && (status[28] == status[31]) &&
               (status[39] == status[40]) && (status[50] == 'W') && (status[22] == 'R') && (status[31] == 'G') &&
               (status[40] == 'O') && (status[13] == 'B') && (status[53] == 'W') && (status[24] == 'R') &&
               (status[29] == 'G') && (status[51] == 'W') && (status[27] == 'G') && (status[42] == 'O') &&
               (status[45] == 'W') && (status[36] == 'O') && (status[9] == 'B') && (status[47] == 'W') &&
               (status[11] == 'B')
               && (status[18] == 'R');
    return res;
}

bool Events::isSecondLayer() {
    std::string status = cube->getColors();
    bool res = iscornerCross();
    return res && (status[12] == status[13]) && (status[13] == status[14]) && (status[13] == 'B')
           && (status[19] == status[22]) && (status[22] == status[25]) && (status[22] == 'R')
           && (status[32] == status[31]) && (status[31] == status[30]) && (status[31] == 'G')
           && (status[43] == status[40]) && (status[40] == status[37]) && (status[37] == 'O');
}

bool Events::isUpperCross() {
    std::string status = cube->getColors();
    bool res = iscornerCross();
    return res && (status[1] == 'Y') && (status[3] == 'Y') && (status[4] == 'Y') && (status[5] == 'Y') &&
           (status[7] == 'Y');
}

bool Events::isReady() {
    std::string status = cube->getColors();
    std::string result = "YYYYYYYYYBBBBBBBBBRRRRRRRRRGGGGGGGGGOOOOOOOOOWWWWWWWWW";
    return result == status;
}

void Events::solve() {
    FileManager::initialize("log.txt");
    cube->log();
    Events::cross();
    Events::cornerCross();
    Events::secondLayer();
    Events::upperCross();
    Events::setUpeerCross();
    Events::setUpperCorners();
    Events::setAllCorners();
    FileManager::out.close();
}

void Events::cross() {
    this->y();
    this->y();
    std::string cur_colors = cube->getColors();
    bool itRotated = false;
    int cnt = 0;
    while (cnt < 4) {
        itRotated = false;
        cur_colors = cube->getColors();
        for (int i = 1; i < 9; i += 2) {
            if (cur_colors[i] == 'W') {
                if (i == 1 && cur_colors[16] == 'B') {
                    this->L();
                    this->L();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
                if (i == 5 && cur_colors[23] == 'R') {
                    this->F();
                    this->F();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
                if (i == 7 && cur_colors[34] == 'G') {
                    this->R();
                    this->R();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
                if (i == 3 && cur_colors[41] == 'O') {
                    this->B();
                    this->B();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }

            }
        }
        if (cur_colors[16] == 'W' && cur_colors[1] == 'B') {
            this->u();
            this->f();
            this->L();
            this->F();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[23] == 'W' && cur_colors[5] == 'R') {
            this->u();
            this->r();
            this->F();
            this->R();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[34] == 'W' && cur_colors[7] == 'G') {
            this->u();
            this->b();
            this->R();
            this->B();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[41] == 'W' && cur_colors[3] == 'O') {
            this->u();
            this->l();
            this->B();
            this->L();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[14] == 'W') {
            this->l();
            this->u();
            this->L();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[25] == 'W') {
            this->f();
            this->u();
            this->F();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[30] == 'W') {
            this->r();
            this->u();
            this->R();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[37] == 'W') {
            this->b();
            this->u();
            this->B();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[12] == 'W') {
            this->L();
            this->u();
            this->l();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[19] == 'W') {
            this->F();
            this->u();
            this->f();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[32] == 'W') {
            this->R();
            this->u();
            this->r();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[43] == 'W') {
            this->B();
            this->u();
            this->b();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[10] == 'W') {
            this->L();
            this->L();
            this->u();
            this->l();
            this->l();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[21] == 'W') {
            this->F();
            this->F();
            this->u();
            this->f();
            this->f();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[28] == 'W') {
            this->R();
            this->R();
            this->u();
            this->r();
            this->r();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[39] == 'W') {
            this->B();
            this->B();
            this->u();
            this->b();
            this->b();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[50] == 'W' && cur_colors[21] != 'R') {
            this->F();
            this->F();
            this->u();
            this->f();
            this->f();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[52] == 'W' && cur_colors[28] != 'G') {
            this->R();
            this->R();
            this->u();
            this->r();
            this->r();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[48] == 'W' && cur_colors[39] != 'O') {
            this->B();
            this->B();
            this->u();
            this->b();
            this->b();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[46] == 'W' && cur_colors[10] != 'B') {
            this->L();
            this->L();
            this->u();
            this->l();
            this->l();
            itRotated = true;
            cur_colors = cube->getColors();
        }


        this->U();
        if (!itRotated) {
            cnt++;
        } else {
            cnt = 0;
        }
    }
    this->X();
    this->X();
    this->X();
    this->X();
}


void Events::cornerCross() {
    bool itRotated = false;
    std::string cur_colors = cube->getColors();
    int cnt = 0;
    while (cnt < 4) {
        itRotated = false;
        cur_colors = cube->getColors();
        if (cur_colors[17] == 'W' && cur_colors[2] == 'B' && cur_colors[20] == 'R') {
            this->l();
            this->u();
            this->L();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[26] == 'W' && cur_colors[8] == 'R' && cur_colors[35] == 'G') {
            this->f();
            this->u();
            this->F();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[33] == 'W' && cur_colors[6] == 'G' && cur_colors[44] == 'O') {
            this->r();
            this->u();
            this->R();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[38] == 'W' && cur_colors[0] == 'O' && cur_colors[15] == 'B') {
            this->b();
            this->u();
            this->B();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[15] == 'W' && cur_colors[0] == 'B' && cur_colors[38] == 'O') {
            this->L();
            this->U();
            this->l();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[20] == 'W' && cur_colors[2] == 'R' && cur_colors[17] == 'B') {
            this->F();
            this->U();
            this->f();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[35] == 'W' && cur_colors[8] == 'G' && cur_colors[26] == 'R') {
            this->R();
            this->U();
            this->r();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[44] == 'W' && cur_colors[6] == 'O' && cur_colors[33] == 'G') {
            this->B();
            this->U();
            this->b();
            itRotated = true;
            cur_colors = cube->getColors();
        }

        for (int i = 0; i < 9; i += 2) {
            if (cur_colors[i] == 'W') {
                if (cur_colors[15] == 'O' && cur_colors[38] == 'B') {
                    this->L();
                    this->u();
                    this->l();
                    this->u();
                    this->u();
                    this->L();
                    this->U();
                    this->l();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
                if (cur_colors[17] == 'R' && cur_colors[20] == 'B') {
                    this->F();
                    this->u();
                    this->f();
                    this->u();
                    this->u();
                    this->F();
                    this->U();
                    this->f();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
                if (cur_colors[26] == 'G' && cur_colors[35] == 'R') {
                    this->R();
                    this->u();
                    this->r();
                    this->u();
                    this->u();
                    this->R();
                    this->U();
                    this->r();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
                if (cur_colors[44] == 'G' && cur_colors[33] == 'O') {
                    this->B();
                    this->u();
                    this->b();
                    this->u();
                    this->u();
                    this->B();
                    this->U();
                    this->b();
                    itRotated = true;
                    cur_colors = cube->getColors();
                }
            }

        }

        if (cur_colors[11] == 'W') {
            this->l();
            this->u();
            this->L();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[24] == 'W') {
            this->f();
            this->u();
            this->F();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[27] == 'W') {
            this->r();
            this->u();
            this->R();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[36] == 'W') {
            this->b();
            this->u();
            this->B();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[18] == 'W') {
            this->l();
            this->u();
            this->L();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[29] == 'W') {
            this->f();
            this->u();
            this->F();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[42] == 'W') {
            this->r();
            this->u();
            this->R();
            itRotated = true;
            cur_colors = cube->getColors();
        }
        if (cur_colors[9] == 'W') {
            this->b();
            this->u();
            this->B();
            itRotated = true;
            cur_colors = cube->getColors();
        }


        if (cur_colors[45] == 'W' && (cur_colors[36] != 'O' || cur_colors[9] != 'B')) {
            this->L();
            this->u();
            this->l();
            itRotated = true;
            cur_colors = cube->getColors();
        }

        if (cur_colors[47] == 'W' && (cur_colors[18] != 'R' || cur_colors[11] != 'B')) {
            this->F();
            this->u();
            this->f();
            itRotated = true;
            cur_colors = cube->getColors();
        }

        if (cur_colors[53] == 'W' && (cur_colors[24] != 'R' || cur_colors[29] != 'G')) {
            this->R();
            this->u();
            this->r();
            itRotated = true;
            cur_colors = cube->getColors();
        }

        if (cur_colors[51] == 'W' && (cur_colors[42] != 'O' || cur_colors[27] != 'G')) {
            this->B();
            this->u();
            this->b();
            itRotated = true;
            cur_colors = cube->getColors();
        }

        if (!itRotated) {
            cnt++;
        } else {
            cnt = 0;
        }
        this->U();
    }
    this->X();
    this->X();
    this->X();
    this->X();
    this->Y();
    this->Y();
}


void Events::secondLayer() {
    std::string cur_colors = cube->getColors();
    bool itRotated = false;

    int cnt = 0;
    while (cur_colors[12] != cur_colors[14] || cur_colors[14] != 'B' ||
           cur_colors[19] != cur_colors[25] || cur_colors[25] != 'R' ||
           cur_colors[32] != cur_colors[30] || cur_colors[30] != 'G' ||
           cur_colors[43] != cur_colors[37] || cur_colors[37] != 'O' ||
           cur_colors[13] != 'B' || cur_colors[22] != 'R' || cur_colors[31] != 'G' || cur_colors[40] != 'O') {

        cnt = 0;
        itRotated = false;
        cur_colors = cube->getColors();
        while (cnt < 4) {
            itRotated = false;
            cur_colors = cube->getColors();
            if (cur_colors[16] == 'B' && cur_colors[1] == 'O') {
                this->u();
                this->b();
                this->U();
                this->B();
                this->U();
                this->L();
                this->u();
                this->l();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[23] == 'R' && cur_colors[5] == 'B') {
                this->u();
                this->l();
                this->U();
                this->L();
                this->U();
                this->F();
                this->u();
                this->f();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[34] == 'G' && cur_colors[7] == 'R') {
                this->u();
                this->f();
                this->U();
                this->F();
                this->U();
                this->R();
                this->u();
                this->r();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[41] == 'O' && cur_colors[3] == 'G') {
                this->u();
                this->r();
                this->U();
                this->R();
                this->U();
                this->B();
                this->u();
                this->b();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[16] == 'B' && cur_colors[1] == 'R') {
                this->U();
                this->F();
                this->u();
                this->f();
                this->u();
                this->l();
                this->U();
                this->L();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[23] == 'R' && cur_colors[5] == 'G') {
                this->U();
                this->R();
                this->u();
                this->r();
                this->u();
                this->f();
                this->U();
                this->F();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[34] == 'G' && cur_colors[7] == 'O') {
                this->U();
                this->B();
                this->u();
                this->b();
                this->u();
                this->r();
                this->U();
                this->R();
                itRotated = true;
                cur_colors = cube->getColors();
            }

            if (cur_colors[41] == 'O' && cur_colors[3] == 'B') {
                this->U();
                this->L();
                this->u();
                this->l();
                this->u();
                this->b();
                this->U();
                this->B();
                itRotated = true;
                cur_colors = cube->getColors();
            }


            this->U();
            if (!itRotated) {
                cnt++;
            } else {
                cnt = 0;
            }
        }
        if (cur_colors[14] != 'B' || cur_colors[19] != 'R') {
            this->U();
            this->F();
            this->u();
            this->f();
            this->u();
            this->l();
            this->U();
            this->L();
            cur_colors = cube->getColors();
        }
        if (cur_colors[25] != 'R' || cur_colors[32] != 'G') {
            this->U();
            this->R();
            this->u();
            this->r();
            this->u();
            this->f();
            this->U();
            this->F();
            cur_colors = cube->getColors();
        }
        if (cur_colors[30] != 'G' || cur_colors[43] != 'O') {
            this->U();
            this->B();
            this->u();
            this->b();
            this->u();
            this->r();
            this->U();
            this->R();
            cur_colors = cube->getColors();
        }
        if (cur_colors[12] != 'B' || cur_colors[37] != 'O') {
            this->U();
            this->L();
            this->u();
            this->l();
            this->u();
            this->b();
            this->U();
            this->B();
            cur_colors = cube->getColors();
        }
    }
    this->X();
    this->X();
    this->X();
    this->X();
}


void Events::upperCross() {
    std::string cur_colors = cube->getColors();
    if (cur_colors[23] == 'Y' && cur_colors[34] == 'Y' && cur_colors[1] == 'Y' && cur_colors[4] == 'Y' &&
        cur_colors[3] == 'Y') {
        this->F();
        this->U();
        this->R();
        this->u();
        this->r();
        this->f();
        cur_colors = cube->getColors();
    }
    if (cur_colors[23] == 'Y' && cur_colors[16] == 'Y' && cur_colors[7] == 'Y' && cur_colors[4] == 'Y' &&
        cur_colors[3] == 'Y') {
        this->L();
        this->U();
        this->F();
        this->u();
        this->f();
        this->l();
        cur_colors = cube->getColors();
    }
    if (cur_colors[34] == 'Y' && cur_colors[41] == 'Y' && cur_colors[1] == 'Y' && cur_colors[4] == 'Y' &&
        cur_colors[5] == 'Y') {
        this->R();
        this->U();
        this->B();
        this->u();
        this->b();
        this->r();
        cur_colors = cube->getColors();
    }
    if (cur_colors[16] == 'Y' && cur_colors[41] == 'Y' && cur_colors[4] == 'Y' && cur_colors[5] == 'Y' &&
        cur_colors[7] == 'Y') {
        this->B();
        this->U();
        this->L();
        this->u();
        this->l();
        this->b();
        cur_colors = cube->getColors();
    }
    if (cur_colors[23] == 'Y' && cur_colors[41] == 'Y' && cur_colors[1] == 'Y' && cur_colors[4] == 'Y' &&
        cur_colors[7] == 'Y') {
        this->F();
        this->R();
        this->U();
        this->r();
        this->u();
        this->f();
        cur_colors = cube->getColors();
    }
    if (cur_colors[16] == 'Y' && cur_colors[34] == 'Y' && cur_colors[3] == 'Y' && cur_colors[4] == 'Y' &&
        cur_colors[5] == 'Y') {
        this->R();
        this->B();
        this->U();
        this->b();
        this->u();
        this->r();
        cur_colors = cube->getColors();
    }
    if (cur_colors[23] == 'Y' && cur_colors[34] == 'Y' && cur_colors[41] == 'Y' && cur_colors[16] == 'Y') {
        this->F();
        this->U();
        this->R();
        this->u();
        this->r();
        this->f();
        this->R();
        this->B();
        this->U();
        this->b();
        this->u();
        this->r();
        cur_colors = cube->getColors();
    }
    if (cur_colors[1] != 'Y' || cur_colors[3] != 'Y' || cur_colors[4] != 'Y' || cur_colors[5] != 'Y' ||
        cur_colors[7] != 'Y') {
        throw std::logic_error("Cube is invalid");
    }

}

void Events::setUpeerCross() {
    std::string cur_colors = cube->getColors();
    if (cur_colors[34] == 'R') {
        this->U();
        this->l();
        this->u();
        this->u();
        this->L();
        this->U();
        this->l();
        this->U();
        this->L();
        cur_colors = cube->getColors();
    }
    if (cur_colors[16] == 'R') {
        this->U();
        this->b();
        this->u();
        this->u();
        this->B();
        this->U();
        this->b();
        this->U();
        this->B();
        cur_colors = cube->getColors();
    }
    if (cur_colors[41] == 'R') {
        this->U();
        this->r();
        this->u();
        this->u();
        this->R();
        this->U();
        this->r();
        this->U();
        this->R();
        this->U();
        this->b();
        this->u();
        this->u();
        this->B();
        this->U();
        this->b();
        this->U();
        this->B();
        this->U();
        this->r();
        this->u();
        this->u();
        this->R();
        this->U();
        this->r();
        this->U();
        this->R();
        cur_colors = cube->getColors();
    }
    if (cur_colors[41] == 'G') {
        this->U();
        this->f();
        this->u();
        this->u();
        this->F();
        this->U();
        this->f();
        this->U();
        this->F();
        cur_colors = cube->getColors();
    }
    if (cur_colors[16] == 'G') {
        this->U();
        this->b();
        this->u();
        this->u();
        this->B();
        this->U();
        this->b();
        this->U();
        this->B();
        this->U();
        this->l();
        this->u();
        this->u();
        this->L();
        this->U();
        this->l();
        this->U();
        this->L();
        this->U();
        this->b();
        this->u();
        this->u();
        this->B();
        this->U();
        this->b();
        this->U();
        this->B();
        cur_colors = cube->getColors();
    }
    if (cur_colors[16] == 'O') {
        this->U();
        this->r();
        this->u();
        this->u();
        this->R();
        this->U();
        this->r();
        this->U();
        this->R();
        cur_colors = cube->getColors();
    }
}



void Events::setUpperCorners() {
    std::string cur_colors = cube->getColors();
    bool isFirstVar = true;
    if (cur_colors[2] + cur_colors[17] + cur_colors[20] == 242) {
        this->f();
        this->l();
        this->F();
        this->r();
        this->f();
        this->L();
        this->F();
        this->R();
        cur_colors = cube->getColors();
        isFirstVar = false;
    }
    if (cur_colors[6] + cur_colors[33] + cur_colors[44] == 242) {
        this->r();
        this->f();
        this->l();
        this->F();
        this->R();
        this->f();
        this->L();
        this->F();
        cur_colors = cube->getColors();
        isFirstVar = false;
    }
    if (cur_colors[15] + cur_colors[0] + cur_colors[38] == 242) {
        this->f();
        this->l();
        this->b();
        this->L();
        this->F();
        this->l();
        this->B();
        this->L();
        cur_colors = cube->getColors();
        isFirstVar = false;
    }
    if (cur_colors[2] + cur_colors[17] + cur_colors[20] == 239) {
        this->b();
        this->r();
        this->B();
        this->l();
        this->b();
        this->R();
        this->B();
        this->L();
        cur_colors = cube->getColors();
    }
    if (cur_colors[15] + cur_colors[0] + cur_colors[38] == 239) {
        this->l();
        this->b();
        this->r();
        this->B();
        this->L();
        this->b();
        this->R();
        this->B();
        cur_colors = cube->getColors();
    }
    if (checkSum() == false) {
        throw std::logic_error("Cube is invalid");
    }
}

bool Events::checkSum() {
    std::string cur_colors = cube->getColors();
    bool flag = true;
    if (cur_colors[2] + cur_colors[17] + cur_colors[20] != 237) {
        flag = false;
    }
    if (cur_colors[8] + cur_colors[26] + cur_colors[35] != 242) {
        flag = false;
    }
    if (cur_colors[6] + cur_colors[33] + cur_colors[44] != 239) {
        flag = false;
    }
    if (cur_colors[0] + cur_colors[38] + cur_colors[15] != 234) {
        flag = false;
    }
    return flag;
}

void Events::setAllCorners() {
    std::string cur_corners = cube->getColors();
    for (int i = 0; i < 4; ++i) {
        cur_corners = cube->getColors();
        if (cur_corners[35] == 'Y') {
            this->f();
            this->R();
            this->F();
            this->r();
            this->f();
            this->R();
            this->F();
            this->r();
            cur_corners = cube->getColors();
        }
        if (cur_corners[26] == 'Y') {
            this->R();
            this->f();
            this->r();
            this->F();
            this->R();
            this->f();
            this->r();
            this->F();
            cur_corners = cube->getColors();
        }
        if (isReady()) {
            break;
        }
        this->U();
    }
    if (!isReady()) {
        throw std::logic_error("Cube is invalid");
    }
    for (int i = 0; i < 4; ++i) {
        this->X();
    }
}
void Events::shuffle() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 20);
    std::uniform_int_distribution<> distribution(0, 11);

    for (int i = 0; i < distrib(rd); ++i) {
        switch (distribution(rd)) {
            case 0:
                F();
                break;
            case 1:
                R();
                break;
            case 2:
                L();
                break;
            case 3:
                B();
                break;
            case 4:
                U();
                break;
            case 5:
                D();
                break;
            case 6:
                f();
                break;
            case 7:
                r();
                break;
            case 8:
                l();
                break;
            case 9:
                b();
                break;
            case 10:
                u();
                break;
            case 11:
                d();
                break;

        }
    }
}
