#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
using namespace sf;
class Enemy
{
public:
    float enemySpeed = 85.0f;  // Adjust as needed for speed
    Texture enemytexture;
    Sprite enemysprite;
    int col = 0;
    Clock enemyclock;
    bool deadBool;
    int deadAnimeCounter = 0;
    //float leftLimit = 400.0f;   // The left boundary for enemy movement
    //float rightLimit = 600.0f;
    float gravity = 980.0f;
    bool enemydied = false;
    Vector2f enemyPosition = enemysprite.getPosition();
    bool enemyMovingRight = true;
    bool enemyMovingLeft = false;
    float verticalVelocity = 0.0f;
    bool isGrounded = false;
    bool enemymoving = true;
    void load();
    void pos(int x, int y);
    void applyGravity(float delta);
    void stopFalling();
    void update(float deltaTime);
    void checkCollisionWithPlayer(Sprite& player);
    void draw(sf::RenderWindow& window);
    sf::Sprite* getSprite();
    void deadanimation();
};