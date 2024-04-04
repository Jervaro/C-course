#include "ScoreLabel.h"

using namespace MyGameEngine;

// Spel klass.
ScoreLabel *ScoreLabel::getInstance(int x, int y, int w, int h)
{
    return new ScoreLabel(x, y, w, h);
}

ScoreLabel::ScoreLabel(int x, int y, int w, int h) : Label(std::to_string(sys.get_Score()), x, y, w, h)
{
}

void ScoreLabel::tick(std::vector<Sprite *> comps, int loop)
{
    setText(std::to_string(sys.get_Score()));
}