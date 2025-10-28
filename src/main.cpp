#include "module\inputOutput.hpp"

int main()
{
    std::vector<std::vector<char>> maze = input();
    output(maze, maze[0].size());
}