#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
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
    bool answer;
    std::vector<std::vector<int>> arr;

    data(int n, int m, int defaultValue) 
        : arr(n, std::vector<int>(m, defaultValue)) {}
};

void convert(data *myData, std::vector<std::vector<char>> maze);

#endif