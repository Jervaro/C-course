#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

// Spel klass.
using namespace MyGameEngine;

class Player : public MyGameEngine::Sprite
{
public:
    static Player *getInstance(std::string fileName, int x, int y, int size, int speed);
    void tick(std::vector<Sprite *> comps, int loop);
    void handleAttack();
    bool canAttack();
    void handleMovement();
    void handleCollision(Sprite* other);
    void leftArrow();
    void leftArrowUp();
    void rightArrow();
    void rightArrowUp();
    void upArrow();
    void upArrowUp();
    void downArrow();
    void downArrowUp();
    void spaceDown();
    void spaceUp();

protected:
    Player(std::string fileName, int x, int y, int size, int speed); // Konstruktor

private:

    int attackCooldownMax = 20;
    int attackCooldown = attackCooldownMax;
    int speed = 1;

    bool isAlive = true;
    bool spaceIsDown = false;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
};

#endif