//
// Created by alekschamp on 18.05.22.
//

#include <iostream>
#include "FileManager.h"

std::string FileManager::inputFile;
std::ifstream FileManager::in;
std::ofstream FileManager::out;

void FileManager::initialize(const std::string & filename) {
    inputFile = filename;
    in.open(inputFile);
    out.open("log.txt");
}
