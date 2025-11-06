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
                start.setPosition({(j * recSize), (i * recSize)});
                window->draw(start);
            }
            else if(myData.arr[i][j] == 9)
            {
                finish.setPosition({(j * recSize), (i * recSize)});
                window->draw(finish);
            }
            else if(myData.arr[i][j] == 0 or myData.arr[i][j] == 2)
            {
                grass.setPosition({(j * recSize), (i * recSize)});
                window->draw(grass);
            }
            else
            {
                path.setPosition({(j * recSize), ((i * recSize))});
                window->draw(path);
            }
        }
    }
}