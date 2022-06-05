//
// Created by alekschamp on 05.03.2022.
//

#include "DataStorage.h"

std::map<std::string, std::map<double, int>> DataStorage::getLog() {
    return curseLog;
}

void DataStorage::showActualCurse() {
    for (auto &i : currentCurse) {
        std::cout << i.first << " " << i.second << '\n';
    }
    std::cout << '\n';
}
DataStorage DataStorage::getDataStorage() {
    return *this;
}