#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "algorythm/maze.h"
#include "module/consts.h"

void walk(data *myData, int stack[][MAX_STACK_LENGTH], int i, int& stackLength, bool& boolGlobal);

void solve(data *myData);

#endif