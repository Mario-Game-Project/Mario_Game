#include "Player.h"
#include <iostream>

Player::Player(sf::Texture& texture, float floor) :
	col(0),
	row(0),
	spriteWidth(32),
	spriteHeight(64),
	isMovingLeft(false),
	gravity(1120.0f),
	speedX(0),
	speedY(0),
	jumpSpeed(560.0f),
	canMoveLeft(true),
	canMoveRight(true),
	canMoveDown(true),
	canMoveUp(true),
	isBig(false),
	isDied(false),
	isInvisible(false),
	freeze(false),
	alpha(255)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	sprite.setPosition(100, floor);
}

sf::Sprite* Player::getSprite()
{
	return &sprite;
}

void Player::moveRight(float delta)
{
	if (speedX < 150 && canMoveRight) speedX += 300 * delta;
	if (!canMoveRight) speedX = 0;
}

void Player::moveLeft(float delta)
{
	if (speedX > -150 && canMoveLeft) speedX -= 300 * delta;
	if (!canMoveLeft) speedX = 0;
}

void Player::jump()
{
	if (!canMoveDown) {  // only jump when character is on the floor
		canMoveDown = true;
		sprite.move(0, -5); // to break contact from floor
		speedY = -jumpSpeed; // Set initial jump velocity
	}
}

void Player::enemyKilled()
{
	speedY = -300;
}

void Player::checkEnemyCollision(sf::Sprite* enemy)
{
	float spriteTop = sprite.getGlobalBounds().top;
	float spriteBottom = spriteTop + spriteHeight;
	float spriteLeft = sprite.getGlobalBounds().left;
	float spriteRight = spriteLeft + spriteWidth;

	float enemyTop = enemy->getGlobalBounds().top + 42;
	float enemyBottom = enemyTop + enemy->getGlobalBounds().height - 42;
	float enemyLeft = enemy->getGlobalBounds().left + 8;
	float enemyRight = enemyLeft + enemy->getGlobalBounds().width - 16;

	// TODO : FIX FOR EXTRA SPACES IN BOTH SPTIRES 

	if (enemy->getGlobalBounds().intersects(sprite.getGlobalBounds())
		&& !isDied
		&& !isInvisible
		&& enemyLeft < spriteRight
		&& enemyRight > spriteLeft
		&& enemyTop < spriteBottom
		&& enemyBottom >= spriteBottom
		) {

		if (isBig) {
			freeze = true;
			isInvisible = true;
			spriteClock.restart();
			row = row - 2;
			isBig = false;
		}
		else {
			col = 4;
			isDied = true;
			speedY = -300;
		}
	}
}
void Player::update(float delta, bool isMoving)
{
	/*This function is designed based on the fact that function will execute from top to bottom 
	So we are writing the functionalities in reverse priority order wrt to speed and sprite control.
	i.e. logic written in end is of most priority */

	// Updating sprite's indices for animation :

	/*================== Freeze ==================*/
	if (freeze) {
		freeze = spriteClock.getElapsedTime().asMilliseconds() > 1000 ? false : true;
		isInvisible = true;
		if (InvisiblityClock.getElapsedTime().asMilliseconds() > 50) {
			InvisiblityClock.restart();
			alpha = alpha > 0 ? 0 : 128;
		}
		if (!freeze) alpha = 128;
		sprite.setColor(sf::Color(255, 255, 255, alpha));
		return; // do not do any type of movement when freezed ( usually when upgraded/dowgraded )
	}

	/*============================= Invisibility ==============================*/
	if (isInvisible) {
		isInvisible = InvisiblityClock.getElapsedTime().asMilliseconds() > 1000 ? false : true;
		if (!isInvisible) sprite.setColor(sf::Color(255, 255, 255, 255));
	}

	/*=================== Left - Right Movements ================*/
	if (speedX > 0) {
		// Moing Right 
		if (isMovingLeft) {
			row--;
			isMovingLeft = false;
		}
		if (spriteClock.getElapsedTime().asMilliseconds() > 200) {
			col = (++col) % 2;
			spriteClock.restart();
		}
	}
	else if (speedX < 0) {
		// Moving Left
		if (!isMovingLeft) {
			row++;
			isMovingLeft = true;
		}
		if (spriteClock.getElapsedTime().asMilliseconds() > 200) {
			col = (++col) % 2;
			spriteClock.restart();
		}
	}
	else {
		// Stopped
		col = 0;
	}

	/* ============================ Applying friction ================================= */
	if (!isMoving)
	{
		if (speedX > 0) speedX -= 200 * delta;
		if (speedX < 0) speedX += 200 * delta;
		if (speedX > -10 && speedX < 10) speedX = 0;
	}

	/* ============================ Gravity ================================ */
	if (!canMoveUp) speedY = 50;
	if (canMoveDown) {
		speedY += gravity * delta; // Update vertical velocity with gravity
		col = 2;
	}
	else speedY = 0;

	/* ============================ Death ================================ */
	if (isDied) {
		speedX = 0;
		col = 4;
	}

	// ============================ Level Completed ================================

	if (touchedFlag) {
		if (canMoveDown) {
			speedX = 0;
			speedY = 100;
			col = 5;
		}
		else 
		{
			speedY = 0;
			moveRight(delta);
		}
	}

	if (reachedCastle) {
		speedX = 0;
		speedY = 0;
		alpha = alpha > 0 ? alpha -100 : 0;
		sprite.setColor(sf::Color(255, 255, 255,alpha));
	}

	sprite.move(speedX * delta, speedY * delta);

}
void Player::Upgrade()
{
	if (!isBig) {
		row = row + 2;
		freeze = true;
		spriteClock.restart();
		isBig = true;
	}
}

void Player::draw(sf::RenderWindow* window)
{
	// Changing texture Rectangle to create animations
	sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	window->draw(sprite);
}

