//
//  Utils.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 28/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Utils.hpp"

std::string float_to_string(float const& f, int const& p)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(p) << f;
    return stream.str();
}

void print(std::string const& s)
{
    std::cout << s << std::endl;
}
