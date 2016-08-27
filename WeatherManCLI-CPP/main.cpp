//
//  main.cpp
//  WeatherManCLI-C++
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Downloader.hpp"
#include "JSONReader.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    HTTPDownloader downloader;
    string url = downloader.makeURL(argc, argv);
    if (url != "")
    {
        cout << "Downloading..." << endl;
        string content = downloader.download(url);
        JSONReader reader;
        cout << "Parsing..." << endl;
        CurrentWeather weather = reader.parse(content);
        cout << "Result:\n" << endl;
        cout << weather.description() << endl;
        return 0;
    }
    else
    {
        cout << "Usage:\n\tweatherman city,country" << endl;
        return 1;
    }
}
