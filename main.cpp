#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

#define WINDOW_X 800
#define WINDOW_Y 600


class ricky{
	int hitPoints;
	float movementSpeed;
	sf::Sprite sprite;
	sf::Vector2f pos;
	int spriteCounter = 0;
	// static sf::Texture textureRicky;

public:
	ricky(sf::Texture & texture, int hitPoints = 100, float movementSpeed = .05){
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		this->hitPoints = hitPoints;
		this->movementSpeed = movementSpeed;
		pos = sprite.getPosition();
		sprite.setOrigin(80,80);

	}
	void control(){
		getPos();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos.y < WINDOW_Y){
			sprite.move(0, movementSpeed);
			animateDown();
			}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pos.y >= 0){
			sprite.move(0, -movementSpeed);
			}	

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pos.x >= 0){
			sprite.move(-movementSpeed, 0);
			}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pos.x < WINDOW_X){
			sprite.move(movementSpeed, 0);
			}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			sprite.setPosition(0,0);
			}

		sprite.setRotation(sprite.getRotation() + .001);
	}
	void draw(sf::RenderWindow & window){

		window.draw(sprite);		
	}

	void getPos(){
		pos = sprite.getPosition();
	}
	void animateDown(){
		sprite.setTextureRect(sf::IntRect(spriteCounter * 33, 0, 32 * (spriteCounter + 1), 32));
		++spriteCounter;
	}


};

// Draws all entities loaded
void drawLoop(sf::RenderWindow & window, vector<ricky> & vec){
	int counter = 0;
	for(int i = 0; i < vec.size(); ++i){
		vec[counter].draw(window);
	}
}

int main()
{
    // Create the main window
    static sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Riqukey RINEHOLDS tha vidiagame");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpeg"))
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
	vector<ricky> entities;
	// Instantiates player
	ricky player(texture);
	entities.push_back(player);
	ricky * playerP = &entities[0];	
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
		drawLoop(window, entities);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
