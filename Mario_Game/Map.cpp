#include "Map.h"
#include <iostream>
void Map::renderFloor()
{
	Floor* floor = new Floor(texture, 0, 22, 30);
	floors.push_back(floor);
}

void Map::renderPipes()
{
	Pipe* pipe = new Pipe(texture, 2, 20, 21);
	pipes.push_back(pipe);
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
}

int Map::checkRightCollision(sf::Sprite* sprite)
{
	for (Pipe* pipe : pipes) {
		int res = pipe->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}
}
void Map::draw(sf::RenderWindow* window)
{
	window->draw(background);

	for (Floor* tile : floors) tile->draw(window);

	for (Pipe* tile : pipes) tile->draw(window);

}

