#include <SFML/Graphics.hpp>
#include <cmath>
#include "module/mouseWork.h"
#include "algorythm/mazeSolver.h"
#include "module/getCoord.h"

using namespace sf;

void mouseWork(data *myData, sf::RenderWindow *window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(localPosition);

    float recSizeX = (float)(window->getSize().x) / myData->m;
    float recSizeY = (float)(window->getSize().y) / myData->n;

    printf("%f %f, %f %f ", worldPos.x, worldPos.y, recSizeX, recSizeY);

    int x = getCoord(recSizeX, myData->m, worldPos.x);
    printf("%d ", x);
    int y = getCoord(recSizeY, myData->n, worldPos.y);
    printf("%d\n", y);

    

    if (x < 0 || x >= myData->m || y < 0 || y >= myData->n) 
        return;

    if(myData->arr[y][x] == 0)
    {
        myData->arr[y][x] = 1;
        return;
    }
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
    solve(myData);
}