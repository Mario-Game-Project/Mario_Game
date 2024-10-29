#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
using namespace sf;
class Enemy
{
    Sprite enemySprite;
    Clock enemyClock;

    float enemySpeed_X;
    int col;
    int row;
    float gravity ;
    float enemySpeed_Y;
    int deadAnimeCounter;

public:
    bool isGrounded;
    bool enemyMovingRight;
    bool enemyDied;

    Enemy( sf::Texture* texture, int x , int y);
    void checkCollisionWithPlayer(Sprite& player);
    void update(float deltaTime);
    sf::Sprite* getSprite();
    void draw(sf::RenderWindow* window);
};