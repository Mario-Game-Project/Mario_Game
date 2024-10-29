#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, int x, int y) :
	enemySpeed_X(85),
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

void Enemy::checkCollisionWithPlayer(Sprite& playerSprite) {
	// Get player and enemy bounds
	FloatRect playerBounds = playerSprite.getGlobalBounds();
	FloatRect enemyBounds = enemySprite.getGlobalBounds();

	// Check if player is colliding with enemy from upside
	if (playerBounds.intersects(enemyBounds) 
		&& !enemyDied 
		&& playerBounds.top + playerBounds.height <= enemyBounds.top + 36 // 32 + 4 for accuraccy as per spritesheet
		&& playerBounds.left + playerBounds.width > enemyBounds.left + 5 // `+5` for accuraccy as per spritesheet
		&& playerBounds.left < enemyBounds.left + enemyBounds.width - 10) {
		enemySpeed_Y = -300; // jump
		enemyDied = true;
	}
}

void Enemy::update(float delta)
{
	bool updateTexture = false;
	Vector2f enemyPosition = enemySprite.getPosition();

	// Left-Right movements
	if (enemyMovingRight) {
		enemyPosition.x += enemySpeed_X * delta;

		if (enemyClock.getElapsedTime().asMilliseconds() > 100) {
			col = ++col % 5;
			row = 5;
			updateTexture = true;
			enemyClock.restart();
		}
	}
	else {
		enemyPosition.x -= enemySpeed_X * delta;
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
		enemyPosition.y += enemySpeed_Y * delta; // Update vertical position
	}
	else {
		enemySpeed_Y = 0;  // Reset vertical velocity
		isGrounded = true;     // Mark the enemy as grounded
	}

	if (updateTexture) enemySprite.setTextureRect(IntRect(col * 32, row * 64, 32, 64));
	enemySprite.setPosition(enemyPosition);
}
void Enemy::draw(sf::RenderWindow* window)
{
	window->draw(enemySprite);
}
