#include <SFML/Graphics.hpp>
#include "sprites.h"

#define WINDOW_X 800
#define WINDOW_Y 600

Entity::Entity(sf::Texture & texture){
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	animationDelay = 1000;
	spriteCounter = 0;
}
void Entity::draw(sf::RenderWindow & window){
	window.draw(sprite);
}
void Entity::setDimentions(const int & x, const int & y){
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
	spriteCounter = 0;
}
void Entity::animate(int direction){
	sprite.setTextureRect(sf::IntRect(spriteCounter/animationDelay * spriteWidth, spriteHeight * direction, spriteWidth, spriteHeight));
	++spriteCounter;
	counterReset();
}
Player::Player(sf::Texture & texture, int hitPoints, float movementSpeed) : Entity(texture) {
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
