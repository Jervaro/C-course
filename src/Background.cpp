#include "Background.h"

// Spel klass
using namespace MyGameEngine;

Background::Background(std::string fileName) : Sprite(fileName, 0, 0, sys.get_Width(), sys.get_Height())
{
}

Background *Background::getInstance(std::string fileName)
{
    return new Background(fileName);
}
