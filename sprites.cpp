#include <SFML/Graphics.hpp>
#include <iostream>
#include "sprites.h"

#define WINDOW_X 800
#define WINDOW_Y 600

using namespace std;

Entity::Entity(const sf::Texture & texture, const int & spriteFrames , const float & xDimension, const float & yDimension){
	sprite.setTexture(texture);
    spriteWidth = xDimension;
    spriteHeight = yDimension;
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(0, 0);
	animationDelay = 1000;
	spriteCounter = 0;
	this->spriteFrames = spriteFrames;
};
void Entity::draw(sf::RenderWindow & window){
	window.draw(sprite);
}
void Entity::setDimentions(const float & x, const float & y){
	this->spriteWidth = x;
	this->spriteHeight = y;
}
void Entity::getPos(){
	pos = sprite.getPosition();
}
void Entity::setPos(const float & x, const float & y){
	sprite.setPosition(x, y);
}
void Entity::counterReset(){
    if (spriteCounter/animationDelay >= 12)
	    spriteCounter = 0;
}
void Entity::animate(const int & direction){
	sprite.setTextureRect(sf::IntRect(spriteCounter / animationDelay * spriteWidth, spriteHeight * direction, spriteWidth, spriteHeight));
	++spriteCounter;
	counterReset();
}
Player::Player(const sf::Texture & texture, const int & spriteFrames, const float & xDimension, const float & yDimension, const int & hitPoints, const float & movementSpeed)
    : Entity(texture, spriteFrames, xDimension, yDimension) {
	this->hitPoints = hitPoints;
	this->movementSpeed = movementSpeed;
}
void Player::control(){
	getPos();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos.y < WINDOW_Y){
		sprite.move(0, movementSpeed);
		animate(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pos.x >=0){
		sprite.move(-movementSpeed, 0);
		animate(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pos.x < WINDOW_X){
		sprite.move(movementSpeed, 0);
		animate(2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pos.y >= 0){
		sprite.move(0, -movementSpeed);
		animate(3);
	}
}
