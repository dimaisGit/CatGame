#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "Camera.h"
#include "Button.h"
#include "Menu.h"
using namespace sf;
using std::cout;
using std::endl;
using std::string;
double tileSize = 64;


void pollEvent(RenderWindow& window);
void handleMenu(const Camera& camera, RenderWindow& window);

int main()
{
	Vector2i windowSize(1200, 700);
	RenderWindow window(VideoMode(windowSize.x, windowSize.y), "SFML works!");

	Player player;
	Camera camera(windowSize);
	Clock clock;
	double elapsedTimeAsSeconds;
	Menu menu(camera);
	while (window.isOpen())
	{
		elapsedTimeAsSeconds = clock.getElapsedTime().asMicroseconds() / 1000000.0;
		clock.restart();
		pollEvent(window);
		handleMenu(camera, window);
		camera.update(player.getPosition(), elapsedTimeAsSeconds);
		player.update(elapsedTimeAsSeconds);
		window.setView(camera);
		window.clear();
		window.display();
	}

	return 0;
}

void pollEvent(RenderWindow& window)
{
	Event e;
	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
			window.close();
	}
}

void handleMenu(const Camera& camera, RenderWindow& window)
{
	Menu menu(camera);
	while (menu.isOpen())
	{
		menu.update(window, camera);
		window.clear();
		menu.draw(window);
		window.display();
		pollEvent(window);
	}
}