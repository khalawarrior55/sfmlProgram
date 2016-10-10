#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "sprites.h"

// This is the top of the program
// Random Comment

using namespace std;

#define WINDOW_X 800
#define WINDOW_Y 600

/*
class ricky{
	int hitPoints;
	float movementSpeed;
	sf::Sprite sprite;
	sf::Vector2f pos;
	int spriteCounter;
	int delayCounter;

public:
	ricky(sf::Texture & texture, int hitPoints = 100, float movementSpeed = .005){
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		this->hitPoints = hitPoints;
		this->movementSpeed = movementSpeed;
		pos = sprite.getPosition();
		spriteCounter = 0;
		delayCounter = 1000;
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));

	}
	void control(){
		// Gets the position of the sprite
		getPos();
		// Moves sprite down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos.y < WINDOW_Y){
			sprite.move(0, movementSpeed);
			animateDown();
			}

		// Moves sprite up
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pos.y >= 0){
			sprite.move(0, -movementSpeed);
			animateUp();
			}	

		// Moves sprite left
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pos.x >= 0){
			sprite.move(-movementSpeed, 0);
			animateLeft();
			}

		// Moves sprite right
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pos.x < WINDOW_X){
			sprite.move(movementSpeed, 0);
			animateRight();
			}

		// Returns sprite to (0, 0)
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			sprite.setPosition(0,0);
			}

	}
	void draw(sf::RenderWindow & window){

		window.draw(sprite);		
	}
	void counterReset(){
		if (spriteCounter/delayCounter >= 12)
			spriteCounter = 0;
	}
	void getPos(){
		pos = sprite.getPosition();
	}
	void animateDown(){
		sprite.setTextureRect(sf::IntRect(spriteCounter/delayCounter * 32, 0, 32, 32));
		++spriteCounter;
		counterReset();
	}
	void animateUp(){
		sprite.setTextureRect(sf::IntRect(spriteCounter/delayCounter * 32, 96, 32, 32));
		++spriteCounter;
		counterReset();
	}
	void animateRight(){
		sprite.setTextureRect(sf::IntRect(spriteCounter/delayCounter * 32, 64, 32, 32));
		++spriteCounter;
		counterReset();
	}
	void animateLeft(){
		sprite.setTextureRect(sf::IntRect(spriteCounter/delayCounter * 32, 32, 32, 32));
		++spriteCounter;
		counterReset();
	}


};
*/
// Draws all entities loaded
void drawLoop(sf::RenderWindow & window, vector<Player> & vec, vector<sf::Sprite> & sprites){
	int counter = 0;
	for(int i = 0; i < sprites.size(); ++i){
		window.draw(sprites[counter]);
	}
	for(int i = 0; i < vec.size(); ++i){
		vec[counter].draw(window);
	}
}

int main()
{
    // Create the main window
    static sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Riqukey RINEHOLDS tha vidiagame");
    // Load a texture for sprites
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
	sf::Texture grass;
	if (!grass.loadFromFile("truck.jpg"))
		return EXIT_FAILURE;
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("lol fuck you", font, 50);
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("bluegrassBanjo.wav"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
	// Entity Holder
	vector<Player> entities;
	// Instantiates player
	Player player(texture, 32.0, 32.0);
	entities.push_back(player);
	Player * playerP = &entities[0];	
	// Spawns background grass
	sf::Sprite background;
	background.setTexture(grass);
	background.setPosition(0, 0);
	vector<sf::Sprite> sprites;
	sprites.push_back(background);
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

			// Close window: Escape pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
        }
        // Clear screen
        window.clear();

		// Scans inputs
		playerP->control();
		// Draws Entities
		drawLoop(window, entities, sprites);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
