//
//  JSONReader.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "JSONReader.hpp"
#include "Weather.hpp"

using namespace std;
using namespace boost::property_tree;

Weather JSONReader::parse(string const& json)
{
    // read_json wants either a filename or a stream
    // so we make our JSON string a stringstream
    istringstream j(json);
    // populate a tree with the JSON
    ptree tree;
    read_json(j, tree);
    // the class instance we return as value
    Weather w;
    // find the key then get its typed value
    w.temp = tree.get_child("main.temp").get_value<float>();
    w.city = tree.get_child("name").get_value<string>();
    w.country = tree.get_child("sys.country").get_value<string>();
    w.wind_speed = tree.get_child("wind.speed").get_value<float>();
    w.wind_direction = tree.get_child("wind.deg").get_value<float>();
    // TODO: just take the last object in the array instead of looping
    BOOST_FOREACH(ptree::value_type& obj, tree.get_child("weather"))
    {
        w.category = obj.second.get_child("main").get_value<string>();
        w.icon_url = "http://openweathermap.org/img/w/" + obj.second.get_child("icon").get_value<string>() + ".png";
        w.sub_category = obj.second.get_child("description").get_value<string>();
    }
    return w;
}
