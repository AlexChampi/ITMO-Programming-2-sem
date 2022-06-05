//
// Created by alekschamp on 06.03.2022.
//
#pragma once
#ifndef TEST1_CURSEANALYZE_H
#define TEST1_CURSEANALYZE_H

#include "Page.h"
#include "JSONParser.h"
#include <chrono>
#include <thread>
#include "AnalyzeData.h"
#include <fstream>
#include <iostream>

using namespace nlohmann;
using namespace std::chrono_literals;

class CurseAnalyze {
private:
    JSONParser jsonParser;
    Page page;
public:
    void startAnalyze();

    void showResults();

//    void resultsToFile(const std::string &file);
//
//    void analyzeFromFile(const std::string &string);
//
//    bool isActual();
};

#endif //TEST1_CURSEANALYZE_H
