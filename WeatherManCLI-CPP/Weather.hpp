//
//  Weather.hpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef Weather_hpp
#define Weather_hpp

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iomanip>
#include "Utils.hpp"

struct DateTime {
    std::string date;
    std::string time;
};

class Weather {
public:
    float temp;
    std::string city;
    std::string country;
    std::string category;
    std::string sub_category;
    std::string icon_url;
    float wind_speed;
    float wind_direction;
    float wind_speed_kmh();
    std::string wind_direction_compass();
    std::string description();
private:
    DateTime date_formatted();
};

#endif /* Weather_hpp */
