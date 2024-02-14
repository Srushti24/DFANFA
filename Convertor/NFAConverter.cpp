//
//  NFAConverter.cpp
//  DFAConverter
//
//  Created by Srushti Desai on 1/6/24.
//

#include "NFAConverter.hpp"
#include <map>

using namespace std;

NFAConverter::NFAConverter():
m_stateNumber(0)
{
    
}

NFAConverter::~NFAConverter()
{
    
}

void NFAConverter::convertExpression(Regex& tree)
{
    for(int i =0; i<tree.children.size(); i++)
    {
        convertExpression(tree.children[i]);
    }
    if(tree.type == Regex::ALPHABET)
    {
        push(tree.alphabet);
    }
    else if(tree.type == Regex::KSTAR)
    {
        Star();
    }
    else if (tree.type == Regex::CONCAT)
    {
        Compact();
    }
    else{
        Union();
    }
}

void NFAConverter::push(char& input) // A
{
    State state1(m_stateNumber);
    m_stateNumber++;
    State state2(m_stateNumber);
    state1.m_transitions.insert(std::make_pair(input, &state2));
    // [ forced to pass the above state as pointer ]
    std::deque<State*> stateTable;
    stateTable.push_back(&state1);
    stateTable.push_back(&state2);
    m_stateStack.push(stateTable);
}

void NFAConverter::Union() // A|B
{
    std::deque<State*> s1 = m_stateStack.top();
    m_stateStack.pop();
    std::deque<State*> s2 = m_stateStack.top();
    m_stateStack.pop();
    
    State start(m_stateNumber++);
    State end(m_stateNumber++);
    start.m_transitions.insert(std::make_pair('0', s1[0]));
    start.m_transitions.insert(std::make_pair('0', s2[0]));
    s1[s1.size()-1]->addTransition('0', &end);
    s2[s2.size()-1]->addTransition('0', &end);
    s1.push_back(&end);
    s2.push_front(&start);
    s2.insert(s2.end(), s1.begin(), s1.end());
    m_stateStack.push(s2);
}

void NFAConverter::Compact() //AB
{
    std::deque<State*> s1 = m_stateStack.top();
    m_stateStack.pop();
    std::deque<State*> s2 = m_stateStack.top();
    m_stateStack.pop();
    s2[s2.size()-1]->addTransition('0', s1[0]); //this
    s2.insert(s2.end(), s1.begin(), s1.end());
    m_stateStack.push(s2);
}

void NFAConverter::Star() //A*
{
    std::deque<State*> s1 = m_stateStack.top();
    m_stateStack.pop();
    State start(m_stateNumber++);
    State end(m_stateNumber++);
    start.addTransition(0,&end);
    start.m_transitions.insert(std::make_pair('0', s1[0]));
    s1[s1.size()-1]->addTransition('0', &end); //this
    s1[s1.size()-1]->addTransition('0', s1[0]); //this
    s1.push_front(&start);
    s1.push_back(&end);
    m_stateStack.push(s1);
}

 

