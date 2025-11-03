#include <stdio.h>

#include "algorythm\maze.h"
#include "module\input.h"
#include "algorythm\mazeSolver.h"
#include "module\output.h"
#include "module\consts.h"
#include "module\makeOutput.h"

int main()
{
    printf("%d\n", MAX_STACK_LENGTH);

    std::vector<std::vector<char>> maze = input();
    data myData(maze.size(), maze[0].size(), -1);
    myData.n = maze.size();
    myData.m = maze[0].size();
    convert(&myData, maze);

    bool answer = solve(&myData);

    if(answer)
    {
        printf("Y\n");
    }
    else{
        printf("N\n");
    }
    makeOutput(&myData);
    output(myData);
}