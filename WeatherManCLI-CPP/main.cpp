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
    cout << "\nCreating request..." << endl;
    HTTPDownloader downloader;
    string url = downloader.makeURL(argc, argv);
    if (url != "")
    {
        cout << "Downloading data..." << endl;
        string content = downloader.download(url);
        JSONReader reader;
        cout << "Parsing response..." << endl;
        CurrentWeather weather = reader.parse(content);
        cout << "\nResult:\n" << endl;
        cout << weather.description() << endl;
        return 0;
    }
    else
    {
        cout << "Usage:\n\tweatherman city,country" << endl;
        return 1;
    }
}
