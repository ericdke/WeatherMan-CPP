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
private:
    boost::property_tree::ptree tree;
};

#endif /* JSONReader_hpp */
