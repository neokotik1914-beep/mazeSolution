#include <stdio.h>

#include "algorythm\mazeSolver.h"
#include "module\consts.h"

void walk(data *myData, int stack[][MAX_STACK_LENGTH], int index, int& stackLength, bool& boolGlobal)
{
    int x = stack[0][index];
    int y = stack[1][index];
    myData->arr[x][y] = 2;
    if(x == myData->finish.x and y == myData->finish.y)
    {
      boolGlobal = 1;
      return;
    }
    if (x - 1 >= 0 and (myData->arr[x - 1][y] == 0))
    {
      stack[0][stackLength] = x - 1;
      stack[1][stackLength] = y;
      stack[2][stackLength] = stack[2][index] + 1;
      stack[3][stackLength] = index;
      stackLength++;
    }
    if (x + 1 < myData->n and (myData->arr[x + 1][y] == 0))
    {
      stack[0][stackLength] = x + 1;
      stack[1][stackLength] = y;
      stack[2][stackLength] = stack[2][index] + 1;
      stack[3][stackLength] = index;
      stackLength++;
    }
    if (y - 1 >= 0 and (myData->arr[x][y - 1] == 0))
    {
      stack[0][stackLength] = x;
      stack[1][stackLength] = y - 1;
      stack[2][stackLength] = stack[2][index] + 1;
      stack[3][stackLength] = index;
      stackLength++;
    }
    if (y + 1 < myData->m and (myData->arr[x][y + 1] == 0))
    {
      stack[0][stackLength] = x;
      stack[1][stackLength] = y + 1;
      stack[2][stackLength] = stack[2][index] + 1;
      stack[3][stackLength] = index;
      stackLength++;
    }
}

bool solve(data *myData)
{
  printf("Solving...\n");
  bool boolGlobal = 0;
  int stack[4][MAX_STACK_LENGTH];
  int stackLength = 1;
  stack[0][0] = myData->start.x;
  stack[1][0] = myData->start.y;
  stack[2][0] = 0;
  stack[3][0] = -1;
  int index = 0;
  for (int i = 0; i < stackLength and boolGlobal == 0; i++)
  {
    walk(myData, stack, i, stackLength, boolGlobal);
    int a = MAX_STACK_LENGTH;
    if(stackLength >= a - 500)
    {
      printf("ACHTUNG!!\n");
    }
    if(boolGlobal)
    {
      index = i;
    }
  }
  printf("Walked %d\n", stackLength);
  if(boolGlobal)
  {
  while (true)
  {
    int x = stack[0][index];
    int y = stack[1][index];
    if (x == myData->start.x and y == myData->start.y)
  {
        break;
      }
      myData->arr[x][y] = 3;
      index = stack[3][index];

     }
    }
    printf("Solved\n");
    return boolGlobal;
}