#include "Map.h"
#include <iostream>
void Map::renderFloor()
{
	Floor* floor = new Floor(texture, 0, 22, 40);
	floors.push_back(floor);
}

void Map::renderPipes()
{
	Pipe* pipe = new Pipe(texture, 2, 20, 21);
	pipes.push_back(pipe);


	Pipe* pipe2 = new Pipe(texture, 3, 34, 20);
	pipes.push_back(pipe2);

}

void Map::renderBricksBlocks()
{
	{
		Brick* brick = new Brick(texture, 13, 19);
		bricks.push_back(brick);
	}
	{
		QuestionBlock* block = new QuestionBlock(texture, 14, 19, true);
		blocks.push_back(block);
	}
	{
		Brick* brick = new Brick(texture, 15, 19);
		bricks.push_back(brick);
	}
	{
		QuestionBlock* block = new QuestionBlock(texture, 16, 19, false);
		blocks.push_back(block);
	}
	{
		Brick* brick = new Brick(texture, 17, 19);
		bricks.push_back(brick);
	}

}

void Map::renderStones()
{
	for (int i = 0; i < 3; i++) {
		Stone* stone = new Stone(texture, 5 + i, 22 - i, 3 - i);
		stones.push_back(stone);
	}
}

Map::Map(float winWidth, float winHeight)
{
	// Loading tilesheet
	if (!texture.loadFromFile("./Assets/Map/tilesheet.png"))
		std::cout << "Failed to load tilesheet" << std::endl;

	// Setting background (sky)
	if (textureBg.loadFromFile("./Assets/Map/background.jpg")) {
		background.setTexture(textureBg);
		background.scale(
			float(winWidth) / textureBg.getSize().x,
			float(winHeight) / textureBg.getSize().y
		);
		background.setPosition(0, 0);
	}
	else std::cout << "Failed to load background" << std::endl;

	/*========================== Rendering Components : ==========================*/

	renderFloor();
	renderPipes();
	renderBricksBlocks();
	renderStones();
}

int Map::checkDownCollision(sf::Sprite* sprite)
{
	for (Floor* floor : floors) {
		int res = floor->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Pipe* pipe : pipes) {
		int res = pipe->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for(QuestionBlock* block : blocks)
	{
		int res = block->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Stone* stone : stones) {
		int res = stone->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

int Map::checkLeftCollision(sf::Sprite* sprite)
{
	for (Pipe* pipe : pipes) {
		int res = pipe->checkLeftCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkLeftCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for(QuestionBlock* block : blocks)
	{
		int res = block->checkLeftCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Stone* stone : stones) {
		int res = stone->checkLeftCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

int Map::checkRightCollision(sf::Sprite* sprite)
{
	for (Pipe* pipe : pipes) {
		int res = pipe->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for(QuestionBlock* block : blocks)
	{
		int res = block->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Stone* stone : stones) {
		int res = stone->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

int Map::checkUpCollision(sf::Sprite* sprite , bool isBig)
{

	for (Brick* brick : bricks) {
		int res = brick->checkUpCollision(sprite , isBig);

		if (res > -1) {
			return res;
		}
	}

	for(QuestionBlock* block : blocks)
	{
		int res = block->checkUpCollision(sprite , isBig);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

bool Map::checkPowerUp(sf::Sprite* sprite)
{
	for (QuestionBlock* block : blocks) {
		bool res = block->checkPowerUp(sprite);
		if (res) {
			return res;
		}
	}
	return false;
}

void Map::draw(sf::RenderWindow* window , float delta)
{
	window->draw(background);

	for (Floor* tile : floors) tile->draw(window);

	for (Pipe* tile : pipes) tile->draw(window);

	for (Brick* brick : bricks) brick->draw(window);
	
	for(QuestionBlock* block : blocks) block->draw(window ,delta , this);

	for (Stone* stone : stones) stone->draw(window);
}

