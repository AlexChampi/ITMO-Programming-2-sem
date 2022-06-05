//
// Created by alekschamp on 05.03.2022.
//


#include "Page.h"
#include <iostream>

Page::Page() {
    curl_global_init(CURL_GLOBAL_ALL);
}

std::string Page::update() {

    curl = curl_easy_init();
    std::string readBuffer;
    std::string tokenHeader = "X-CMC_PRO_API_KEY: " + APIInfo().getToken();
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, tokenHeader.c_str());
    curl_easy_setopt(curl, CURLOPT_URL, APIInfo().getURL().c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return readBuffer;


}

size_t Page::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

Page::~Page() {
    curl_global_cleanup();
}
