#include <cstdlib>
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
int miniMax::minimax(State *state, int depth, int minMaxPlayer){

    state->get_legal_actions();
    for(auto x:state->legal_actions)
    {
        State temp=(*state);
        int xVal=temp.board.board[1-temp.player][x.first.first][x.first.second];
        swap(temp.board.board[temp.player][x.first.first][x.first.second],temp.board.board[temp.player][x.second.first][x.second.second]);
        temp.board.board[1-temp.player][x.second.first][x.second.second]=0;
        state->child.push_back(&temp);
    }

    if(!depth || state->child.empty())return  state->evaluate();
    if(minMaxPlayer)
    {
        int value=INT_MIN;
        for(auto a:state->child)value=max(value,minimax(a,depth-1,0));
        return value;
    }
    else
    {
        int value=INT_MAX;
        for(auto a:state->child)value=min(value,minimax(a,depth-1,1));
        return value;
    }
}
/*priority_queue<pair<int,Move>>Q;

    state->get_legal_actions();
    for(auto x:state->legal_actions)
    {
        int xVal=state->board.board[1-state->player][x.first.first][x.first.second];
        swap(state->board.board[state->player][x.first.first][x.first.second],
        state->board.board[state->player][x.second.first][x.second.second]);
        state->board.board[1-state->player][x.first.first][x.first.second]=0;

        Q.push(pair(state->evaluate(),x));

        swap(state->board.board[state->player][x.first.first][x.first.second],
        state->board.board[state->player][x.second.first][x.second.second]);
        state->board.board[1-state->player][x.first.first][x.first.second]=xVal;
    }
       
    auto actions = Q.top().second;
    return actions;*/