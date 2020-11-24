// Space Invaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Definitions.h"
#include "Game.h"

int main()
{
    Game* game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT, "SPACE INVADERS");

    game->Run();

    return EXIT_SUCCESS;
}
