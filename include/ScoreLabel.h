#ifndef SCORELABEL_H
#define SCORELABEL_H

#include "Label.h"

// Spel klass
using namespace MyGameEngine;

class ScoreLabel : public Label
{
public:
    static ScoreLabel *getInstance(int x, int y, int w, int h);
    void tick(std::vector<Sprite *> comps, int loop);

protected:
    ScoreLabel(int x, int y, int w, int h);
};

#endif