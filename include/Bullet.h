#ifndef BULLET_H
#define BULLET_H

#include "Sprite.h"

// Spel klass
using namespace MyGameEngine;

class Bullet : public MyGameEngine::Sprite
{
public:
    static Bullet *getInstance(std::string fileName, int x, int y);
    void tick(std::vector<Sprite *> comps, int loop);                       // Uppdatering av Bullet.
    void handleCollision(Sprite *other);

protected:
    Bullet(std::string fileName, int x, int y);                             // Konstruktor

private:
    int speed = 4;
    int size = 40;
};

#endif