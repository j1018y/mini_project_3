#include <cstdlib>
#include <climits>
//#include <queue>

#include "../state/state.hpp"
#include "./alphabeta.hpp"
using namespace std;

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move alphaBeta::get_move(State *state){
    state->THE_PLAYER=state->player;
    state->get_legal_actions();
    int choice=INT_MIN;
    Move ans;
    for(auto x:state->legal_actions)
    {
        int num=alphabeta(state->next_state(x),6,INT_MIN,INT_MAX,0);//opponent choosing the smallest value
        if(choice<num)//player choosing
        {
            choice=num;
            ans=x;
        }
    }
    return ans;
}
int alphaBeta::alphabeta(State *state, int depth, int a, int b, int minMaxPlayer){

    if(!depth)return state->evaluate();
    state->get_legal_actions();

    if(state->legal_actions.empty())return  state->evaluate();
    if(minMaxPlayer)
    {
        int value=INT_MIN;
        for(auto h:state->legal_actions)
        {
            value=max(value,alphabeta(state->next_state(h),depth-1,a,b,0));
            a=max(a,value);
            if(a>=b)break;
        }
        return value;
    }
    else
    {
        int value=INT_MAX;
        for(auto h:state->legal_actions)
        {
            value=min(value,alphabeta(state->next_state(h),depth-1,a,b,1));
            b=min(b,value);
            if(b<=a)break;
        }
        return value;
    }
}

        /*int xVal=temp.board.board[1-temp.player][x.first.first][x.first.second];
        swap(temp.board.board[temp.player][x.first.first][x.first.second],temp.board.board[temp.player][x.second.first][x.second.second]);
        temp.board.board[1-temp.player][x.second.first][x.second.second]=0;*/
