#include <SFML/Graphics.hpp>
#include "Floor.h"
#include "Pipe.h"
#include "Brick.h"
#include "QuestionBlock.h"
#include "Stone.h"

#pragma once
class Map
{
	sf::Texture texture;
	sf::Texture textureBg;
	sf::Sprite background;

	std::vector<Floor*> floors;
	std::vector<Pipe*> pipes;
	std::vector<Brick*> bricks;
	std::vector<QuestionBlock*> blocks;
	std::vector<Stone*> stones;
	sf::View view;

	int viewSpeed;
	int mapEnd;

	void renderFloor();
	void renderPipes();
	void renderBricksBlocks();
	void renderStones();

public:
	Map(float winWidth, float winHeight);
	int checkDownCollision(sf::Sprite* sprite);
	int checkLeftCollision(sf::Sprite* sprite , bool isMario);
	int checkRightCollision(sf::Sprite* sprite);

	int checkUpCollision(sf::Sprite* sprite , bool isBig);
	bool checkPowerUp(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window , float delta);
	void mapView(sf::Sprite* sprite , float delta);
};

