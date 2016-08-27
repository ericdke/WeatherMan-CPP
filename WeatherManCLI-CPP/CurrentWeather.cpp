//
//  CurrentWeather.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "CurrentWeather.hpp"
#include "Utilities.hpp"

using namespace std;

float CurrentWeather::wind_speed_kmh()
{
    return floor(((wind_speed * 3.6) * 5 + 0.5) / 5);
}

string CurrentWeather::wind_direction_compass()
{
    vector<string> compass = {"Nord","Nord Nord-Est","Nord-Est","Est-Nord-Est","Est","Est-Sud-Est","Sud-Est","Sud-Sud-Est","Sud","Sud-Sud-Ouest","Sud-Ouest","Ouest-Sud-Ouest","Ouest","Ouest-Nord-Ouest","Nord-Ouest","Nord-Nord-Ouest"};
    double sp = (((double) wind_direction) / 22.5) + 0.5;
    int index = fmod(sp, 16);
    return compass[index];
}

string CurrentWeather::description()
{
    DateTime dt = date_formatted();
    string dts = dt.date + ", " + dt.time;
    string cel = Utilities::float_to_string(temp, 1);
    string ci = city + " (" + country + "), le " + dts + ".\n";
    string te = "Température: " + cel + "°C.\n";
    string ca = ci + te + "Temps: " + category + " (" + sub_category + ").\n";
    // TODO: check if wind
    string w = Utilities::float_to_string(wind_speed_kmh(), 1);
    string desc = ca + "Vent: " + wind_direction_compass() + " à " + w + " km/h.";
    return desc;
}

DateTime CurrentWeather::date_formatted()
{
    time_t temps;
    struct tm datetime;
    char format_date[32];
    char format_temps[32];
    time(&temps);
    datetime = *localtime(&temps);
    strftime(format_date, 32, "%d/%m/%Y", &datetime);
    strftime(format_temps, 32, "%Hh%M", &datetime);
    DateTime dt;
    dt.date = (string) format_date;
    dt.time = (string) format_temps;
    return dt;
}



