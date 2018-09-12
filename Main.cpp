#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include<cstdlib>
#include<ctime>
// end libraries

int main()
{
	//------------------------------------------------------
	// Game Setup
	//------------------------------------------------------

	// Render window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);
	
	// seed our random number generation
	srand(time(NULL));



	// Timer functionality 
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeLimit = sf::seconds(signalTimeLowerLimit);
	sf::Time timeTillSignal = sf::seconds(10.0f);
	sf::Clock gameClock;

	// Create Button Sprite		
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	// centre the sprite on the screen 
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);


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
	    //  Input
	   // ------------------------------------------------------

		// Check for input 
		sf::Event gameEvent;
		//Process events 
		while (gameWindow.pollEvent(gameEvent))
		{

			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				// check if we clicked the button
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					
					// we did!
					int range = (int)(signalTimeUpperLimit - signalTimeLowerLimit);
					float signalSeconds = rand() % range + signalTimeLowerLimit;
					timeTillSignal = sf::seconds(signalSeconds);
					
				}

			}
			
			
			// Check if the event is the closed event 
			if (gameEvent.type == sf::Event::Closed)
			{

				// close the game window
				gameWindow.close();

			} // end closed event 




		} // end input polling while loop 

		 // ----------------------------------------------------
		//  end Input
	   // ------------------------------------------------------

		 //----------------------------------------------------
		// Update
	   //------------------------------------------------------

		// Update game state
		sf::Time frameTime = gameClock.restart();

		//update our signal timer
		timeTillSignal = timeTillSignal - frameTime;
		if (timeTillSignal.asSeconds() <= 0.0f)
		{
			buttonSprite.setColor(sf::Color::Red);
		}
		
		

		 //----------------------------------------------------
		// Draw
	   //------------------------------------------------------
		


		// clear the window to a single colour 
		gameWindow.clear(sf::Color::Black);

		gameWindow.draw(buttonSprite);

		// Display the window contents on the screen 
		gameWindow.display();


	} // end of game while loop 

	// exit point for the program
	return 0;

} // end of main function
