//
//  Utilities.cpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#include "Utilities.hpp"

std::string Utilities::float_to_string(float f)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << f;
    return stream.str();
}
