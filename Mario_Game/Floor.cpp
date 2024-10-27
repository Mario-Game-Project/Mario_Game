#include "Floor.h"
#include <iostream>


Floor::Floor(sf::Texture& texture, int posTilesX, int posTilesY, int tilesN)
{
	sf::Sprite sprite;
	sprite.setTexture(texture);
	int col = 0; // for spritesheet columns indexing

	while (tilesN > 1) {
		sprite.setTextureRect(sf::IntRect(col * 32, 0, 32, 32 * 3));
		sprite.setPosition(posTilesX * 32, posTilesY * 32);
		tiles.push_back(sprite);
		posTilesX++;
		col = (col + 1) % 19;
		tilesN--;
	}
	sprite.setTextureRect(sf::IntRect(19 * 32, 0, 32, 32 * 3));
	sprite.setPosition(posTilesX * 32, posTilesY * 32);
	tiles.push_back(sprite);
}

int Floor::checkDownCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10; // `+10` to fix player sprite's empty spaces in side creating bug
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	for (sf::Sprite tile : tiles) {
		float tileTop = tile.getGlobalBounds().top + 32;
		float tileBottom = tileTop + 32;
		float tileLeft = tile.getGlobalBounds().left;
		float tileRight = tileLeft + tile.getGlobalBounds().width;

		if (tileRight > spriteLeft
			&& tileLeft < spriteRight
			&& tileTop <= spriteBottom
			&& tileTop > spriteTop
			&& tileBottom > spriteBottom
			) {
			return tileTop;
		}
	}
	return -1;
}

int Floor::checkRightCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	sf::Sprite tile = tiles.at(0);
	float tileTop = tile.getGlobalBounds().top + 5;
	float tileBottom = tileTop + tile.getGlobalBounds().height - 10;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft > spriteLeft
		&& tileRight > spriteRight
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop) {
		return tileLeft;
	}
	return -1;
}

int Floor::checkLeftCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	sf::Sprite tile = tiles.at(tiles.size() - 1);
	float tileTop = tile.getGlobalBounds().top + 5;
	float tileBottom = tileTop + tile.getGlobalBounds().height - 10;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft < spriteLeft
		&& tileRight < spriteRight
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop
		) {
		return tileRight;
	}

	return -1;
}

void Floor::draw(sf::RenderWindow* window)
{
	for (sf::Sprite tile : tiles) window->draw(tile);
}
