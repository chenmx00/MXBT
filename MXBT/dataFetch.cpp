//
//  dataFetch.cpp
//  MXBT
//
//  Created by Minxing Chen on 10/25/20.
//

#include "dataFetch.hpp"
#ifndef fstream
#include <fstream>
#endif

#ifndef iostrean
#include <iostream>
#endif

#include <curl/curl.h>
#include <chrono>
#include <cmath>

using namespace std;

size_t write(void *ptr, size_t size, size_t nmemb, FILE *stream){
    return fwrite(ptr, size, nmemb, stream);
}

const char* get_configure(char *symbol, char filename[MAX_LENGTH], char crumbFilename[MAX_LENGTH]){
    CURL *cookieURL = curl_easy_init();
    FILE * crumbFile;

    
}

dataFetch::dataFetch(char *symbol, long start_date, long end_date, char filename[MAX_LENGTH], char cookie[MAX_LENGTH], char crumbFilename[MAX_LENGTH]){
    auto interval = "one"; // unit: days
    CURLcode *code;
    FILE *fp;
    string yahoo_url = string("https://query1.finance.yahoo.com/v7/finance/download/") + string(symbol) + string("?period1=") + to_string(start_date) + string("&period2=") + to_string(end_date) + string("&interval=") + string(interval) + string("&events=history&crumb=") + get_crumb_and_cookies(symbol, cookie, crumbFilename);
    CURL *curl = curl = curl_easy_init(); // Curl initialization.
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, cookie); //Set cookies.
    curl_easy_setopt(curl, CURLOPT_URL, yahoo_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
    fp = fopen(filename, "wb");
    // writing data into the file.
    if (fp) {
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        fclose(fp);
    }
    
    
    market = MarketDataProc(filename, symbol);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
};
