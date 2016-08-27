//
//  main.cpp
//  WeatherManCLI-C++
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Downloader.hpp"
#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
using namespace std;

string makeURL(int argc, const char * argv[])
{
    if(argc > 1)
    {
        string input;
        for(int i = 1; i < argc; i++) {
            input += argv[i];
        }
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

int main(int argc, const char * argv[])
{
    string url = makeURL(argc, argv);
    if (url != "")
    {
        HTTPDownloader downloader;
        string content = downloader.download(url);
        cout << content << endl;
        return 0;
    }
    else
    {
        cout << "Usage: weatherman city,country" << endl;
        return 1;
    }
}
