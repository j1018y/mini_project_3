#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class alphaBeta{
public:
  static int alphabeta(State *state, int depth,int a,int b, int minMaxPlayer);//minMaxPlayer:0 for min, 1 for max
  static Move get_move(State *state, int depth);
};