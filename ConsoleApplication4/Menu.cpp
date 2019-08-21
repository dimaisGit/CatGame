#include "Menu.h"
Menu::Menu(const Camera& camera)
{
	isMenuOpen = true;
	playButton = new Button(Vector2f(500, 500), "Play");
	playButton->setCenter(camera);
}

void Menu::update(const RenderWindow& window, const Camera& camera)
{
	playButton->update(window, camera);
	if (playButton->isClicked())
		close();
}

bool Menu::isOpen() const
{
	return isMenuOpen;
}

void Menu::draw(RenderWindow& window) const
{
	playButton->draw(window);
}

void Menu::close()
{
	isMenuOpen = false;
}

Menu::~Menu()
{
	delete playButton;
}