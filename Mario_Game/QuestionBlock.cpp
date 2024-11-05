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
	if (!Hitten) {
		if (clock.getElapsedTime().asMilliseconds() >= 200) {
			if (prevCol == 15) colRight = true;
			if (prevCol == 17) colRight = false;

			if (colRight) prevCol++;
			if (!colRight) prevCol--;

			tile.setTextureRect(sf::IntRect(prevCol * 32, 7 * 32, 32, 32));
			clock.restart();
		}
	}
}

void QuestionBlock::powerAnimation(Map* map, float delta)
{
	if (powerUp.getPosition().y > tile.getPosition().y - 32 && !cpCameOut)
	{
		cpCameOut = false;
		powerSpeedY = -50;
		powerSpeedX = 0;
	}
	else {
		if (!cpCameOut) {
			cpCameOut = true;
			powerSpeedX = 100;
		}

		bool jumped = false;

		int resDown = map->checkDownCollision(&powerUp , false);
		if (resDown > -1) {
			powerUp.setPosition(powerUp.getPosition().x, resDown - 32);
			if (resDown< prevFloor) 
			{
				jumped = true;
				powerSpeedY = -200;
				powerSpeedX *= -1;
			}
			else powerSpeedY = 0;	
			
			prevFloor = resDown;
		}
		else powerSpeedY += 1000*delta;
		

		int resRight = map->checkRightCollision(&powerUp , false);
		if (resRight > -1 && !jumped) powerSpeedX = -100;
		

		int resLeft = map->checkLeftCollision(&powerUp , false , false);
		if (resLeft > -1 && !jumped) powerSpeedX = 100;
		
	}
	powerUp.move(powerSpeedX * delta, powerSpeedY * delta);

	if (cpAnimation.getElapsedTime().asMilliseconds() >= 200) {
		cpCol = cpCol == 18 ? 19 : 18;
		powerUp.setTextureRect(sf::IntRect(cpCol * 32, 6 * 32, 32, 32));
		cpAnimation.restart();
	}
}

void QuestionBlock::coinAnimation(float delta)
{
	if (!cpCameOut) {
		if (coin.getPosition().y > tile.getPosition().y - 70 && !cpCameOut) coin.move(0, -200 * delta);
		else cpCameOut = true;
	}
	else if (coin.getPosition().y < tile.getPosition().y) coin.move(0, 200 * delta);
	else coin = sf::Sprite();
	
	if (cpAnimation.getElapsedTime().asMilliseconds() >= 50) {
		cpCol = cpCol > 18 ? 14 : cpCol + 1;
		coin.setTextureRect(sf::IntRect(cpCol * 32, 4 * 32, 32, 32));
		cpAnimation.restart();
	}

}

QuestionBlock::QuestionBlock(sf::Texture& texture, float x, float y, bool canPower) :
	colRight(true),
	containPower(canPower),
	cpCol(14),
	prevCol(15),
	isBouncing(false),
	bounce(false),
	powerSpeedX(0),
	powerSpeedY(0),
	Hitten(false),
	cpCameOut(false),
	prevFloor(0)
{
	tile.setTexture(texture);
	tile.setTextureRect(sf::IntRect(prevCol * 32, 7 * 32, 32, 32));
	tile.setPosition(x * 32, y * 32);

	if (canPower) {
		cpCol = 18;
		powerUp.setTexture(texture);
		powerUp.setTextureRect(sf::IntRect(cpCol * 32, 6 * 32, 32, 32));
		powerUp.setPosition(x * 32, y * 32);
	}
	else {
		coin.setTexture(texture);
		coin.setTextureRect(sf::IntRect(cpCol * 32, 4 * 32, 32, 32));
		coin.setPosition(x * 32, y * 32);
	}
}

int QuestionBlock::checkRightCollision(sf::Sprite* sprite, bool isBig)
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
	float tileBottom = tileTop + tile.getGlobalBounds().height - 8;
	float tileLeft = tile.getGlobalBounds().left + 3; // `+3` to fix player sprite's empty spaces in side creating bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 6;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft > spriteLeft
		&& tileLeft <= spriteRight
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop
		) return tileLeft;

	return -1;
}

int QuestionBlock::checkLeftCollision(sf::Sprite* sprite, bool isBig)
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
	float tileBottom = tileTop + tile.getGlobalBounds().height - 8;
	float tileLeft = tile.getGlobalBounds().left + 3; // `+3` to fix player sprite's empty spaces in side creating bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 6;


	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileRight < spriteRight
		&& tileRight >= spriteLeft
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop
		) return tileRight;

	return -1;
}


int QuestionBlock::checkDownCollision(sf::Sprite* sprite, bool isBig)
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
		) return tileTop;
	
	return -1;
}

int QuestionBlock::checkUpCollision(sf::Sprite* sprite, bool isBig)
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
	float tileLeft = tile.getGlobalBounds().left + 6; // `+6` for right-left collision bug
	float tileRight = tileLeft + tile.getGlobalBounds().width - 12;

	if (tileRight > spriteLeft
		&& tileLeft < spriteRight
		&& tileBottom >= spriteTop
		&& tileBottom < spriteBottom
		&& tileTop < spriteTop
		) {
		if (!Hitten) {
			bounce = true;
			Hitten = true;
		}
		return tileBottom;
	}
	return -1;
}

bool QuestionBlock::checkPowerUp(sf::Sprite* sprite)
{
	if (containPower && cpCameOut && powerUp.getGlobalBounds().intersects(sprite->getGlobalBounds())) {
		powerUp = sf::Sprite();
		return true;
	}

	return false;
}

void QuestionBlock::draw(sf::RenderWindow* window, float delta, Map* map)
{
	blockAnimation();
	if (Hitten) {
		if (!containPower) coinAnimation(delta);
		else powerAnimation(map, delta);
	}

	window->draw(powerUp);
	window->draw(coin);
	window->draw(tile);
}

sf::Vector2f QuestionBlock::getStartPos()
{
	return tile.getPosition(); ;
}

sf::Vector2f QuestionBlock::getEndPos()
{
	return tile.getPosition() + sf::Vector2f(tile.getGlobalBounds().width, 0);
}

