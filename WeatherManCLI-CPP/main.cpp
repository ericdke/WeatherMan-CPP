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

void print(string const& s)
{
    cout << s << endl;
}

int main(int argc, const char * argv[])
{
    HTTPDownloader downloader;
    
    string url = downloader.makeURL(argc, argv);
    
    if (url != "")
    {
        print("\nDownloading data...");
        
        string json = downloader.download(url);
        
        JSONReader reader;
        
        print("Parsing response...");
        
        CurrentWeather weather = reader.parse(json);
        
        print("\nResult:\n");
        
        print(weather.description());
        
        return 0;
    }
    else
    {
        print("Usage:\n\tweatherman city,country");
        return 1;
    }
}
