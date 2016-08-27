//
//  main.cpp
//  WeatherManCLI-C++
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Downloader.hpp"
#include "JSONReader.hpp"
#include "CurrentWeather.hpp"
#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
using namespace std;

int main(int argc, const char * argv[])
{
    JSONReader reader;
    HTTPDownloader downloader;
    string url = downloader.makeURL(argc, argv);
    if (url != "")
    {
        string content = downloader.download(url);
        CurrentWeather weather = reader.parse(content);
        cout << weather.temp << endl;
        cout << weather.city << endl;
        cout << weather.country << endl;
        cout << weather.wind_speed << endl;
        cout << weather.wind_direction << endl;
        cout << weather.category << endl;
        cout << weather.sub_category << endl;
        cout << weather.icon_url << endl;
        return 0;
    }
    else
    {
        cout << "Usage:\n\tweatherman city,country" << endl;
        return 1;
    }
}
