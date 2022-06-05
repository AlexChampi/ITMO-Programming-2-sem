//
// Created by alekschamp on 05.03.2022.
//
#pragma once

#ifndef TEST1_APIINFO_H
#define TEST1_APIINFO_H


#include <string>

class APIInfo {
    std::string token = "5af9f9cb-cbc5-4755-8508-b5f393599452";
    std::string url = "https://pro-api.coinmarketcap.com/v1/cryptocurrency/listings/latest?start=1&limit=5&convert=USD";
public:
    std::string getURL();

    std::string getToken();
};


#endif //TEST1_APIINFO_H
