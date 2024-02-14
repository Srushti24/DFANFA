//
//  Regex.hpp
//  DFAConverter
//
//  Created by Srushti Desai on 1/7/24.
//

#ifndef Regex_hpp
#define Regex_hpp

#include <stdio.h>
#include <iostream>

struct Regex {
    enum Type {
        EPSILON, // E
        ALPHABET, // a,b,c
        UNION, // |
        CONCAT, // multiply
        KSTAR // star
    };
    Type type;
    std::vector<Regex> children;
    char alphabet;
};

#endif /* Regex_hpp */
