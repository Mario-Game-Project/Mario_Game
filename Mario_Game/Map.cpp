#include "Map.h"
#include <iostream>

void Map::renderFloor()
{
	{
		Floor* floor = new Floor(texture, 0, 22, 66);
		floors.push_back(floor);
	}
	{
		Floor* floor = new Floor(texture, 69, 22, 84 - 69);
		floors.push_back(floor);
	}
	{
		Floor* floor = new Floor(texture, 87, 22, 200 - 87);
		floors.push_back(floor);
	}
	mapEnd = 200;
}

void Map::renderPipes()
{
	{
		Pipe* pipe = new Pipe(texture, 2, 20, 21);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 3, 34, 20);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 4, 42, 19);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 4, 53, 19);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 3, 126, 20);
		pipes.push_back(pipe);
	}
}

void Map::renderBricksBlocks()
{
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

	{

		{
			Brick* brick = new Brick(texture, 14, 15);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 15, 15, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 16, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 75, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 76, 19);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 77, 19, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 78, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 79, 19);
			bricks.push_back(brick);
		}
	}

	{

		{
			Brick* brick = new Brick(texture, 79, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 80, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 81, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 82, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 83, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 84, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 85, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 88, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 89, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 90, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 91, 15);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 92, 15, false);
			blocks.push_back(block);
		}
	}

	{
		Brick* brick = new Brick(texture, 92, 19);
		bricks.push_back(brick);
	}

	{
		{
			QuestionBlock* block = new QuestionBlock(texture, 98, 19, false);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 101, 19, false);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 101, 15, true);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 104, 19, false);
			blocks.push_back(block);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 109, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 110, 19);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 112, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 113, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 114, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 118, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 119, 15);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 120, 15, false);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 121, 15, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 122, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 119, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 120, 19);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 135, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 136, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 137, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 138, 19);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 139, 19, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 140, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 141, 19);
			bricks.push_back(brick);
		}
	}

}

void Map::renderStones()
{
	int posX = mapEnd - 32;
	for (int i = 0; i < 10; i++) {
		Stone* stone = new Stone(texture, posX - 10 + i, 22 - i, 11 - i);
		stones.push_back(stone);
	}
}

void Map::renderCastleFlag()
{
	castle = new Castle(texture, mapEnd - 15.5, 23 - 10);
	flag = new Flag(texture, mapEnd - 25, 22, 14);
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

	// Rendering Components :

	renderFloor();
	renderPipes();
	renderBricksBlocks();
	renderStones();
	renderCastleFlag();

	// Setting View :

	view.setCenter(sf::Vector2f(winWidth / 2, (winHeight / 2)));
	view.setSize(sf::Vector2f(winWidth, winHeight));
	view.zoom(1);

	winRightBorder = view.getCenter().x + view.getSize().x / 2;
	winLeftBorder = view.getCenter().x - view.getSize().x / 2;
}

