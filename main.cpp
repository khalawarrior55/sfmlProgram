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
	Player player(texture, 12, 32.0, 32.0);
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
