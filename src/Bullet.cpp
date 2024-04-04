#include "Bullet.h"
#include "EnemyTwo.h"

// Spel klass.
using namespace MyGameEngine;

Bullet::Bullet(std::string fileName, int x, int y) : Sprite(fileName, x, y, 40, 40)
{
}

Bullet *Bullet::getInstance(std::string fileName, int x, int y)
{
    return new Bullet(fileName, x, y);
}

void Bullet::tick(std::vector<Sprite *> comps, int loop)
{
    // Rörelse
    if (getRect().y < 0)
    {
        globalGameEngine.remove(this);
    }
    else
    {
        rect.y -= speed; // Hastigheten på bullet.
    }
}

void Bullet::handleCollision(Sprite *other)
{
    // Kollar om other är av typen EnemyTwo
    if (dynamic_cast<EnemyTwo *>(other))
    {
        // Ökar score.
        sys.increaseScore();

        // Tar bort fienden och bullet.
        globalGameEngine.remove(other);
        globalGameEngine.remove(this);
    }
}
