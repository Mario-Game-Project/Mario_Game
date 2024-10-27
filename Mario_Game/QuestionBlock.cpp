#include "QuestionBlock.h"
#include "Map.h"
#include <iostream>

void QuestionBlock::blockAnimation()
{
	if (bounce && clock.getElapsedTime().asMilliseconds() >= 100) {

		if (!isBouncing) {
			tile.move(0, -5);
			isBouncing = true;
			tile.setTextureRect(sf::IntRect(18 * 32, 7 * 32, 32, 32));
		}
		else {
			tile.move(0, 5);
			isBouncing = false;
			bounce = false;

		}
		clock.restart();
	}
	if (!hadHitted) {
		if (clock.getElapsedTime().asMilliseconds() >= 200) {
			if (prevX == 15) forward = true;
			if (prevX == 17) forward = false;

			if (forward) prevX++;
			if (!forward) prevX--;

			tile.setTextureRect(sf::IntRect(prevX * 32, 7 * 32, 32, 32));
			clock.restart();
		}
	}
}

void QuestionBlock::powerAnimation(Map* map, float delta)
{
	if (powerUp.getPosition().y > tile.getPosition().y - 32 && !pCameOut)
	{
		pCameOut = false;
		powerSpeedY = -50;
		powerSpeedX = 0;
	}
	else {
		if (!pCameOut) {
			pCameOut = true;
			powerSpeedX = 100;
		}

		int resDown = map->checkDownCollision(&powerUp);
		if (resDown > -1) {
			powerUp.setPosition(powerUp.getPosition().x, resDown - 32);
			powerSpeedY = 0;
		}
		else {
			powerSpeedY = 300;
		}

		int resRight = map->checkRightCollision(&powerUp);
		if (resRight > -1) {
			powerSpeedX = -100;
		}

		int resLeft = map->checkLeftCollision(&powerUp);
		if (resLeft > -1) {
			powerSpeedX = 100;
		}
	}
	powerUp.move(powerSpeedX * delta, powerSpeedY * delta);

	if (cpAnimation.getElapsedTime().asMilliseconds() >= 200) {
		cpX = cpX == 18 ? 19 : 18;
		powerUp.setTextureRect(sf::IntRect(cpX * 32, 6 * 32, 32, 32));
		cpAnimation.restart();
	}
}

void QuestionBlock::coinAnimation(float delta)
{
	if (coin.getPosition().y > tile.getPosition().y - 70)
	{
		coin.move(0, -200 * delta);
		if (cpAnimation.getElapsedTime().asMilliseconds() >= 100) {
			cpX = cpX > 18 ? 14 : cpX + 1;
			coin.setTextureRect(sf::IntRect(cpX * 32, 4 * 32, 32, 32));
			cpAnimation.restart();
		}
	}
	else coin = sf::Sprite();

}

QuestionBlock::QuestionBlock(sf::Texture& texture, float x, float y, bool canPower) :
	forward(true),
	containPower(canPower),
	cpX(14),
	prevX(15),
	isBouncing(false),
	bounce(false),
	powerSpeedX(0),
	powerSpeedY(0),
	hadHitted(false),
	pCameOut(false)
{
	tile.setTexture(texture);
	tile.setTextureRect(sf::IntRect(prevX * 32, 7 * 32, 32, 32));
	tile.setPosition(x * 32, y * 32);

	if (canPower) {
		cpX = 18;
		powerUp.setTexture(texture);
		powerUp.setTextureRect(sf::IntRect(cpX * 32, 6 * 32, 32, 32));
		powerUp.setPosition(x * 32, y * 32);
	}
	else {
		coin.setTexture(texture);
		coin.setTextureRect(sf::IntRect(cpX * 32, 4 * 32, 32, 32));
		coin.setPosition(x * 32, y * 32);
	}
}

int QuestionBlock::checkRightCollision(sf::Sprite* sprite)
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

int QuestionBlock::checkLeftCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top ;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
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

int QuestionBlock::checkDownCollision(sf::Sprite* sprite)
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

int QuestionBlock::checkUpCollision(sf::Sprite* sprite, bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - 2 * topDec;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	float tileTop = tile.getGlobalBounds().top + tile.getGlobalBounds().height / 2.0;
	float tileBottom = tileTop + tile.getGlobalBounds().height / 2.0;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileBottom > spriteTop
		&& tileTop <= spriteBottom
		&& tileRight > spriteLeft
		&& tileLeft < spriteRight
		) {
		if (!hadHitted) {
			bounce = true;
			hadHitted = true;
		}

		return tileBottom;
	}
	return -1;
}

bool QuestionBlock::checkPowerUp(sf::Sprite* sprite)
{
	if (containPower && pCameOut && powerUp.getGlobalBounds().intersects(sprite->getGlobalBounds())) {
		powerUp = sf::Sprite();
		return true;
	}

	return false;
}

void QuestionBlock::draw(sf::RenderWindow* window, float delta, Map* map)
{
	blockAnimation();
	if (hadHitted) {
		if (!containPower) coinAnimation(delta);
		else powerAnimation(map, delta);
	}

	window->draw(powerUp);
	window->draw(coin);
	window->draw(tile);
}

void QuestionBlock::collide(sf::Sprite&)
{

}

