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
	//sf::Clock cpHitClock ; // for cp come out from block

	int prevX;
	bool forward;
	bool containPower;
	bool bounce;
	bool isBouncing;
	int cpX;

	bool hadHitted;

	bool pCameOut;
	int powerSpeedX;
	int powerSpeedY;

	void blockAnimation();
	void powerAnimation(Map*, float);
	void coinAnimation(float);



public:
	QuestionBlock(sf::Texture&, float x, float y, bool);
	int checkRightCollision(sf::Sprite*);
	int checkLeftCollision(sf::Sprite*);
	int checkDownCollision(sf::Sprite*);
	int checkUpCollision(sf::Sprite* , bool);
	bool checkPowerUp(sf::Sprite*);
	void draw(sf::RenderWindow* window, float, Map*);
	void collide(sf::Sprite&);
};

