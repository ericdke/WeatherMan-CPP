//
//  CurrentWeather.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "CurrentWeather.hpp"
#include <cmath>
#include <vector>
#include <ctime>
//#include <ostream>
//#include <iostream>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <iomanip>

using namespace std;

float CurrentWeather::wind_speed_kmh()
{
    return floor(((wind_speed * 3.6) * 5 + 0.5) / 5);
}

string CurrentWeather::wind_direction_compass()
{
    vector<string> compass = {"Nord","Nord Nord-Est","Nord-Est","Est-Nord-Est","Est","Est-Sud-Est","Sud-Est","Sud-Sud-Est","Sud","Sud-Sud-Ouest","Sud-Ouest","Ouest-Sud-Ouest","Ouest","Ouest-Nord-Ouest","Nord-Ouest","Nord-Nord-Ouest"};
    double sp = (((double) wind_speed) / 22.5) + 0.5;
    int index = fmod(sp, 16);
    return compass[index];
}

string CurrentWeather::description()
{
    string d = date_formatted();
    
    stringstream stream;
    stream << fixed << setprecision(1) << temp;
    string st = stream.str();
    string s = city + " (" + country + "), le " + d + ". Température: ";
    string te = boost::lexical_cast<string>(st);
    // TODO: check if wind
    string ws = boost::lexical_cast<string>(wind_speed_kmh());
    string desc = s + te + "°C, temps: " + category + " (" + sub_category + "), vent: direction " + wind_direction_compass() + " à " + ws + " km/h.";
    return desc;
}

string CurrentWeather::date_formatted()
{
    time_t temps;
    struct tm datetime;
    char format_date[32];
    char format_temps[32];
    time(&temps);
    datetime = *localtime(&temps);
    strftime(format_date, 32, "%d/%m/%Y", &datetime);
    strftime(format_temps, 32, "%Hh%M", &datetime);
    string fd = (string) format_date;
    string ft = (string) format_temps;
    return fd + ", " + ft;
}



