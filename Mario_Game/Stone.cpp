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
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	for (sf::Sprite tile : tiles) {

		float tileTop = tile.getGlobalBounds().top;
		float tileBottom = tileTop + tile.getGlobalBounds().height;
		float tileLeft = tile.getGlobalBounds().left + 6; // `+6` for right - left collision bug
		float tileRight = tileLeft + tile.getGlobalBounds().width - 12;

		if (tileRight > spriteLeft
			&& tileLeft < spriteRight
			&& tileTop <= spriteBottom
			&& tileTop > spriteTop
			&& tileBottom > spriteBottom
			) return tileTop;
	}
	return -1;
}

int Stone::checkRightCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	sf::Sprite tile = tiles.at(0);
	float tileTop = tile.getGlobalBounds().top;
	float tileBottom = tileTop + tile.getGlobalBounds().height - 4;
	float tileLeft = tile.getGlobalBounds().left + 3; // `+3` to fix player sprite's empty spaces in side creating bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 6;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft > spriteLeft
		&& tileLeft <= spriteRight
		&& tileTop < spriteBottom) return tileLeft;
	return -1;
}

int Stone::checkLeftCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	sf::Sprite tile = tiles.at(tiles.size() - 1);
	float tileTop = tile.getGlobalBounds().top;
	float tileBottom = tileTop + tile.getGlobalBounds().height - 4;
	float tileLeft = tile.getGlobalBounds().left + 3; // `+4` to fix player sprite's empty spaces in side creating bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 6;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileRight < spriteRight
		&& tileRight >= spriteLeft
		&& tileTop < spriteBottom
		) return tileRight;

	return -1;
}

sf::Vector2f Stone::getStartPos()
{
	return tiles.at(0).getPosition();
}

sf::Vector2f Stone::getEndPos()
{
	return tiles.at(tiles.size() - 1).getPosition() + sf::Vector2f(tiles.at(0).getGlobalBounds().width, 0);
}

void Stone::draw(sf::RenderWindow* window)
{
	for (sf::Sprite tile : tiles) {
		window->draw(tile);
	}
}
