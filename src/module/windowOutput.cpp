#include <SFML/Graphics.hpp>

#include "module/windowOutput.h"
#include "algorythm/maze.h"

const float sqrtTwo = 1.41421356;

using namespace sf;

void drawWall(RenderWindow *w, float x, float y, float size)
{
    // Outside Box x, y, size
    
    // Inside Box x1 = x / , y
    float size1 = size * 7 / 10;
    float offSet = (size - size1) / 2;

    sf::RectangleShape outside({size, size});
    outside.setFillColor(sf::Color(165, 115, 89));
    outside.setPosition({x, y});
    w->draw(outside);

    sf::RectangleShape inside({size1, size1});
    inside.setFillColor(sf::Color(235, 172, 139));
    inside.setPosition({x + offSet, y + offSet});
    w->draw(inside);

    sf::RectangleShape shtuka({(size - offSet) * sqrtTwo, offSet * sqrtTwo});
    shtuka.setFillColor(sf::Color(165, 115, 89));
    shtuka.setPosition({x + offSet, y});
    shtuka.setRotation(sf::degrees(45));
    w->draw(shtuka);

    sf::RectangleShape shtuka1({(size - offSet) * sqrtTwo, offSet * sqrtTwo});
    shtuka1.setFillColor(sf::Color(165, 115, 89));
    shtuka1.setPosition({x, y + size - offSet});
    shtuka1.setRotation(sf::degrees(-45));
    w->draw(shtuka1);

}

inline bool isPathCell(int v)
{
    return (v == 3 || v == 9 || v == 10);
}

void drawPath(RenderWindow *w, int row, int col, float size, data myData)
{
    float offSet = size / 5;

    sf::RectangleShape grass({size, size});
    grass.setFillColor(sf::Color(0, 255, 0));
    grass.setPosition({col * size, row * size});
    w->draw(grass);

    sf::RectangleShape path({size - offSet, size - 2 * offSet});
    path.setFillColor(sf::Color(255, 255, 0));

    float x = col * size;
    float y = row * size;

    if(row - 1 >= 0 && isPathCell(myData.arr[row - 1][col]))
    {
        path.setPosition({x + size - offSet, y});
        path.setRotation(sf::degrees(90));
        w->draw(path);
    }

    if(col + 1 < myData.m && isPathCell(myData.arr[row][col + 1]))
    {
        path.setPosition({x + size, y + size - offSet});
        path.setRotation(sf::degrees(180));
        w->draw(path);
    }

    if(row + 1 < myData.n && isPathCell(myData.arr[row + 1][col]))
    {
        path.setPosition({x + offSet, y + size});
        path.setRotation(sf::degrees(-90));
        w->draw(path);
    }

    if(col - 1 >= 0 && isPathCell(myData.arr[row][col - 1]))
    {
        path.setPosition({x, y + offSet});
        path.setRotation(sf::degrees(0));
        w->draw(path);
    }
}


void drawPOI(RenderWindow *w, int x, int y, float size, data myData)
{
    drawPath(w, x, y, size, myData);

    float offSet = size / 6;

    sf::RectangleShape house({size - 2 * offSet, size - 2 * offSet});
    house.setFillColor(sf::Color(160, 160, 160));
    house.setPosition({y * size + offSet, x * size + offSet});
    w->draw(house);
}

void winOut(data myData, RenderWindow *window)
{
    float recSize = window->getSize().x/myData.n;

    sf::RectangleShape path({recSize, recSize});
    path.setFillColor(sf::Color(255, 255, 0));

    sf::RectangleShape start({recSize, recSize});
    start.setFillColor(sf::Color(0, 0, 255));

    sf::RectangleShape finish({recSize, recSize});
    finish.setFillColor(sf::Color(245, 0, 255));

    sf::RectangleShape grass({recSize, recSize});
    grass.setFillColor(sf::Color(0, 255, 0));

    for(int i = 0; i < myData.n; i++)
    {
        for(int j = 0; j < myData.m; j++)
        {
            if(myData.arr[i][j] == 1)
            {
                drawWall(window, j * recSize, i * recSize, recSize);
            }
            else if(myData.arr[i][j] == 10)
            {
                drawPOI(window, i, j, recSize, myData);
            }
            else if(myData.arr[i][j] == 9)
            {
                finish.setPosition({(j * recSize), (i * recSize)});
                window->draw(finish);
            }
            else if(myData.arr[i][j] == 0)
            {
                grass.setPosition({(j * recSize), (i * recSize)});
                window->draw(grass);
            }
            else if (myData.arr[i][j] == 3)
            {
                drawPath(window, i, j, recSize, myData);
            }
        }
    }
}