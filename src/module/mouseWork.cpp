#include <SFML/Graphics.hpp>
#include "module/mouseWork.h"
#include "algorythm/mazeSolver.h"

using namespace sf;

void mouseWork(data *myData, sf::RenderWindow *window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);

    float recSizeX = window->getSize().x / myData->n;
    float recSizeY = window->getSize().y / myData->m;

    int x = localPosition.x / recSizeX;
    int y = localPosition.y / recSizeX;

    if (x < 0 || x >= myData->n || y < 0 || y >= myData->m) 
        return;

    if(myData->arr[y][x] == 0)
        myData->arr[y][x] = 1;
    else if(myData->arr[y][x] == 1)
        myData->arr[y][x] = 0;
    else if(myData->arr[y][x] == 3)
        myData->arr[y][x] = 1;

    for(int i = 0; i < myData->n; i++)
    {
        for(int j = 0; j < myData->m; j++)
        {
            if(myData->arr[i][j] == 3)
            {
                myData->arr[i][j] = 0;
            }
        }
    }
    bool answer = solve(myData);
}