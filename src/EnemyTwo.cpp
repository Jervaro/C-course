#include "EnemyTwo.h"

// Spel klass.
using namespace MyGameEngine;

EnemyTwo::EnemyTwo(std::string fileName, int x, int y, int size, int speed) : Sprite(fileName, x, y, size, size)
{
    this->speed = speed;
};

EnemyTwo *EnemyTwo::getInstance(std::string fileName, int x, int y, int size, int speed)
{
    return new EnemyTwo(fileName, x, y, size, speed);
}

void EnemyTwo::tick(std::vector<Sprite *> comps, int loop)
{
    // Åker nedåt.
    rect.y += speed;

    // Ifall this är utanför fönstret så tas den bort.
    if (getRect().y > sys.get_Height() + getSize())
    {
        globalGameEngine.remove(this);
    }
}
