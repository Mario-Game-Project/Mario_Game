#include "Enemy.h"

void Enemy::load()
{
	if (enemytexture.loadFromFile("Assets/Characters/SpriteSheet-32x64.png")) {
		std::cout << "loaded";
		enemysprite.setTexture(enemytexture);
		int x = 32;
		int y = 64;
		enemysprite.setTextureRect(IntRect(0, 4 * 64, 32, 64));
		enemysprite.setPosition(Vector2f(400, 21 * 32)); //21*32 to place it on the ground
	}
	else {
		std::cout << "failed to load";
	}
}

void Enemy::pos(int x, int y) {
	enemysprite.setPosition(Vector2f(x, y));
}

void Enemy::applyGravity(float delta) {
	if (!isGrounded) {  // Only apply gravity if not grounded
		verticalVelocity += gravity * delta; // Increase downward velocity due to gravity
		getSprite()->move(0, verticalVelocity * delta); // Move the enemy downwards
	}
}

// Stops the enemy from falling when it hits the ground/platform
void Enemy::stopFalling() {
	verticalVelocity = 0;  // Reset vertical velocity
	isGrounded = true;     // Mark the enemy as grounded
}

void Enemy::update(float deltaTime)
{

	Vector2f enemyPosition = enemysprite.getPosition();

	if (enemyMovingRight && enemymoving) {
		enemyPosition.x += enemySpeed * deltaTime;

		//enemysprite.setTextureRect(IntRect(0, 5 * 64, 32, 64));
		if (enemyclock.getElapsedTime().asMilliseconds() > 100) {
			col = ++col % 5;
			enemysprite.setTextureRect(IntRect(col * 32, 5 * 64, 32, 64));
			enemyclock.restart();
		}
		if (enemydied) {
			enemysprite.setTextureRect(IntRect(5 * 32, 4 * 64, 32, 64));
			//enemyMovingRight = false;
		}
		//if (enemyPosition.x > rightlimit) {
		//	enemyMovingRight = false;
		//	enemyMovingLeft = true;
		//	std::cout << "Enemy hit right limit!" << std::endl; // Debug info
		//}
	}
	else if (enemymoving) {
		enemyPosition.x -= enemySpeed * deltaTime;

		//enemysprite.setTextureRect(IntRect(0, 4 * 64, 32, 64));
		if (enemyclock.getElapsedTime().asMilliseconds() > 100) {
			col = ++col % 5;
			enemysprite.setTextureRect(IntRect(col * 32, 4 * 64, 32, 64));
			enemyclock.restart();
		}
		//if (enemyPosition.x < leftlimit) {
		//	enemyMovingLeft = false;
		//	enemyMovingRight = true;


		//	std::cout << "Enemy hit left limit!" << std::endl; // Debug info
		//}
	}
	enemysprite.setPosition(enemyPosition);
}



void Enemy::checkCollisionWithPlayer(Sprite& playerSprite) {
	// Get player and enemy bounds
	FloatRect playerBounds = playerSprite.getGlobalBounds();
	FloatRect enemyBounds = enemysprite.getGlobalBounds();

	// Check if player is colliding with enemy
	if (playerBounds.intersects(enemyBounds) && !enemydied && enemymoving) {
		// Check if player is hitting from the top
		if (playerBounds.top + playerBounds.height <= enemyBounds.top + 32 &&
			playerBounds.left + playerBounds.width > enemyBounds.left &&
			playerBounds.left < enemyBounds.left + enemyBounds.width) {
			enemydied = true;
			enemymoving = false;
			// Example of removing the enemy
		}
		else {
			// Player hits enemy from the side - Player dies
			//std::cout << "Player hit enemy from the side! Player dies." << std::endl;

		}
	}
}

void Enemy::deadanimation() {

	enemysprite.setTextureRect(IntRect(5 * 32, 4 * 64, 32, 64));

	if (enemyclock.getElapsedTime().asMilliseconds() > 100) {

		/* if (!deadBool) {
			 enemysprite.move(1, -0);
			 deadAnimeCounter++;
			 if (deadAnimeCounter >= 20) {
				 deadBool = true;
			 }
		 }*/
		 /* else {

		  }*/
		enemysprite.move(0, 0.5);

		//enemyclock.restart();
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	if (enemydied) {
		deadanimation();
	}

	window.draw(enemysprite);
}

sf::Sprite* Enemy::getSprite()
{
	return &enemysprite;
}
