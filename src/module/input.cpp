#include <stdio.h>

#include "module\input.h"

std::vector<std::vector<char>> input() {
  int n, m;
    scanf("%d%d", &n, &m);
    printf("Size of array: %d %d\n", n, m);

    std::vector<std::vector<char>> maze(n, std::vector<char>(m));

    for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      
      char c = '\n';
      while (c == '\n')
      {
        scanf("%c", &c);
      }
      maze[i][j] = c;
      
    }
  }
  printf("=================\n");
  return maze;
}