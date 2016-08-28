//
//  Downloader.cpp
//  dl
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

// -----
/**
 * HTTPDownloader.cpp
 *
 * A simple C++ wrapper for the libcurl easy API.
 *
 * Written by Uli Köhler (techoverflow.net)
 * Published under CC0 1.0 Universal (public domain)
 */
#include "Downloader.hpp"

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data << endl;
    return size * nmemb;
}

HTTPDownloader::HTTPDownloader() {
    curl = curl_easy_init();
}

HTTPDownloader::~HTTPDownloader() {
    curl_easy_cleanup(curl);
}

string HTTPDownloader::download(const std::string& url) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    /* we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1); //Prevent "longjmp causes uninitialized stack frame" bug
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
    /* Perform the request, res will get the return code */
    CURLcode res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    
    return out.str();
}
// -----

string HTTPDownloader::makeURL(int argc, const char * argv[])
{
    if(argc > 1)
    {
        // make a single string from all CLI input
        string input;
        for(int i = 1; i < argc; i++) {
            input += argv[i];
        }
        // TODO: percent escape accented characters
        string url = "http://api.openweathermap.org/data/2.5/weather?q="
        + input
        + "&appid=d21991d7851f849bfe8cc24d12c795d0&units=metric&lang=fr";
        return url;
    }
    else
    {
        return "";
    }
}
