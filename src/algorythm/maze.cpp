#include <stdio.h>

#include "algorythm/maze.h"

void convert(data *myData, std::vector<std::vector<char>> maze)
{
    //printf("Converting...\n");
    for(int i = 0; i < myData->n; i++)
    {
        myData->arr[i]=std::vector<int>(myData->m, -1);
        for(int j = 0; j < myData->m; j++)
        {
            if(maze[i][j] == '.')
            {
                myData->arr[i][j] = 0;

            }
            if(maze[i][j] == 'O')
            {
                myData->arr[i][j] = 1;
            }
            if(maze[i][j] == '@')
            {
                myData->arr[i][j] = 0;
                myData->start.x = i;
                myData->start.y = j; 
            }
            if(maze[i][j] == 'X')
            {
                myData->arr[i][j] = 0;
                myData->finish.x = i;
                myData->finish.y = j; 
            }
        }
    }
    //printf("Converted\n");
    return;
}