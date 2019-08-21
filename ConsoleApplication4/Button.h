#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Camera.h"
using namespace sf;
using std::string;
class Button
{
private:
	Vector2f position;
	Font font;
	short fontSize;
	short padding;
	SoundBuffer onHoverSoundBuffer;
	Sound onHoverSound;
	SoundBuffer onClickSoundBuffer;
	Sound onClickSound;
	bool onHoverSoundWasPlayed;
	bool onClickSoundWasPlayed;
	bool isButtonClicked;
	Clock clickTimer;
	int clickDelay;
	Text textForButton;
	string outString;
	RectangleShape background;
	Color backgroundColor;
	Color textColor;
	Color backgroundOnHoverColor;
	Color textOnHoverColor;

	void setPosition();
	bool isMouseInArea(const FloatRect& area, const RenderWindow& window, const Camera& camera) const;
public:
	void draw(RenderWindow& window) const;
	void update(const RenderWindow& window, const Camera& camera);
	void setCenter(const Camera& camera);
	
	bool isClicked();

	Button(
		const Vector2f& position,
		string outString,
		short padding = 15,
		string pathToOnHoverSound = "Sounds/onHoverSound.wav",
		string pathToClickSound = "Sounds/onClickSound.wav",
		string pathToFont = "Fonts/MeowFont.ttf",
		short fontSize = 20,
		Color backgroundColor = Color::White,
		Color textColor = Color::Black,
		Color backgroundOnHoverColor = Color::Black,
		Color textOnHoverColor = Color::White
	);
	~Button();
};

