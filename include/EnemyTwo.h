#ifndef ENEMYTWO_H
#define ENEMYTWO_H

#include "Sprite.h"

// Spel klass
using namespace MyGameEngine;

class EnemyTwo : public Sprite
{
public:
    static EnemyTwo *getInstance(std::string fileName, int x, int y, int size, int speed);
    void tick(std::vector<Sprite *> comps, int loop);

protected:
    EnemyTwo(std::string fileName, int x, int y, int size, int speed); // Konstruktor

private:
    int speed = 1;
};

#endif