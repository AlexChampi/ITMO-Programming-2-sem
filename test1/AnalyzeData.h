//
// Created by alekschamp on 06.03.2022.
//

#ifndef TEST1_ANALYZEDATA_H
#define TEST1_ANALYZEDATA_H

#include <numeric>
#include <iostream>
#include <utility>
#include "DataStorage.h"

class AnalyzeData {
private:
    DataStorage dataStorage;
    int amount = countAmount();
public:
    explicit AnalyzeData(DataStorage);

    void showData();

    void showAverage();

    void showMedine();

    void showBoarder();

    int countAmount();
};


#endif //TEST1_ANALYZEDATA_H
