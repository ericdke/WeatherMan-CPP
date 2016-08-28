//
//  Utils.hpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 28/08/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <iomanip>

std::string float_to_string(float const& f, int const& p);
void print(std::string const& s);

#endif /* Utils_hpp */
