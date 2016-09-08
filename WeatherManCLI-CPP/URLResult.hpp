//
//  URLResult.hpp
//  weatherman
//
//  Created by ERIC DEJONCKHEERE on 08/09/2016.
//  Copyright © 2016 AYA.io. All rights reserved.
//

#ifndef URLResult_hpp
#define URLResult_hpp

#include <string>

struct URLResult {
    URLResult(bool s, std::string r) : success(s), url(r) {};
    bool success;
    std::string url;
};

#endif /* URLResult_hpp */
