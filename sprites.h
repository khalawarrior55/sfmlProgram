#ifndef _SPRITES_H
#define _SPRITES_H

class Entity
{
protected:
	sf::Sprite sprite; // Holds the sprite of the Entity
	sf::Vector2f pos; // Holds the position of the sprite relative to it's origin (Default: Top Left)
	float spriteWidth; // Width of the sprite in the texture
	float spriteHeight; // Height of the sprite in the texture
	int spriteCounter; // Counter that determines what frame the sprite is showing 
	int animationDelay; // Value that lengthens the time between each texture change
	int spriteFrames; // Number of frames in the texture for the sprite
public:
	Entity(const sf::Texture & texture, const int & spriteFrames, const float & xDimension, const float & yDimension);
	void draw(sf::RenderWindow & window);
	void setDimentions(const float & x, const float & y);
	void getPos();
	void setPos(const float & x, const float & y);
	void counterReset();
	void animate(const int & direction);
};

class Player: public Entity
{
protected:
	int hitPoints;
	float movementSpeed;
public:
	Player(const sf::Texture & texture, const int & spriteFrames, const float & xDimension, const float & yDimension, const int & hitPoints = 100, const float & movementSpeed = .01);
	void control();

};
#endif
