#include "Castle.h"

Castle::Castle(sf::Texture& texture, float x, float y)
{
	castle.setTexture(texture);
	castle.setPosition(x*32, y*32);
	castle.setTextureRect(sf::IntRect(0, 13*32, 12*32, 10*32));
}


sf::Vector2f Castle::getPosition()
{
	return castle.getPosition();
}

bool Castle::castleDoor(sf::Sprite* sprite)
{
	return sprite->getGlobalBounds().left >= castle.getGlobalBounds().left + (32 * 5);
}

void Castle::draw(sf::RenderWindow* window)
{
	window->draw(castle);
}
