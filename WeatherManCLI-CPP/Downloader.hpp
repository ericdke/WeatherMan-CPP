//
//  Downloader.hpp
//  dl
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef HTTPDOWNLOADER_HPP
#define HTTPDOWNLOADER_HPP

#include <string>
#include <sstream>
#include <iostream>
#include "restclient-cpp/restclient.h"
#include "URLResult.hpp"

class HTTPDownloader {
public:
    std::string download(const std::string& url);
    URLResult makeURL(int argc, const char * argv[]);
};

#endif  /* HTTPDOWNLOADER_HPP */
