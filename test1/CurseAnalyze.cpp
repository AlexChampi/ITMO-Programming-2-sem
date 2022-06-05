//
// Created by alekschamp on 06.03.2022.
//

#include "CurseAnalyze.h"

void t(bool &isActive) {
    std::string input;
    std::cin >> input;
    isActive = false;
}


void CurseAnalyze::startAnalyze() {
    bool isActive = true;

    std::thread thr(t, std::ref(isActive));
    while (isActive) {
        std::string stringForParsing = page.update();
        jsonParser.addActualCurse(stringForParsing);
        jsonParser.showActualCurse();
        std::this_thread::sleep_for(10s);
    }
    thr.join();

}

void CurseAnalyze::showResults() {
    AnalyzeData analyzeData(jsonParser.getDataStorage());
    analyzeData.showData();

    analyzeData.showMedine();
    analyzeData.showAverage();
    analyzeData.showBoarder();
}

//bool CurseAnalyze::isActual() {
//    std::string input;
//    if (!(std::cin >> input)) {
//        return true;
//    }
//    return false;
//}

//void CurseAnalyze::resultsToFile(const std::string &file) {
//    jsonParser.writeToFile(file);
//}
//
//void CurseAnalyze::analyzeFromFile(const std::string &string) {
//    std::ifstream fin(string);
//    //std::cout << string;
//    nlohmann::json json = nlohmann::json::parse(fin);
//    //std::cout << json[0];
//    jsonParser.clearVector();
//    for (size_t size = 0; size < json.size(); ++size) {
//        jsonParser.addToVector(json[size]);
//    }
//    jsonParser.addActualCurse();
//    showResults();
//}