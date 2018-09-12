#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

int main()
{
	//------------------------------------------------------
	// Game Setup
	//------------------------------------------------------

	// Render window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);


	//------------------------------------------------------
	// End Game Setup
	//------------------------------------------------------




	//------------------------------------------------------
	// Game Loop
	//------------------------------------------------------

	// Runs every frame until the game window is closed 
	while (gameWindow.isOpen())
	{

		
		 // ----------------------------------------------------
	    // Input
	   // ------------------------------------------------------

		// Check for input 
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))

			// Check if the event is the closed event 
			if (gameEvent.type == sf::Event::Closed)
			{

			// close the game window
				gameWindow.close();
			}




		 //----------------------------------------------------
		// Update
	   //------------------------------------------------------


		 //----------------------------------------------------
		// Draw
	   //------------------------------------------------------

		// clear the window to a single colour 
		gameWindow.clear(sf::Color::Black);


		// Display the window contents on the screen 
		gameWindow.display();


	} // end of game while loop 

	// exit point for the program
	return 0;

} // end of main function
