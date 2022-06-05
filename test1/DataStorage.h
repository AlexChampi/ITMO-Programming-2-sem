//
// Created by alekschamp on 05.03.2022.
//
#pragma once

#ifndef TEST1_DATASTORAGE_H
#define TEST1_DATASTORAGE_H

#include <map>
#include <vector>
#include <iostream>

class DataStorage {
protected:
    std::map<std::string, std::map<double, int>> curseLog;
    std::map<std::string, double> currentCurse;
public:
    std::map<std::string, std::map<double, int>> getLog();

    void showActualCurse();

    DataStorage getDataStorage();
};


#endif //TEST1_DATASTORAGE_H
