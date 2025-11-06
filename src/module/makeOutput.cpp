#include <stdio.h>

#include "module/makeOutput.h"
#include "module/consts.h"

void makeOutput(data *myData) {
    printf("Making Output\n");
    int stack[3][MAX_STACK_LENGTH];
    int stackLength = 1;
    stack[0][0] = myData->start.x;
    stack[1][0] = myData->start.y;
    stack[2][0] = -1;
    for(int i = 0; i < stackLength; i++)
    {
        int x = stack[0][i];
        int y = stack[1][i];
        int prev = stack[2][i];
        if(x == myData->finish.x and y == myData->finish.y)
        {
            myData->arr[x][y] = 9;
            return;
        }
        else if (x - 1 >= 0 and (myData->arr[x - 1][y] == 3))
        {
            stack[0][stackLength] = x - 1;
            stack[1][stackLength] = y;
            stack[2][stackLength] = 3;
            if(prev == -1)
            {
                myData->arr[x][y] = 10;
            }
            
            else if(prev == 4) {myData->arr[x][y] = 14;}
            else if(prev == 2) {myData->arr[x][y] = 16;}
            else if(prev == 3) {myData->arr[x][y] = 15;}
            stackLength++;
        }
        else if (x + 1 < myData->n and (myData->arr[x + 1][y] == 3))
        {
            stack[0][stackLength] = x + 1;
            stack[1][stackLength] = y;
            stack[2][stackLength] = 1;
            if(prev == -1)
            {
                myData->arr[x][y] = 10;
            }
            else if(prev == 1) {myData->arr[x][y] = 11;}
            else if(prev == 2) {myData->arr[x][y] = 18;}
            else if(prev == 4) {myData->arr[x][y] = 12;}
            stackLength++;
        }
        else if (y - 1 >= 0 and (myData->arr[x][y - 1] == 3))
        {
            stack[0][stackLength] = x;
            stack[1][stackLength] = y - 1;
            stack[2][stackLength] = 2;
            if(prev == -1)
            {
                myData->arr[x][y] = 10;
            }
            else if(prev == 1) {myData->arr[x][y] = 18;}
            else if(prev == 2) {myData->arr[x][y] = 17;}
            else if(prev == 3) {myData->arr[x][y] = 16;}
            stackLength++;
        }
        else if (y + 1 < myData->m and (myData->arr[x][y + 1] == 3))
        {
            stack[0][stackLength] = x;
            stack[1][stackLength] = y + 1;
            stack[2][stackLength] = 4;
            if(prev == -1)
            {
                myData->arr[x][y] = 10;
            }
            
            else if(prev == 1) {myData->arr[x][y] = 12;}
            else if(prev == 4) {myData->arr[x][y] = 13;}
            else if(prev == 3) {myData->arr[x][y] = 14;}
            stackLength++;
        }

        if(prev == -1)
        {
            myData->arr[x][y] = 10;
        }

    }
}