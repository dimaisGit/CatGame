#include "Button.h"
Button::Button(
	const Vector2f& position,
	string outString,
	short padding,
	string pathToOnHoverSound,
	string pathToClickSound,
	string pathToFont,
	short fontSize,
	Color backgroundColor,
	Color textColor,
	Color backgroundOnHoverColor,
	Color textOnHoverColor
)
{
	this->position = position;
	this->padding = padding;
	this->fontSize = fontSize;
	this->outString = outString;
	this->backgroundColor = backgroundColor;
	this->textColor = textColor;
	this->backgroundOnHoverColor = backgroundOnHoverColor;
	this->textOnHoverColor = textOnHoverColor;
	this->onHoverSoundWasPlayed = false;
	this->clickDelay = 400;
	this->onHoverSoundBuffer.loadFromFile(pathToOnHoverSound);
	this->onHoverSound = Sound(this->onHoverSoundBuffer);
	this->isButtonClicked = false;


	this->onClickSoundBuffer.loadFromFile(pathToClickSound);
	this->onClickSound = Sound(this->onClickSoundBuffer);

	this->font.loadFromFile(pathToFont);
	this->textForButton = Text(this->outString, this->font, this->fontSize);
	this->textForButton.setPosition(position.x + padding, position.y + padding);
	this->textForButton.setColor(this->textColor);

	this->background.setPosition(position);
	this->background.setSize(Vector2f(
		this->textForButton.getLocalBounds().width + padding * 2,
		this->textForButton.getLocalBounds().height + padding * 2
	));
	this->background.setFillColor(this->backgroundColor);
}

void Button::draw(RenderWindow& window) const
{
	window.draw(this->background);
	window.draw(this->textForButton);
}

bool Button::isMouseInArea(const FloatRect& area, const RenderWindow& window, const Camera& camera) const
{
	return area.contains(Vector2f(
		Mouse::getPosition(window).x + camera.getCenter().x - camera.getSize().x / 2,
		Mouse::getPosition(window).y + camera.getCenter().y - camera.getSize().y / 2
	));
}

void Button::update(const RenderWindow& window, const Camera& camera)
{
	if (isMouseInArea(background.getGlobalBounds(), window, camera))
	{
		background.setFillColor(backgroundOnHoverColor);
		textForButton.setColor(textOnHoverColor);
		if (!onHoverSoundWasPlayed)
		{
			onHoverSound.play();
			onHoverSoundWasPlayed = true;
		}
		if (Mouse::isButtonPressed(Mouse::Left) && clickTimer.getElapsedTime().asMilliseconds() > clickDelay)
		{
			isButtonClicked = true;
			onClickSound.play();
			clickTimer.restart();
		}

	}
	else
	{
		onHoverSoundWasPlayed = false;
		background.setFillColor(backgroundColor);
		textForButton.setColor(textColor);
	}
}

bool Button::isClicked()
{
	if (isButtonClicked)
	{
		isButtonClicked = false;
		return true;
	}
	else
		return false;
}

Button::~Button()
{

}