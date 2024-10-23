#include "Player.h"

Player::Player(sf::Texture& texture, float floor) :
	col(0),
	row(0),
	spriteWidth(32),
	spriteHeight(64),
	isMovingLeft(false),
	gravity(500.0f),
	speedX(0),
	speedY(0),
	floor(floor),
	isJumping(false),
	jumpSpeed(300.0f)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	sprite.setPosition(100, floor);
}

void Player::moveRight(float delta)
{
	sprite.move(delta * 100, 0);
	if (isMovingLeft) {
		row--;
	}

	if (spriteClock.getElapsedTime().asMilliseconds() > 200) {
		col = (++col) % 2;
		sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
		spriteClock.restart();
	}
	isMovingLeft = false;
}

void Player::moveLeft(float delta)
{
	sprite.move(-delta * 100, 0);
	if (!isMovingLeft) {
		row++;
	}

	if (spriteClock.getElapsedTime().asMilliseconds() > 200) {
		col = (++col) % 2;
		sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
		spriteClock.restart();
	}
	isMovingLeft = true;
}

void Player::jump()
{
	if (!isJumping) {
		isJumping = true;
		speedY = -jumpSpeed; // Set initial jump velocity
	}
}

void Player::applyGravity(float delta)
{
	if (isJumping) {
		speedY += gravity * delta; // Update vertical velocity with gravity
		sprite.move(0, speedY * delta); // Move the sprite based on vertical velocity
		col = 2;
		sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));

		// Check if the sprite has landed
		if (sprite.getPosition().y >= floor) {
			sprite.setPosition(sprite.getPosition().x, floor);
			isJumping = false; // Reset jumping status
			speedY = 0.0f; // Reset vertical velocity
			col = 0;
			sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
		}
	}
}

sf::Sprite* Player::getSprite()
{
	return &sprite;
}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

