#include <stdio.h>

#include "module\inputOutput.hpp"

std::vector<std::vector<char>> input() {
    int n;
    scanf("%d", &n);
    printf("Size of array: %d\n", n);

    std::vector<std::vector<char>> maze(n, std::vector<char>(n));

    for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      
      char c = '\n';
      while (c == '\n')
      {
        scanf("%c", &c);
      }
      maze[i][j] = c;
      
    }
  }
    return maze;
}

void output(std::vector<std::vector<char>> maze, int n) {
    for(int i = 0; i < n; i++)
    {
        for (int element : maze[i]) {
            printf("%c ", element); // Print each integer element followed by a space
        }
        printf("\n");
    }
}
/*
3
3 3 3
2 2 2
1 1 0
*/