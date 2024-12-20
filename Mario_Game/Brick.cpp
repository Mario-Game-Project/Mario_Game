#include "Brick.h"
#include <iostream>

void Brick::breakBounce()
{
	if (bounce && clock.getElapsedTime().asMilliseconds() >= 100) {
		if (!isBouncing) {
			tile.move(0, -5);
			topLeft.move(0, -5);
			topRight.move(0, -5);
			bottomLeft.move(0, -5);
			bottomRight.move(0, -5);
			isBouncing = true;
		}
		else {
			tile.move(0, 5);
			topLeft.move(0, 5);
			topRight.move(0, 5);
			bottomLeft.move(0, 5);
			bottomRight.move(0, 5);
			isBouncing = false;
			bounce = false;
		}

		clock.restart();
	}

	if (breakIt && clock.getElapsedTime().asMilliseconds() >= 10) {

		tile.setSize(sf::Vector2f(0, 0));

		if (topLeft.getPosition().x > tile.getPosition().x - 32) {
			topLeft.move(-4, -4);
		}
		else {
			topLeft.move(-1, 10);
		}

		if (topRight.getPosition().x < tile.getPosition().x + 48) {
			topRight.move(4, -4);
		}
		else {
			topRight.move(1, 10);
		}

		if (bottomLeft.getPosition().x > tile.getPosition().x - 32) {
			bottomLeft.move(-4, 4);
		}
		else {
			bottomLeft.move(-1, 10);
		}

		if (bottomRight.getPosition().x < tile.getPosition().x + 48) {
			bottomRight.move(4, 4);
		}
		else {
			bottomRight.move(1, 10);
		}

		topLeft.setOrigin(8, 8);
		topRight.setOrigin(8, 8);
		bottomLeft.setOrigin(8, 8);
		bottomRight.setOrigin(8, 8);

		topLeft.rotate(10);
		topRight.rotate(10);
		bottomLeft.rotate(10);
		bottomRight.rotate(10);

		clock.restart();
	}
}

Brick::Brick(sf::Texture& texture, float x, float y) :
	isBouncing(false),
	bounce(false),
	breakIt(false),
	isBig(false)
{
	tile.setSize(sf::Vector2f(32, 32));
	tile.setPosition(x * 32, y * 32);

	topLeft.setTexture(texture);
	topLeft.setTextureRect(sf::IntRect(16 * 32, 6 * 32, 1 * 16, 1 * 16));
	topLeft.setPosition(x * 32, y * 32);

	topRight.setTexture(texture);
	topRight.setTextureRect(sf::IntRect(16 * 32 + 16, 6 * 32, 1 * 16, 1 * 16));
	topRight.setPosition(x * 32 + 16, y * 32);

	bottomLeft.setTexture(texture);
	bottomLeft.setTextureRect(sf::IntRect(16 * 32, 6 * 32 + 16, 1 * 16, 1 * 16));
	bottomLeft.setPosition(x * 32, y * 32 + 16);

	bottomRight.setTexture(texture);
	bottomRight.setTextureRect(sf::IntRect(16 * 32 + 16, 6 * 32 + 16, 1 * 16, 1 * 16));
	bottomRight.setPosition(x * 32 + 16, y * 32 + 16);
}

int Brick::checkRightCollision(sf::Sprite* sprite , bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec;
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	float tileTop = tile.getGlobalBounds().top ;
	float tileBottom = tileTop + tile.getGlobalBounds().height -8;
	float tileLeft = tile.getGlobalBounds().left + 3; // `+3` to fix player sprite's empty spaces in side creating bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 6;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft > spriteLeft
		&& tileLeft < spriteRight
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop
		)  return tileLeft;

	return -1;
}

int Brick::checkLeftCollision(sf::Sprite* sprite , bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec;
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	float tileTop = tile.getGlobalBounds().top;
	float tileBottom = tileTop + tile.getGlobalBounds().height -8;
	float tileLeft = tile.getGlobalBounds().left + 3; // `+3` to fix player sprite's empty spaces in side creating bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 6;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileRight < spriteRight
		&& tileRight > spriteLeft
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop
		)  return tileRight;

	return -1;
}

int Brick::checkDownCollision(sf::Sprite* sprite , bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec;
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	float tileTop = tile.getGlobalBounds().top;
	float tileBottom = tileTop + tile.getGlobalBounds().height;
	float tileLeft = tile.getGlobalBounds().left + 6; // `+6` for right - left collision bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 12;

	if (tileRight > spriteLeft
		&& tileLeft < spriteRight
		&& tileTop <= spriteBottom
		&& tileTop > spriteTop
		&& tileBottom > spriteBottom
		)  return tileTop;
	
	return -1;
}

int Brick::checkUpCollision(sf::Sprite* sprite, bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec;
	float spriteLeft = sprite->getGlobalBounds().left;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width;

	float tileTop = tile.getGlobalBounds().top;
	float tileBottom = tileTop + tile.getGlobalBounds().height;
	float tileLeft = tile.getGlobalBounds().left + 6;   // `+6` for right - left collision bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 12;
	


	if (tileRight > spriteLeft
		&& tileLeft < spriteRight
		&& tileBottom >= spriteTop
		&& tileBottom < spriteBottom
		&& tileTop < spriteTop
		) {
		if (isBig) {
			breakIt = true;
		}
		else {
			bounce = true;
		}
		return tileBottom;
	}
	return -1;
}

sf::Vector2f Brick::getStartPos()
{
	return tile.getPosition();
}

sf::Vector2f Brick::getEndPos()
{
	return tile.getPosition() + sf::Vector2f( tile.getGlobalBounds().width ,0);
}

void Brick::draw(sf::RenderWindow* window)
{
	breakBounce();

	window->draw(tile);
	window->draw(topLeft);
	window->draw(topRight);
	window->draw(bottomLeft);
	window->draw(bottomRight);
}
