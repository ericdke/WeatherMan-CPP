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

using namespace std;

int main(int argc, const char * argv[])
{
    HTTPDownloader downloader;
    JSONReader reader;
    string url = downloader.makeURL(argc, argv);
    if (url != "")
    {
        string content = downloader.download(url);
        CurrentWeather weather = reader.parse(content);
        cout << weather.description() << endl;
        return 0;
    }
    else
    {
        cout << "Usage:\n\tweatherman city,country" << endl;
        return 1;
    }
}
