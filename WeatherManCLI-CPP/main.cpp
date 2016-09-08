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

int main(int argc, const char * argv[])
{
    HTTPDownloader dl;
    
    URLResult u = dl.makeURL(argc, argv);
    
    if(u.success)
    {
        print("\nDownloading data...");
        
        std::string json = dl.download(u.url);
        
        JSONReader rd;
        
        print("Parsing response...");
        
        Weather w = rd.parse(json);
        
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
