//
//  State.hpp
//  DFAConverter
//
//  Created by Srushti Desai on 12/31/23.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include<map>
#include<set>
#include <iostream>


class State
{
    
public:
    State(int stateNumber);
    ~State();
    int m_stateNumber;
    std::multimap<char, State*> m_transitions;
    std::multimap<char, char> temp;
    std::set<State> m_origin;
    void addTransition(char chInput, State *pState);
    
};
#endif /* State_hpp */
