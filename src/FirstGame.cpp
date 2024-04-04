#include "Player.h"
#include "EnemyTwo.h"
#include "EnemySpawner.h"
#include "Bullet.h"
#include "Background.h"
#include "ScoreLabel.h"

using namespace MyGameEngine;

int main(int argc, char **argv)
{
	// Skapar och lägger till bakgrunden
	Background *bg1 = Background::getInstance("images/bg.png");
	globalGameEngine.add(bg1);

	// Skapar och lägger till ScoreLabel objekt.
	ScoreLabel *scoreLabel = ScoreLabel::getInstance(50, 50, 48, 48);
	globalGameEngine.add(scoreLabel);

	// Skapar och lägger till Player objekt.
	Player *player = Player::getInstance("images/player.png", 500, 700, 80, 6);
	globalGameEngine.add(player);

	// Skapar och lägger till en EnemySpawner
	EnemySpawner *eSpawner = EnemySpawner::getInstance("images/destroyer.png", 100, -100, 100, 5, 2, 50);
	globalGameEngine.add(eSpawner);

	// Kör session.
	globalGameEngine.run();
	return 0;
}
