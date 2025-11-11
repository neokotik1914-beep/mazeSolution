#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <SFML\Graphics\RenderTarget.hpp>
#include <math.h>

#include "module/windowOutput.h"
#include "algorythm/maze.h"

#define _USE_MATH_DEFINES

const float sqrtTwo = 1.41421356;
float _xSize = 0, _ySize = 0, _recSizeX = 0, _recSizeY = 0;

using namespace sf;

void drawWall(RenderWindow *w, float x, float y, float sizeX, float sizeY)
{
    // Outside Box x, y, size
    
    // Inside Box x1 = x / , y
    float size1X = sizeX * 7 / 10;
    float size1Y = sizeY * 7 / 10;
    float offSetX = (sizeX - size1X) / 2;
    float offSetY = (sizeY - size1Y) / 2;

    sf::RectangleShape outside({sizeX, sizeY});
    outside.setFillColor(sf::Color(165, 115, 89));
    outside.setPosition({x, y});
    w->draw(outside);

    sf::RectangleShape inside({size1X, size1Y});
    inside.setFillColor(sf::Color(235, 172, 139));
    inside.setPosition({x + offSetX, y + offSetY});
    w->draw(inside);

    float tg = sizeY / sizeX;
    float shtukaSize = std::sqrt((sizeX - offSetX) * (sizeX - offSetX) + (sizeY - offSetY) * (sizeY - offSetY));
    sf::RectangleShape shtuka({shtukaSize, offSetY * sqrtTwo});
    shtuka.setFillColor(sf::Color(165, 115, 89));
    shtuka.setPosition({x + offSetX, y});
    shtuka.setRotation(sf::degrees(std::atan(tg) * 180.0 / M_PI));
    w->draw(shtuka);

    sf::RectangleShape shtuka1({shtukaSize, offSetY * sqrtTwo});
    shtuka1.setFillColor(sf::Color(165, 115, 89));
    shtuka1.setPosition({x, y + sizeY - offSetY});
    shtuka1.setRotation(sf::degrees(-std::atan(tg) * 180.0 / M_PI));
    w->draw(shtuka1);

}

inline bool isPathCell(int v)
{
    return (v == 3 || v == 9 || v == 10);
}

void drawPath(RenderWindow *w, int row, int col, float sizeX, float sizeY, data myData)
{
    float offSetX = sizeX / 5;
    float offSetY = sizeY / 5;

    sf::RectangleShape grass({sizeX, sizeY});
    grass.setFillColor(sf::Color(0, 255, 0));
    grass.setPosition({col * sizeX, row * sizeY});
    w->draw(grass);

    sf::RectangleShape pathX({sizeX - offSetX, sizeY - (2 * offSetY)});
    pathX.setFillColor(sf::Color(255, 255, 0));
    sf::RectangleShape pathY({sizeX - (2 * offSetX), sizeY - offSetY});
    pathY.setFillColor(sf::Color(255, 255, 0));

    float x = col * sizeX;
    float y = row * sizeY;

    if(row - 1 >= 0 && isPathCell(myData.arr[row - 1][col]))
    {
        pathY.setPosition({x + offSetX, y});
        w->draw(pathY);
    }

    if(col + 1 < myData.m && isPathCell(myData.arr[row][col + 1]))
    {
        pathX.setPosition({x + offSetX, y + offSetY});
        w->draw(pathX);
    }

    if(row + 1 < myData.n && isPathCell(myData.arr[row + 1][col]))
    {
        pathY.setPosition({x + offSetX, y + offSetY});
        w->draw(pathY);
    }

    if(col - 1 >= 0 && isPathCell(myData.arr[row][col - 1]))
    {
        pathX.setPosition({x, y + offSetY});
        w->draw(pathX);
    }
}


void drawPOI(RenderWindow *w, int y, int x, float sizeX, float sizeY, data myData)
{
    drawPath(w, y, x, sizeX, sizeY, myData);

    float offSetX = sizeX / 6;
    float offSetY = sizeY / 6;

    sf::RectangleShape house({sizeX - 2 * offSetX, sizeY - 2 * offSetY});
    house.setFillColor(sf::Color(160, 160, 160));
    house.setPosition({x * sizeX + offSetX, y * sizeY + offSetY});
    w->draw(house);
}

void winOut(data myData, RenderWindow *window)
{
    
    float recSizeX = (float)(window->getSize().x)/myData.m;
    float recSizeY = (float)(window->getSize().y)/myData.n;

    sf::RectangleShape path({recSizeX, recSizeY});
    path.setFillColor(sf::Color(255, 255, 0));

    sf::RectangleShape start({recSizeX, recSizeY});
    start.setFillColor(sf::Color(0, 0, 255));

    sf::RectangleShape finish({recSizeX, recSizeY});
    finish.setFillColor(sf::Color(245, 0, 255));

    sf::RectangleShape grass({recSizeX, recSizeY});
    grass.setFillColor(sf::Color(0, 255, 0));

    for(int i = 0; i < myData.n; i++)
    {
        for(int j = 0; j < myData.m; j++)
        {
            if(myData.arr[i][j] == 1)
            {
                drawWall(window, j * recSizeX, i * recSizeY, recSizeX, recSizeY);
            }
            else if(myData.arr[i][j] == 10)
            {
                drawPOI(window, i, j, recSizeX, recSizeY, myData);
            }
            else if(myData.arr[i][j] == 9)
            {
                finish.setPosition({(j * recSizeX), (i * recSizeY)});
                window->draw(finish);
            }
            else if(myData.arr[i][j] == 0)
            {
                grass.setPosition({(j * recSizeX), (i * recSizeY)});
                window->draw(grass);
            }
            else if (myData.arr[i][j] == 3)
            {
                drawPath(window, i, j, recSizeX, recSizeY, myData);
            }
        }
    }
    if(!myData.answer)
    {
        sf::Texture gorillaTexture;

        if(!gorillaTexture.loadFromFile("C:/Users/user/code/mazeSolution/image.png"))
        {
            
        }

        sf::Sprite gorilla(gorillaTexture);
        gorilla.setPosition({0.f, 0.f});

        // Масштабування на всю область вікна
        sf::Vector2u texSize = gorillaTexture.getSize();
        sf::Vector2u winSize = window->getSize();
        float scaleX = static_cast<float>(winSize.x) / texSize.x;
        float scaleY = static_cast<float>(winSize.y) / texSize.y;
        gorilla.setScale({scaleX, scaleY});

        window->draw(gorilla);
    }
}