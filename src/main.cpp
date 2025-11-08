#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "algorythm/maze.h"
#include "module/input.h"
#include "algorythm/mazeSolver.h"
#include "module/output.h"
#include "module/consts.h"
#include "module/makeOutput.h"
#include "module/windowOutput.h"
#include "module/mouseWork.h"

int main()
{
    printf("%d\n", MAX_STACK_LENGTH);

    std::vector<std::vector<char>> maze = input();
    data myData(maze.size(), maze[0].size(), -1);
    myData.n = maze.size();
    myData.m = maze[0].size();
    convert(&myData, maze);

    bool answer = solve(&myData);

    if(answer)
    {
        printf("Y\n");
    }
    else{
        printf("N\n");
    }
    //makeOutput(&myData);

    sf::RenderWindow window(sf::VideoMode({800, 800}), "answer");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(10);

    window.setPosition({10, 50});

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
                mouseWork(&myData, &window);
                e = NULL;
                output(myData);
            }
            
        }
        window.clear(sf::Color::White);
        winOut(myData, &window);

        window.display();


    }

    output(myData);
}