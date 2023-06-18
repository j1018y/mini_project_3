#include <cstdlib>
#include <climits>
#include<iostream>
#include <fstream>
//#include <queue>

#include "../state/state.hpp"
#include "./miniMax.hpp"
using namespace std;


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move miniMax::get_move(State *state){
    state->THE_PLAYER=state->player;
    state->get_legal_actions();
    int choice=INT_MIN;
    Move ans;
    state->THE_PLAYER=state->player;
    for(auto x:state->legal_actions)
    {
        int num=minimax(state->next_state(x),4,0);
        if(choice<num)
        {
            choice=num;
            ans=x;
        }
    }
    return ans;
}
int miniMax::minimax(State *state, int depth, int minMaxPlayer){

    if(!depth)return state->evaluate();
    state->get_legal_actions();
    //std::cout<<"mini max depth"<<depth<<endl;

    if(state->legal_actions.empty())return state->evaluate();
    int value=INT_MIN;
    if(minMaxPlayer)
    {
        int value=INT_MIN;
        for(auto a:state->legal_actions)
        {
            value=max(value,minimax(state->next_state(a),depth-1,0));
        }
        return value;
    }
    else
    {
        int value=INT_MAX;
        for(auto a:state->legal_actions)
        {
            value=min(value,minimax(state->next_state(a),depth-1,1));
        }
        return value;
    }
}
