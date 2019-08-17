#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;
using namespace sf;

class Player
{
private:
	enum PlayerDirections : char
	{
		STAYING,
		RIGHT_DIRECTION,
		LEFT_DIRECTION
	};
	enum AnimationStates
	{
		staying,
		moveRight,
		moveLeft,
		jump,
		fight
	};
	Vector2f position;
	IntRect size;//rectangle
	Vector2f speed;
	Vector2f maxSpeed;
	Vector2f applyingAcceleration;// x for horizontal y for vertical (g)
	PlayerDirections direction;
	AnimationStates animationState;

	bool onGround;
	short speedForJump; // jump speed boost
	int floor;

	bool rightKey() const;
	bool leftKey() const;
	bool jumpKey() const;

	void applyJump();
	void switchDirection(PlayerDirections direction);
	void checkKeyboard();
public:
	Player();
	~Player();
	void update(double elapsedTimeAsSeconds);
	const Vector2f& getPosition() const;
	const Vector2f& getSpeed() const;
};

