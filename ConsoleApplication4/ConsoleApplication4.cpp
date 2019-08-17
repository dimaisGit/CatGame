#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "Camera.h"
#include "Button.h"
using namespace sf;
using std::cout;
using std::endl;
using std::string;
double tileSize = 64;

string map1[9] =
{
	"00000000000000000000",
	"0------------------0",
	"0------------------0",
	"0------------------0",
	"0------------------0",
	"0------------------0",
	"0------------------0",
	"0------------------0",
	"00000000000000000000",
};


int main()
{
	Vector2i windowSize(1500, 800);
	RenderWindow window(VideoMode(windowSize.x, windowSize.y), "SFML works!");

	RectangleShape rect;
	rect.setSize(Vector2f(50, 50));
	rect.setFillColor(Color::White);

	RectangleShape tile;
	tile.setSize(Vector2f(tileSize, tileSize));

	Player player;
	Camera camera(windowSize);
	Button button(Vector2f(500, 500), "Hello citti");
	Clock clock;
	double elapsedTimeAsSeconds;
	while (window.isOpen())
	{
		elapsedTimeAsSeconds = clock.getElapsedTime().asMicroseconds() / 1000000.0;
		clock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		camera.update(player.getPosition(), elapsedTimeAsSeconds);
		player.update(elapsedTimeAsSeconds);
		rect.setPosition(player.getPosition());
		window.setView(camera);
		window.clear();
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < map1[0].size(); x++)
			{
				if (map1[y][x] == '0')
				{
					tile.setFillColor(Color::White);
					tile.setPosition(Vector2f(x * tileSize, y * tileSize));
					window.draw(tile);
				}
			}
		}
		if (button.isClicked())
		{
			cout << "lol\n";
		}
		button.update(window, camera);
		window.draw(rect);
		button.draw(window);
		window.display();
	}

	return 0;
}