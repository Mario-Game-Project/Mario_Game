#include <SFML/Graphics.hpp>
class Map; // done to skip circular dependency while including Map.h .
#pragma once
class QuestionBlock
{
	sf::Sprite tile;
	sf::Sprite coin;
	sf::Sprite powerUp;
	sf::Clock clock;
	sf::Clock cpAnimation; // c-> coin , p-> power for cp animations

	int prevCol;
	bool colRight;
	bool containPower;
	bool bounce;
	bool isBouncing;
	int cpCol;
	int prevFloor;
	bool Hitten;

	bool cpCameOut;
	int powerSpeedX;
	int powerSpeedY;

	void blockAnimation();
	void powerAnimation(Map*, float);
	void coinAnimation(float);



public:
	QuestionBlock(sf::Texture&, float x, float y, bool containPower);
	int checkRightCollision(sf::Sprite* sprite, bool isBig);
	int checkLeftCollision(sf::Sprite* sprite, bool isBig);
	int checkDownCollision(sf::Sprite* sprite, bool isBig);
	int checkUpCollision(sf::Sprite* sprite, bool isBig);
	bool checkPowerUp(sf::Sprite*);
	void draw(sf::RenderWindow* window, float, Map*);
	void collide(sf::Sprite&);
};

