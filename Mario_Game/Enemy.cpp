#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, int x, int y) :
	enemySpeed_X(50),
	col(0),
	row(0),
	gravity(980),
	enemySpeed_Y(0),
	isGrounded(true),
	deadAnimeCounter(0),
	enemyDied(false),
	enemyMovingRight(false)
{
	enemySprite.setTexture(*texture);
	enemySprite.setTextureRect(IntRect(0, 4 * 64, 32, 64));
	enemySprite.setPosition(Vector2f(x, y));
}

sf::Sprite* Enemy::getSprite()
{
	return &enemySprite;
}

sf::Vector2f Enemy::getStartPos()
{
	return enemySprite.getPosition();
}

sf::Vector2f Enemy::getEndPos()
{
	return enemySprite.getPosition() + sf::Vector2f(enemySprite.getGlobalBounds().width, 0);
}

void Enemy::checkEnemiesCollision(Enemy* enemy)
{
	sf::FloatRect enemyBounds = this->enemySprite.getGlobalBounds();
	sf::FloatRect anotherEnemyBounds = enemy->enemySprite.getGlobalBounds();


	if (enemyBounds.intersects(anotherEnemyBounds)) {
		// Reverse direction for both enemies upon collision

		// Check head collision
		if (enemyBounds.top + enemyBounds.height >= anotherEnemyBounds.top + 32
			&& enemyBounds.top + enemyBounds.height < anotherEnemyBounds.top + anotherEnemyBounds.height)
		{
			enemySprite.setPosition(sf::Vector2f(enemySprite.getPosition().x, enemy ->enemySprite.getPosition().y - 40));
			this->enemySpeed_Y = -300;
		}
		/*else if (anotherEnemyBounds.top + anotherEnemyBounds.height >= enemyBounds.top + 32
			&& anotherEnemyBounds.top + anotherEnemyBounds.height < enemyBounds.top + enemyBounds.height)
		{
			enemy->enemySpeed_Y = -300;
			enemy->enemySprite.move(0, -10);
		}*/

		this->enemyMovingRight = !this->enemyMovingRight;
		enemy->enemyMovingRight = !enemy->enemyMovingRight;


		// For avoiding bugs : 
		if (this->enemyMovingRight) this->enemySprite.move(5, 0);
		else this->enemySprite.move(-5, 0);

		if (enemy->enemyMovingRight) enemy->enemySprite.move(5, 0);
		else enemy->enemySprite.move(-5, 0);
	}
}

void Enemy::checkCollisionWithPlayer(Sprite& playerSprite) {
	// Get player and enemy bounds
	FloatRect playerBounds = playerSprite.getGlobalBounds();
	FloatRect enemyBounds = enemySprite.getGlobalBounds();

	// Check if player is colliding with enemy from upside
	if (playerBounds.intersects(enemyBounds)
		&& !enemyDied
		&& playerBounds.top + playerBounds.height >= enemyBounds.top + 32 // `+ 45` for accuraccy as per spritesheet
		&& playerBounds.left + playerBounds.width > enemyBounds.left + 8.5 // `+5` for accuraccy as per spritesheet
		&& playerBounds.left < enemyBounds.left + enemyBounds.width - 8.5) {

		enemySpeed_Y = -300; // jump
		enemyDied = true;
		enemyMovingRight = !enemyMovingRight;
	}
}

void Enemy::update(float delta)
{
	bool updateTexture = false;
	Vector2f enemyMove;

	// Left-Right movements
	if (enemyMovingRight) {
		enemyMove.x += enemySpeed_X * delta;

		if (enemyClock.getElapsedTime().asMilliseconds() > 100) {
			col = ++col % 5;
			row = 5;
			updateTexture = true;
			enemyClock.restart();
		}
	}
	else {
		enemyMove.x -= enemySpeed_X * delta;
		if (enemyClock.getElapsedTime().asMilliseconds() > 100) {
			col = ++col % 5;
			row = 4;
			updateTexture = true;
			enemyClock.restart();
		}
	}

	// death animation 
	if (enemyDied) {
		col = 5;
		updateTexture = true;

		// jumping speed in set in collisionWithPlayer function
	}

	// gravity :
	if (!isGrounded) {  // Only apply gravity if not grounded
		enemySpeed_Y += gravity * delta; // Increase downward velocity due to gravity
		enemyMove.x = 0;
		enemyMove.y += enemySpeed_Y * delta; // Update vertical position
	}
	else {
		enemySpeed_Y = 0;  // Reset vertical velocity
		isGrounded = true;     // Mark the enemy as grounded
	}

	if (updateTexture) enemySprite.setTextureRect(IntRect(col * 32, row * 64, 32, 64));
	enemySprite.move(enemyMove);
}
void Enemy::draw(sf::RenderWindow* window)
{
	window->draw(enemySprite);
}
