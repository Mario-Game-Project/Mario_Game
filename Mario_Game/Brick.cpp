#include "Brick.h"
#include "Brick.h"
#include <iostream>

Brick::Brick(sf::Texture& texture, float x, float y)
{
	tile.setTexture(texture);
	tile.setTextureRect(sf::IntRect(16 * 32, 6 * 32, 1 * 32, 1 * 32));
	tile.setPosition(x * 32, y * 32);
}

int Brick::checkRightCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

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

int Brick::checkLeftCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height ;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

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

int Brick::checkDownCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

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

int Brick::checkUpCollision(sf::Sprite* sprite)
{

	float spriteTop = sprite->getGlobalBounds().top;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height ;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	float tileTop = tile.getGlobalBounds().top + tile.getGlobalBounds().height / 2.0;
	float tileBottom = tileTop + tile.getGlobalBounds().height / 2.0;
	float tileLeft = tile.getGlobalBounds().left - 5;
	float tileRight = tileLeft + tile.getGlobalBounds().width + 10;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileBottom > spriteTop
		&& tileTop <= spriteBottom
		&& tileRight > spriteLeft
		&& tileLeft < spriteRight
		) {
		return tileBottom;
	}
	return -1;
}

void Brick::draw(sf::RenderWindow* window)
{
	window->draw(tile);
}
