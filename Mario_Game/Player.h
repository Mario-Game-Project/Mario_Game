#include <SFML/Graphics.hpp>
#pragma once
class Player
{
	int col;
	int row;
	int spriteWidth;
	int spriteHeight;
	sf::Clock spriteClock;
	sf::Sprite sprite;

	int speedX;  // Horizontal speed
	int speedY;  // Vertical speed
	float gravity;     // Gravity force
	float floor; // Y position of the ground
	bool isMovingLeft;
	bool isJumping;
	float jumpSpeed;// Speed of the jump
public : 
	Player(sf::Texture& texture, float floor);
	void moveRight(float);
	void moveLeft(float);
	void jump();
	void applyGravity(float);

	void draw(sf::RenderWindow* window);
};

