//
//  JSONReader.hpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef JSONReader_hpp
#define JSONReader_hpp

#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "CurrentWeather.hpp"
#include <sstream>

class JSONReader {
public:
    CurrentWeather parse(std::string const& json);
    void print_source();
private:
    std::string source;
    boost::property_tree::ptree tree;
    CurrentWeather weather;
    void print(boost::property_tree::ptree const& ptr)
    {
        boost::property_tree::ptree::const_iterator end = ptr.end();
        for (boost::property_tree::ptree::const_iterator iter = ptr.begin(); iter != end; ++iter)
        {
            std::cout << iter->first << ": " << iter->second.get_value<std::string>() << std::endl;
            print(iter->second);
        }
    }
};

#endif /* JSONReader_hpp */
