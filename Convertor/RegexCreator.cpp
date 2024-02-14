//
//  RegexTree.cpp
//  DFAConverter
//
//  Created by Srushti Desai on 1/7/24.
//

#include "RegexCreator.hpp"


RegexCreator::RegexCreator(std::string expression):m_expression(expression)
{
}

RegexCreator::~RegexCreator()
{
    
}

Regex RegexCreator::createTree()
{
    for(int i=0;i <m_expression.size(); i++)
    {
      //  std::cout << "current char is " << m_expression[i] <<"\n";
        if(m_expression[i] != '*' && m_expression[i] != '(' && m_expression[i] != ')' && m_expression[i] != '|'  && m_expression[i] != '%')
        {
            
            Regex r1;
            r1.type = Regex::ALPHABET;
            r1.alphabet= m_expression[i];
            regex_stack.push(r1);
          //  display(r1);
            
            
        }
        else if(m_expression[i] == '(' || operand_stack.empty())
        {
            operand_stack.push(m_expression[i]);
        }
        else if(m_expression[i] == ')')
        {
            //std::cout << "inside )" << "\n";
            //std::cout << operand_stack.top() << "\n";
            while(!operand_stack.empty() && operand_stack.top()!= '(')
            {
               // std::cout << "popping" << "\n";
                popStack();
            }
            operand_stack.pop();
        }
        else
        {
            while(!operand_stack.empty() && priority(operand_stack.top()) < priority(m_expression[i]) )
            {
                popStack();
            }
            operand_stack.push(m_expression[i]);
        }
    }
    
    while(!operand_stack.empty())
    {
        popStack();
    }
    std::cout << "Stack size is " << regex_stack.size() << "\n";
    Regex r1 =regex_stack.top();
    display(r1);
    return r1;
   // regex_stack.pop();
    
}


Regex::Type RegexCreator::getType(char operation)
{
    if(operation == '*')
    {
        return Regex::KSTAR;
    }
    else if(operation == '%')
    {
        return Regex::CONCAT;
    }
    else
    {
        return Regex::UNION;
    }
}

int RegexCreator::priority(char& operand)
{
    switch(operand)
    {
        case '*':
            return 1;
        case '%':
            return 2;
        default:
            return 3;
    }
}

void RegexCreator:: popStack()
{
    Regex r1 = regex_stack.top();
    regex_stack.pop();
    char operation = operand_stack.top();
   // std::cout << "operation is " << operation << "\n";
    operand_stack.pop();
    Regex r3;
    r3.type = getType(operation);
    r3.children.push_back(r1);
    if(operation != '*')
    {
        Regex r2 = regex_stack.top();
        r3.children.push_back(r2);
        regex_stack.pop();
    }
    regex_stack.push(r3);
 //   std::cout << "from pop stack " << "\n";
   // display(r3);
}

void RegexCreator::display(Regex r)
{
    std::cout << "Type is "<<r.type << "\n";
    std::cout << "alphabet  is "<<r.alphabet << "\n";
    std::cout << "children list size is " << r.children.size() << "\n";
    for(size_t i =0; i<r.children.size(); i++)
    {
        std::cout << r.children[i].alphabet ;
    }
    for(size_t i =0; i<r.children.size(); i++)
    {
        display(r.children[i]);
    }
    
}
