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
#include "Weather.hpp"
#include <sstream>

class JSONReader {
    void check_code(boost::property_tree::ptree* tree);
public:
    Weather parse(std::string const& json);
};

#endif /* JSONReader_hpp */
