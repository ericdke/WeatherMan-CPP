//
//  main.cpp
//  WeatherManCLI-C++
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Utils.hpp"
#include "Downloader.hpp"
#include "JSONReader.hpp"

using namespace std;

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
        
        Weather w = reader.parse(json);
        
        print("\nResult:\n");
        
        print(w.description());
        
        return 0;
    }
    else
    {
        print("Usage:\n\tweatherman city,country");
        return 1;
    }
}
