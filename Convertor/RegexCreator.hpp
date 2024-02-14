//
//  RegexTree.hpp
//  DFAConverter
//
//  Created by Srushti Desai on 1/7/24.
//

#ifndef RegexTree_hpp
#define RegexTree_hpp

#include <stdio.h>
#include<iostream>
#include<stack>
#include"Regex.hpp"

class RegexCreator
{
public:
    RegexCreator(std::string expression);
    ~RegexCreator();
    Regex createTree();
private:
    std::string m_expression;
    std::stack<char> operand_stack;
    std::stack<Regex> regex_stack;
    Regex::Type getType(char operation);
    int priority(char& operand);
    void popStack();
    void display(Regex r);
};
#endif /* RegexTree_hpp */
