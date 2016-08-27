//
//  Utilities.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Utilities.hpp"

std::string Utilities::float_to_string(float const& f, int const& p)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(p) << f;
    return stream.str();
}
