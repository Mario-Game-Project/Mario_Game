#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Pipe::Pipe(sf::Texture& texture, int pipeHeight, float posTileX, float posTileY)
{
	sf::Sprite top;
	top.setTexture(texture);
	top.setTextureRect(sf::IntRect(3 * 32, 5 * 32, 64, 32));

	sf::Sprite bottom;
	bottom.setTexture(texture);
	bottom.setTextureRect(sf::IntRect(3 * 32, 6 * 32, 64, 32));

	while (pipeHeight > 1)
	{
		bottom.setPosition(posTileX * 32, (posTileY + pipeHeight - 1) * 32);
		tiles.push_back(bottom);
		pipeHeight--;
	}

	top.setPosition(posTileX * 32, posTileY * 32);
	tiles.push_back(top);
}

int Pipe::checkRightCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10; // `+10` to fix player sprite's empty spaces in side creating bug
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	for (sf::Sprite tile : tiles) {
		float tileTop = tile.getGlobalBounds().top + 4;
		float tileBottom = tileTop + tile.getGlobalBounds().height;
		float tileLeft = tile.getGlobalBounds().left + 4;
		float tileRight = tileLeft + tile.getGlobalBounds().width - 8;

		if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
			&& tileLeft > spriteLeft
			&& tileRight > spriteRight
			&& tileTop < spriteBottom
			&& tileBottom > spriteTop) {
			return tileLeft - 4;
		}
	}
	return -1;
}

int Pipe::checkLeftCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;// `+10` to fix player sprite's empty spaces in side creating bug
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;


	for (sf::Sprite tile : tiles) {

		float tileTop = tile.getGlobalBounds().top + 4;
		float tileBottom = tileTop + tile.getGlobalBounds().height - 8;
		float tileLeft = tile.getGlobalBounds().left + 4;
		float tileRight = tileLeft + tile.getGlobalBounds().width - 8;

		if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
			&& tileLeft < spriteLeft
			&& tileRight < spriteRight
			&& tileTop < spriteBottom
			&& tileBottom > spriteTop
			) {
			return tileRight + 4;
		}
	}
	return -1;
}

int Pipe::checkDownCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10; // `+10` to fix player sprite's empty spaces in side creating bug
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	sf::Sprite tile = tiles.at(tiles.size() - 1);

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
	return -1;
}

void Pipe::draw(sf::RenderWindow* window)
{
	for (sf::Sprite pipe : tiles) {
		window->draw(pipe);
	}
}