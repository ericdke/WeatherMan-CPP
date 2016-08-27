//
//  Utilities.hpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 27/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef Utilities_hpp
#define Utilities_hpp

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <iomanip>

class Utilities {
public:
    static std::string float_to_string(float const& f, int const& p); // float, precision
};

#endif /* Utilities_hpp */
