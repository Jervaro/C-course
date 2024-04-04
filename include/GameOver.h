#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Label.h"

// Spel klass
using namespace MyGameEngine;

class GameOver : public Label
{
public:
    static GameOver *getInstance(int x, int y, int w, int h);

protected:
    GameOver(int x, int y, int w, int h);

private:
};

#endif