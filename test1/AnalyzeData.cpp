//
// Created by alekschamp on 06.03.2022.
//

#include "AnalyzeData.h"



AnalyzeData::AnalyzeData(DataStorage dataStorage) : dataStorage(std::move(dataStorage)) {}

void AnalyzeData::showAverage() {
    std::cout << "=====AVERAGE=====\n";
    for (auto &item: dataStorage.getLog()) {
        double result = 0;
        std::cout << item.first << ": ";
        for (auto &j: item.second) {
            result += j.first * j.second / amount;
        }
        std::cout << result << "\n";
    }
}

void AnalyzeData::showData() {
    std::cout << "=====DATA=====\n";
    for (auto &item: dataStorage.getLog()) {
        std::cout << item.first << ": ";
        for (auto &j: item.second) {
            std::cout << j.first << " - " << j.second << "; ";
        }
        std::cout << '\n';
    }

}

void AnalyzeData::showMedine() {
    std::cout << "=====MEDINE=====\n";
    for (auto &item: dataStorage.getLog()) {
        std::cout << item.first << ": ";
        int cnt = amount / 2;
        for (auto &j: item.second) {
            cnt -= j.second;
            if (cnt <= 0) {
                std::cout << j.first << '\n';
                break;
            }
        }

    }
}

void AnalyzeData::showBoarder() {
    std::cout << "=====MIN-MAX=====\n";
    for (auto &item: dataStorage.getLog()) {
        std::cout << item.first << ": ";
        std::cout << item.second.begin()->first << " - ";
        std::cout << (--item.second.end())->first << '\n';
    }
}

int AnalyzeData::countAmount() {
    auto i = dataStorage.getLog().begin()->second;
    int result = 0;
    for (auto &j: i) {
        result += j.second;
    }
    return result;
}
