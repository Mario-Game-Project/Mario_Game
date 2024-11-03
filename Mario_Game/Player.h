#include <SFML/Graphics.hpp>
#include "Enemy.h"
#pragma once
class Player
{
	int col;
	int row;
	int spriteWidth;
	int spriteHeight;
	sf::Clock spriteClock;
	sf::Clock InvisiblityClock;
	sf::Sprite sprite;

	int speedX;  // Horizontal speed
	int speedY;  // Vertical speed
	float gravity;     // Gravity force
	bool isMovingLeft; 
	float jumpSpeed;// Speed of the jump
	bool freeze; 
	int alpha;
public:
	bool canMoveRight;
	bool canMoveLeft;
	bool canMoveUp;
	bool canMoveDown;
	bool isDied;
	bool isBig;
	bool isInvisible;
	bool touchedFlag;
	bool reachedCastle;
	Player(sf::Texture& texture, float floor);
	sf::Sprite* getSprite();
	void moveRight(float delta);
	void moveLeft(float delta);
	void jump();
	void enemyKilled();
	void checkEnemyCollision(sf::Sprite* enemy);
	void update(float delta, bool isMoving);
	void Upgrade();
	void draw(sf::RenderWindow* window);
};

