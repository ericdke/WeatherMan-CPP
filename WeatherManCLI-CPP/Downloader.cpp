//
//  Downloader.cpp
//  dl
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Downloader.hpp"

URLResult HTTPDownloader::makeURL(int argc, const char * argv[])
{
    if(argc > 1)
    {
        // make a single string from all CLI input
        std::string input;
        for(int i = 1; i < argc; i++) {
            input += argv[i];
        }
        
        std::string url = "http://api.openweathermap.org/data/2.5/weather?q="
        + input
        + "&appid=d21991d7851f849bfe8cc24d12c795d0&units=metric&lang=fr";
        
        return URLResult(true, url);
    }
    return URLResult(false, "");
}

std::string HTTPDownloader::download(const std::string &url)
{
    RestClient::Response res = RestClient::get(url);

    if(res.code != 200)
    {
        std::cout << "ERROR " << res.code << std::endl;
        exit(1);
    }
    return res.body;
}
