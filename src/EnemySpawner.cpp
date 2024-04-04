#include "EnemySpawner.h"
#include "EnemyTwo.h"

// Spel klass.
using namespace MyGameEngine;

EnemySpawner::EnemySpawner(std::string fileName, int x, int y, int size, int speed, int speedSpawnedEnemy, int attackCooldownMax) : Sprite(fileName, x, y, size, size)
{
    this->fileName = fileName;
    this->speed = speed;
    this->speedSpawnedEnemy = speedSpawnedEnemy;
    this->attackCooldownMax = attackCooldownMax;
    this->attackCooldown = attackCooldownMax;
}

EnemySpawner *EnemySpawner::getInstance(std::string fileName, int x, int y, int size, int speed, int speedSpawnedEnemy, int attackCooldownMax)
{
    return new EnemySpawner(fileName, x, y, size, speed, speedSpawnedEnemy, attackCooldownMax);
}


void EnemySpawner::tick(std::vector<Sprite *> comps, int loop)
{
    // Åker till höger, byter håll när den nuddar kanten o fortsätter så.
    rect.x += speed;
    if (getRect().x < 0)
    {
        speed *= -1;
    }
    if (getRect().x > (sys.get_Width() - getRect().w))
    {
        speed *= -1;
    }

    if (attackCooldown >= attackCooldownMax)
    {
        attackCooldown = 0;
        perform();
    }

    if(attackCooldown < attackCooldownMax){
        attackCooldown++;
    }
}

void EnemySpawner::perform()
{
    // Skapar en ny fiende.
    EnemyTwo *enemy = EnemyTwo::getInstance(fileName, getRect().x, getRect().y, getRect().w, speedSpawnedEnemy);
    // Spawnar den nya fienden.
    globalGameEngine.add(enemy);
}
