#ifndef _SPRITES_H
#define _SPRITES_H

class Entity
{
protected:
	sf::Sprite sprite;
	sf::Vector2f pos;
	float spriteWidth;
	float spriteHeight;
	int spriteCounter;
	int animationDelay;
public:
	Entity(sf::Texture & texture, float xDimension, float yDimension);
	void draw(sf::RenderWindow & window);
	void setDimentions(const float & x, const float & y);
	void getPos();
	void setPos(const float & x, const float & y);
	void counterReset();
	void animate(int direction);
};

class Player: public Entity
{
protected:
	int hitPoints;
	float movementSpeed;
public:
	Player(sf::Texture & texture, float xDimension, float yDimension, int hitPoints = 100, float movementSpeed = .01);
	void control();

};
#endif
