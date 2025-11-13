#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "algorythm/maze.h"
#include "module/input.h"
#include "algorythm/mazeSolver.h"
#include "module/output.h"
#include "module/consts.h"
#include "module/makeOutput.h"
#include "module/windowOutput.h"
#include "module/mouseWork.h"
#include "module/sunMove.h"

int main()
{
    //printf("%d\n", MAX_STACK_LENGTH);

    std::vector<std::vector<char>> maze = input();
    data myData(maze.size(), maze[0].size(), -1);
    myData.n = maze.size();
    myData.m = maze[0].size();
    convert(&myData, maze);

    solve(&myData);

    if(myData.answer)
    {
        //printf("Y\n");
    }
    else{
        //printf("N\n");
    }
    //makeOutput(&myData);

    sf::RenderWindow window(sf::VideoMode({800, 800}), "answer");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(true);

    window.setPosition({10, 50});
    sf::Clock clock;

    myData.sun.xf = 0;
    myData.sun.yf = 0;

    int sizeX = window.getSize().x;
    int sizeY = window.getSize().y;
    float T = 10;
    float rad = sqrt(sizeX * sizeX + sizeY * sizeY) / 2;

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* e = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (e->button == sf::Mouse::Button::Left)
                {
                    myData.currentTime = clock.getElapsedTime().asMilliseconds();
                    mouseWork(&myData, &window);
                    e = NULL;
                }
            }
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
                sizeX = window.getSize().x;
                sizeY = window.getSize().y;
                rad = sqrt(sizeX * sizeX + sizeY * sizeY) / 2;
            }
            
        }
        myData.currentTime = clock.getElapsedTime().asMilliseconds();
        sunMove(rad, T, &myData, sizeX / 2, sizeY / 2);

        window.clear(sf::Color::White);

        winOut(&myData, &window);

        window.display();

        
    }

    output(myData);
}