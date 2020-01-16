#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	circle.setRadius(50);
	circle.setPosition(550,288);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2);

	smallRectangle.setSize(sf::Vector2f(10, 10));
	smallRectangle.setPosition(210,210);
	smallRectangle.setFillColor(sf::Color::Blue);

	mediumRectangle.setSize(sf::Vector2f(20, 20));
	mediumRectangle.setPosition(205,205);
	mediumRectangle.setFillColor(sf::Color::Green);

	largeRectangle.setSize(sf::Vector2f(30, 30));
	largeRectangle.setPosition(200,200);
	largeRectangle.setFillColor(sf::Color::Red);

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font.";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(24);
	text.setPosition(550, 0);

	cornerRectangle.setSize(sf::Vector2f(50, 50));
	cornerRectangle.setFillColor(sf::Color::Green);
	
	
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	bottomRightCorner = window->getSize();
	cornerRectangle.setPosition(bottomRightCorner.x-50, bottomRightCorner.y-50);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(circle);

	window->draw(largeRectangle);
	window->draw(mediumRectangle);
	window->draw(smallRectangle);

	window->draw(text);

	window->draw(cornerRectangle);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}