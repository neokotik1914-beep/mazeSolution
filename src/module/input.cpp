#include <iostream>
#include <fstream>

#include "module/input.h"

std::vector<std::vector<char>> input() 
{
  int n, m;
  std::ifstream inFile("C:/Users/user/code/mazeSolution/input.txt");
  if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input.txt" << std::endl;
    }
  inFile >> n >> m;
  printf("Size of array: %d %d\n", n, m);
  std::vector<std::vector<char>> maze(n, std::vector<char>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      
      inFile >> maze[i][j];
      
    }
  }
  printf("=================\n");
  return maze;
}