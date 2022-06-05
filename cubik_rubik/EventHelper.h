//
// Created by alekschamp on 19.05.22.
//

#ifndef CUBIK_RUBIK_EVENTHELPER_H
#define CUBIK_RUBIK_EVENTHELPER_H


#include "Window.h"

class EventHelper {
public:
    float angle;
    float max_angle;
public:
    EventHelper(float angle, float maxAngle);
    bool isValid();
};


#endif //CUBIK_RUBIK_EVENTHELPER_H
