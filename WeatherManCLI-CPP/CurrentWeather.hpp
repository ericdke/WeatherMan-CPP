//
//  CurrentWeather.hpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef CurrentWeather_hpp
#define CurrentWeather_hpp

#include <iostream>

class CurrentWeather {
public:
    float temp;
    std::string city;
    std::string country;
    std::string category;
    std::string sub_category;
    float wind_speed;
    int wind_direction;
    std::string icon_url;
};

#endif /* CurrentWeather_hpp */
