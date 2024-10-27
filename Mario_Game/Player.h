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
	bool isMovingLeft; 
	float jumpSpeed;// Speed of the jump
public:
	bool canMoveRight;
	bool canMoveLeft;
	bool canMoveUp;
	bool canMoveDown;
	//bool isJumping;
	bool isBig;
	Player(sf::Texture& texture, float floor);
	void moveRight(float delta);
	void moveLeft(float delta);
	void update(float delta , bool isMoving);
	void jump();
	void applyGravity(float delta);
	sf::Sprite* getSprite();
	void setPosition( int x  , int y);
	void Upgrade();
	void draw(sf::RenderWindow* window);
};

