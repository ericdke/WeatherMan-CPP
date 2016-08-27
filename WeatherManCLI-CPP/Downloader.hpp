//
//  Downloader.hpp
//  dl
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

/**
 * HTTPDownloader.hpp
 *
 * A simple C++ wrapper for the libcurl easy API.
 *
 * Written by Uli Köhler (techoverflow.net)
 * Published under CC0 1.0 Universal (public domain)
 */
#ifndef HTTPDOWNLOADER_HPP
#define HTTPDOWNLOADER_HPP

#include <string>
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <sstream>
#include <iostream>

/**
 * A non-threadsafe simple libcURL-easy based HTTP downloader
 */
class HTTPDownloader {
public:
    HTTPDownloader();
    ~HTTPDownloader();
    /**
     * Download a file using HTTP GET and store in in a std::string
     * @param url The URL to download
     * @return The download result
     */
    std::string download(const std::string& url);
    std::string makeURL(int argc, const char * argv[]);
private:
    void* curl;
};

#endif  /* HTTPDOWNLOADER_HPP */
