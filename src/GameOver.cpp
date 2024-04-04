#include "GameOver.h"

// Spel klass.
using namespace MyGameEngine;
GameOver *GameOver::getInstance(int x, int y, int w, int h)
{
    return new GameOver(x, y, w, h);
}

GameOver::GameOver(int x, int y, int w, int h) : Label("Game Over", x, y, w, h) {
    
}