int Map::checkDownCollision(sf::Sprite* sprite, bool isBig)
{
	for (Floor* floor : floors) {
		int tileLeft = floor->getStartPos().x;
		int tileRight = floor->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = floor->checkDownCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;

	}

	for (Pipe* pipe : pipes) {

		int tileLeft = pipe->getStartPos().x;
		int tileRight = pipe->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = pipe->checkDownCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (Brick* brick : bricks) {

		int tileLeft = brick->getStartPos().x;
		int tileRight = brick->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = brick->checkDownCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (QuestionBlock* block : blocks)
	{
		int tileLeft = block->getStartPos().x;
		int tileRight = block->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = block->checkDownCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;

	}

	for (Stone* stone : stones) {

		int tileLeft = stone->getStartPos().x;
		int tileRight = stone->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = stone->checkDownCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}
	return -1;
}

int Map::checkLeftCollision(sf::Sprite* sprite, bool isBig, bool isMario)
{
	// fixing left border for mario only
	int leftBorder = view.getCenter().x - view.getSize().x / 2 + 10;
	if (isMario && sprite->getPosition().x < leftBorder) return leftBorder;

	for (Pipe* pipe : pipes) {
		int tileLeft = pipe->getStartPos().x;
		int tileRight = pipe->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = pipe->checkLeftCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (Brick* brick : bricks) {

		int tileLeft = brick->getStartPos().x;
		int tileRight = brick->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = brick->checkLeftCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (QuestionBlock* block : blocks)
	{
		int tileLeft = block->getStartPos().x;
		int tileRight = block->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = block->checkLeftCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;

	}

	for (Stone* stone : stones) {

		int tileLeft = stone->getStartPos().x;
		int tileRight = stone->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = stone->checkLeftCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	return -1;
}

int Map::checkRightCollision(sf::Sprite* sprite, bool isBig)
{
	for (Pipe* pipe : pipes) {
		int tileLeft = pipe->getStartPos().x;
		int tileRight = pipe->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = pipe->checkRightCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}


	for (Brick* brick : bricks) {
		int tileLeft = brick->getStartPos().x;
		int tileRight = brick->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = brick->checkRightCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (QuestionBlock* block : blocks)
	{
		int tileLeft = block->getStartPos().x;
		int tileRight = block->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = block->checkRightCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (Stone* stone : stones) {
		int tileLeft = stone->getStartPos().x;
		int tileRight = stone->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = stone->checkRightCollision(sprite);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	return -1;
}
int Map::checkUpCollision(sf::Sprite* sprite, bool isBig)
{
	for (Brick* brick : bricks) {
		int tileLeft = brick->getStartPos().x;
		int tileRight = brick->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = brick->checkUpCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	for (QuestionBlock* block : blocks)
	{
		int tileLeft = block->getStartPos().x;
		int tileRight = block->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			int res = block->checkUpCollision(sprite, isBig);
			if (res > -1) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	return -1;
}

int Map::checkEndFlag(sf::Sprite* sprite)
{
	if (flag->getPosition().x < winRightBorder) return flag->checkPoleCollision(sprite);

	return -1;
}

bool Map::checkCastleDoor(sf::Sprite* sprite)
{
	if (castle->getPosition().x < winRightBorder) return castle->castleDoor(sprite);

	return false;
}

bool Map::checkPowerUp(sf::Sprite* sprite)
{
	for (QuestionBlock* block : blocks) {
		int tileLeft = block->getStartPos().x;
		int tileRight = block->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) // only check if not out of view
		{
			bool res = block->checkPowerUp(sprite);
			if (res) return res;
		}
		else if (tileLeft > winRightBorder) break;
	}

	return false;
}

void Map::draw(sf::RenderWindow* window, float delta)
{
	window->draw(background);

	window->setView(view);

	for (Floor* floor : floors)
	{
		int tileLeft = floor->getStartPos().x;
		int tileRight = floor->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) floor->draw(window); // only render if not out of view
		else if (tileLeft > winRightBorder) break;
	}

	for (Pipe* pipe : pipes)
	{
		int tileLeft = pipe->getStartPos().x;
		int tileRight = pipe->getEndPos().x;

		/* if (tileLeft < winRightBorder)
		{
			if (tileRight < winLeftBorder)
			{
				delete pipe;
				pipes.erase(pipes.begin());
			}
			else pipe->draw(window);
			std::cout << pipes.size() << std::endl;
		}
		else break;
		*/

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) pipe->draw(window); // only render if not out of view
		else if (tileLeft > winRightBorder) break;
	}


	for (Brick* brick : bricks)
	{
		int tileLeft = brick->getStartPos().x;
		int tileRight = brick->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) brick->draw(window); // only render if not out of view
		else if (tileLeft > winRightBorder) break;
	}

	for (QuestionBlock* block : blocks)
	{
		int tileLeft = block->getStartPos().x;
		int tileRight = block->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) block->draw(window, delta, this); // only render if not out of view
		else if (tileLeft > winRightBorder) break;
	}

	for (Stone* stone : stones)
	{
		int tileLeft = stone->getStartPos().x;
		int tileRight = stone->getEndPos().x;

		if (tileLeft < winRightBorder && tileRight > winLeftBorder) stone->draw(window); // only render if not out of view
		else if (tileLeft > winRightBorder) break;
	}

	if (castle->getPosition().x < winRightBorder) castle->draw(window);

	if (flag->getPosition().x < winRightBorder) flag->draw(window, delta);
}

void Map::mapView(sf::Sprite* sprite, float delta)
{
	winRightBorder = view.getCenter().x + view.getSize().x / 2;
	winLeftBorder = view.getCenter().x - view.getSize().x / 2;

	background.setPosition(view.getCenter().x - (view.getSize().x / 2.0), view.getCenter().y - (view.getSize().y / 2.0));

	if (view.getCenter().x + view.getSize().x / 2 >= mapEnd * 32) return;

	int speed = sprite->getPosition().x - view.getCenter().x;

	if (speed > 0) view.setCenter(view.getCenter().x + speed, view.getCenter().y);
}

