//
//  State.cpp
//  DFAConverter
//
//  Created by Srushti Desai on 12/31/23.
//

#include "State.hpp"


State::State(int stateNumber): m_stateNumber(stateNumber)
{
    
}

State::~State()
{
    
}

void State::addTransition(char chInput, State *pState)
{
    if(pState)
    {
        m_transitions.insert(std::make_pair(chInput, pState));
    }
    
};
