//
// Created by alekschamp on 05.03.2022.
//
#pragma once
#ifndef TEST1_JSONPARSER_H
#define TEST1_JSONPARSER_H

#include "nlohmann/json.hpp"
#include "DataStorage.h"
#include <vector>

class JSONParser : public DataStorage {

public:


    void addActualCurse(const std::string &val);

//    void writeToFile(const std::string &fileName);
//
//    void clearVector();
//    void parse(const std::string &);
//
//    void addToVector(nlohmann::json json);
};


#endif //TEST1_JSONPARSER_H
