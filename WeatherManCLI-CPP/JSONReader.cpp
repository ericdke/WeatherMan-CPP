//
//  JSONReader.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "JSONReader.hpp"
#include "CurrentWeather.hpp"


using namespace std;
using namespace boost::property_tree;

CurrentWeather JSONReader::parse(string const& json)
{
    istringstream j(json);
    read_json(j, tree);
    weather.temp = tree.get_child("main.temp").get_value<float>();
    weather.city = tree.get_child("name").get_value<string>();
    weather.country = tree.get_child("sys.country").get_value<string>();
    weather.wind_speed = tree.get_child("wind.speed").get_value<float>();
    weather.wind_direction = tree.get_child("wind.deg").get_value<float>();
    BOOST_FOREACH(ptree::value_type& obj, tree.get_child("weather"))
    {
        weather.category = obj.second.get_child("main").get_value<string>();
        weather.icon_url = "http://openweathermap.org/img/w/" + obj.second.get_child("icon").get_value<string>() + ".png";
        weather.sub_category = obj.second.get_child("description").get_value<string>();
    }
    return weather;
}

const void JSONReader::print_source()
{
    print(tree);
}
