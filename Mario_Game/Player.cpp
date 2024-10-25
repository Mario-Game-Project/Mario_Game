#include "Player.h"
#include <iostream>

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
	jumpSpeed(300.0f),
	canMoveLeft(true),
	canMoveRight(true)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	sprite.setPosition(100, floor);
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

void Player::update(float delta , bool isMoving)
{
	// Updaing sprites for anmiations :
	if (speedX > 0) {
		// Moing Right 
		sprite.move(delta * 100, 0);
		if (isMovingLeft) {
			row--;
		}

		if (spriteClock.getElapsedTime().asMilliseconds() > 200) {
			col = (++col) % 2;
			spriteClock.restart();
		}
		isMovingLeft = false;
	}
	else if (speedX < 0){
		// Moving Left
		if (!isMovingLeft) {
			row++;
		}
		if (spriteClock.getElapsedTime().asMilliseconds() > 200) {
			col = (++col) % 2;
			spriteClock.restart();
		}
		isMovingLeft = true;
	}
	else {
		col = 0;
	}
	// Changing Sprite's textures to create an animation:
	sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	
	// Moving Sprites :
	sprite.move(speedX*delta , 0);

	// Logic to stop character when it is not ment to move 
	if (!isMoving)
	{
		//Applying friction
		if (speedX > 0) speedX -= 200 * delta;
		if (speedX < 0) speedX += 200 * delta;
		if (speedX > -10 && speedX < 10) speedX = 0;
	}
	
	// Add jumping animation logic in this or better create a new function named updateAnimations
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

void Player::setPosition( int x  , int y)
{
	if(y == -1) y = sprite.getPosition().y ;
	if(x == -1) x = sprite.getPosition().x ;
	sprite.setPosition(x, y);
}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

