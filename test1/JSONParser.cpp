//
// Created by alekschamp on 05.03.2022.
//

#include <fstream>
#include "JSONParser.h"

//void JSONParser::parse(const std::string &string) {
//    nlohmann::json json1 = nlohmann::json::parse(string);
//    json.push_back(json1);
//}

void JSONParser::addActualCurse(const std::string &val) {
    nlohmann::json j = nlohmann::json::parse(val);
    nlohmann::json coins = j["data"];
    currentCurse.clear();
    for (auto &i: coins) {
        std::map<double, int> &tmp = curseLog[i["symbol"].get<std::string>()];
        currentCurse[i["symbol"].get<std::string>()] = i["quote"]["USD"]["price"];
        tmp[i["quote"]["USD"]["price"]] += 1;
    }

}


//void JSONParser::writeToFile(const std::string &fileName) {
//    std::ifstream in(fileName);
//    nlohmann::json jsonFile = nlohmann::json::parse(in);
//    std::ofstream out(fileName);
//    for (auto &item: json) {
//        jsonFile[jsonFile.size()].update(item);
//    }
//    out << jsonFile;
//    out.close();
//    in.close();
//
//}
//
//void JSONParser::addToVector(nlohmann::json json1) {
//    json.push_back(json1);
//}
//
//void JSONParser::clearVector() {
//    json.clear();
//}
//curseLog[i["symbol"].get<std::string>()] = i["quote"]["USD"]["price"].get<double>() += 1;


