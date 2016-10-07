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
	Entity(sf::Texture & texture);
	void draw(sf::RenderWindow & window);
	void setDimentions(const int & x, const int & y);
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
	Player(sf::Texture & texture, int hitPoints = 100, float movementSpeed = .001);
	void control();

};
#endif
