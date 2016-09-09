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

    auto cod = tree.get<string>("cod");
    if(cod != "200")
    {
        if(cod == "404")
        {
            std::cout << "\nERROR: does not exist." << std::endl;
            exit(1);
        }
        std::cout << "\nERROR: " << cod << std::endl;
        exit(1);
    }
    w.temp = tree.get<float>("main.temp");
    w.city = tree.get<string>("name");
    w.country = tree.get<string>("sys.country");
    w.wind_speed = tree.get<float>("wind.speed");
    w.wind_direction = tree.get<float>("wind.deg");
    // A JSON array becomes a node where each item is a child node with an empty name.
    ptree it = tree.get_child("weather").front().second;
    w.category = it.get<string>("main");
    w.icon_url = "http://openweathermap.org/img/w/" + it.get<string>("icon") + ".png";
    w.sub_category = it.get<string>("description");
    return w;
}
