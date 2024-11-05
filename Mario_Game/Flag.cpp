#include "Flag.h"

Flag::Flag(sf::Texture& texture, float tileX, float tileY, int height):
	poleCollided(false)
{
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// base :
	sprite.setTextureRect(sf::IntRect(13*32, 16*32, 32, 32));
	sprite.setPosition(tileX * 32, tileY * 32);
	pole.push_back(sprite);

	// pole :
	for (int i = 1; i < height; i++)
	{
		sprite.setTextureRect(sf::IntRect(13*32, 15*32, 32, 32));
		sprite.setPosition(tileX * 32, (tileY - i) * 32);
		pole.push_back(sprite);
	}

	// ball : 
	sprite.setTextureRect(sf::IntRect(13*32, 13*32, 32, 32));
	sprite.setPosition(tileX * 32, (tileY - height) * 32);
	pole.push_back(sprite);

	// flag :
	flag.setTexture(texture);
	flag.setTextureRect(sf::IntRect(14*32, 14*32, 32, 32));
	flag.setPosition((tileX * 32 ) + 20, (tileY - height + 1) * 32);
}

int Flag::checkPoleCollision(sf::Sprite* sprite)
{
	for(int i = 0; i < pole.size(); i++)
	{
		sf::Sprite tile = pole.at(i);
		if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())) 
		{
			poleCollided = true;
			return tile.getGlobalBounds().left + 8;
		}
	}
	return -1;
}

sf::Vector2f Flag::getPosition()
{
	return flag.getPosition();
}

void Flag::draw(sf::RenderWindow* window ,float delta)
{
	if (poleCollided && flag.getPosition().y < pole[1].getPosition().y) flag.move(0, 200 * delta);

	for(sf::Sprite tile : pole) window->draw(tile);
	window->draw(flag);
}
