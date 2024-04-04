#include "Player.h"
#include "Bullet.h"
#include "EnemyTwo.h"
#include "GameOver.h"

using namespace MyGameEngine;

// Spel klass.
Player::Player(std::string fileName, int x, int y, int size, int speed) : Sprite(fileName, x, y, size, size)
{
    this->speed = speed; // Hastigheten på player
};

Player *Player::getInstance(std::string fileName, int x, int y, int size, int speed)
{
    return new Player(fileName, x, y, size, speed);
}

void Player::tick(std::vector<Sprite *> comps, int loop)
{
    // Skjuta
    handleAttack();

    // Rörelse
    handleMovement();
}

void Player::handleAttack()
{
    // Attack om parametrar är true.
    if (isAlive && spaceIsDown && canAttack())
    {
        Bullet *b = Bullet::getInstance("images/fireball.png", getRect().x + 30, getRect().y);
        globalGameEngine.add(b);
    }

    // Ökar cooldown varje tick för att till slut kunna skjuta.
    if (attackCooldown < attackCooldownMax)
    {
        attackCooldown += 1;
    }
}

bool Player::canAttack()
{
    if (attackCooldown >= attackCooldownMax)
    {
        attackCooldown = 0;
        return true;
    }
    return false;
}

void Player::handleMovement()
{
    if (left && isAlive)
    {
        rect.x -= speed;
    }
    if (right && isAlive)
    {
        rect.x += speed;
    }
    if (up && isAlive)
    {
        rect.y -= speed;
    }
    if (down && isAlive)
    {
        rect.y += speed;
    }
}

void Player::leftArrow()
{
    left = true;
}
void Player::leftArrowUp()
{
    left = false;
}

void Player::rightArrow()
{
    right = true;
}

void Player::rightArrowUp()
{
    right = false;
}

void Player::upArrow()
{
    up = true;
}

void Player::upArrowUp()
{
    up = false;
}

void Player::downArrow()
{
    down = true;
}

void Player::downArrowUp()
{
    down = false;
}

void Player::spaceDown()
{
    spaceIsDown = true;
}

void Player::spaceUp()
{
    spaceIsDown = false;
}

void Player::handleCollision(Sprite *other)
{
    // Kollar om other är av typen EnemyTwo
    if (dynamic_cast<EnemyTwo*>(other))
    {
        // Skapar och lägger till GameOver objekt.
        GameOver *gameOver = GameOver::getInstance((sys.get_Width() / 2) - 200, (sys.get_Height() / 2) - 100, 400, 200);
        globalGameEngine.add(gameOver);

        // Tar bort other.
        globalGameEngine.remove(other);
        // Stänger av movement för spelaren.
        isAlive = false;
        globalGameEngine.remove(this);
    }
}