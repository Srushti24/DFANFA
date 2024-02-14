//
//  NFAConverter.hpp
//  DFAConverter
//
//  Created by Srushti Desai on 1/6/24.
//

#ifndef NFAConverter_hpp
#define NFAConverter_hpp


#include <stdio.h>
#include <iostream>
#include "State.hpp"
#include<deque>
#include<stack>
#include "Regex.hpp"


class NFAConverter
{
public:
    NFAConverter();
    ~NFAConverter();
    void convertExpression(Regex& tree);
    
private:
    std::string m_expression;
    std::stack<char> operands;
    std::stack<std::deque<State*> >m_stateStack;
    int m_stateNumber;
    void push(char& input);
    void Union();
    void Compact();
    void Star();
    
    
};
#endif /* NFAConverter_hpp */

