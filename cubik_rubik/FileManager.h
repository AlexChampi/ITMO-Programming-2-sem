//
// Created by alekschamp on 18.05.22.
//

#ifndef CUBIK_RUBIK_FILEMANAGER_H
#define CUBIK_RUBIK_FILEMANAGER_H


#include <string>
#include <fstream>

class FileManager {
private:
    static std::string inputFile;
public:
    static std::ifstream in;
    static std::ofstream out;
    static void initialize(const std::string & filename);

};


#endif //CUBIK_RUBIK_FILEMANAGER_H
