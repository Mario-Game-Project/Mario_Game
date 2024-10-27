#include "Stone.h"

Stone::Stone(sf::Texture& texture, float x, float y, float tilesN)
{
	sf::Sprite tile;
	tile.setTexture(texture);
	tile.setTextureRect(sf::IntRect(17 * 32, 6 * 32, 32, 32));

	for (int i = 0; i < tilesN; i++)
	{
		tile.setPosition((x + i) * 32, (y) * 32);
		tiles.push_back(tile);
	}
}

int Stone::checkDownCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	for (sf::Sprite tile : tiles) {

		float tileTop = tile.getGlobalBounds().top + 2;
		float tileBottom = tileTop + tile.getGlobalBounds().height;
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

int Stone::checkRightCollision(sf::Sprite* sprite)
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

int Stone::checkLeftCollision(sf::Sprite* sprite)
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

void Stone::draw(sf::RenderWindow* window)
{
	for (sf::Sprite tile : tiles) {
		window->draw(tile);
	}
}
