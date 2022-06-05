//
// Created by alekschamp on 05.03.2022.
//
#pragma once

#ifndef TEST1_PAGE_H
#define TEST1_PAGE_H

#include "APIInfo.h"
#include <curl/curl.h>

class Page {
private:
    CURL *curl{};

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

public:
    Page();

    std::string update();

    ~Page();
};


#endif //TEST1_PAGE_H
