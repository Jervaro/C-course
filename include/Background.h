#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Sprite.h"

// Spel klass
using namespace MyGameEngine;

class Background : public MyGameEngine::Sprite
{
public:
    static Background *getInstance(std::string fileName);

protected:
    Background(std::string fileName);

private:
};
#endif