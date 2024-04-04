#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "EnemyTwo.h"
#include "Sprite.h"

// Spel klass
using namespace MyGameEngine;

class EnemySpawner : public Sprite
{
public:
    static EnemySpawner *getInstance(std::string fileName, int x, int y, int size, int speed, int speedSpawnedEnemy, int attackCooldownMax);
    void tick(std::vector<Sprite *> comps, int loop);
    // void draw() const {};
    void perform();

protected:
    EnemySpawner(std::string fileName, int x, int y, int size, int speed, int speedSpawnedEnemy, int attackCooldownMax);

private:
    std::string fileName;
    int attackCooldownMax;
    int attackCooldown;
    int speed;
    int speedSpawnedEnemy;
};

#endif