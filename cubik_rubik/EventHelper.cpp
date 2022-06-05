//
// Created by alekschamp on 19.05.22.
//

#include "EventHelper.h"

EventHelper::EventHelper(float angle, float maxAngle) : angle(angle), max_angle(maxAngle) {}

bool EventHelper::isValid() {
    return (angle < max_angle + 90) && (angle > max_angle - 90);
}
