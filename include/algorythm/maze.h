#ifndef MAZE_H
#define MAZE_H

#include <vector>

struct coords{
    int x;
    int y;
};

struct data{
    coords start;
    coords finish;
    int n;
    int m;
    std::vector<std::vector<int>> arr;

    data(int n, int m, int defaultValue) 
        : arr(n, std::vector<int>(m, defaultValue)) {}
};

void convert(data *myData, std::vector<std::vector<char>> maze);

#endif