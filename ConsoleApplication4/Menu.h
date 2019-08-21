#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Camera.h"
class Menu
{
private:
	Button *playButton;
	bool isMenuOpen;
public:
	void update(const RenderWindow& window, const Camera& camera);
	void close();
	void draw(RenderWindow& window) const;

	//accessors
	bool isOpen() const;


	//cons(des)tructors
	Menu(const Camera& camera);
	~Menu();
};

