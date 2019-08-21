#include "Player.h"
Player::Player()
{
	position = Vector2f(50, 100);
	size = IntRect(0, 0, 50, 50);
	speed = Vector2f(0, 0);
	maxSpeed = Vector2f(500, 500);
	applyingAcceleration = Vector2f(2000, 2000);
	direction = STAYING;
	animationState = staying;
	onGround = false;
	floor = 500;
	speedForJump = 600;

	idleTexture.loadFromFile("Sprites/idle.png");
}

Player::~Player()
{

}

bool Player::rightKey() const
{
	return Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D);
}

bool Player::leftKey() const
{
	return Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A);
}

bool Player::jumpKey() const
{
	return Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up);
}

void Player::applyJump()
{
	if (onGround)
	{
		onGround = false;
		speed.y = -speedForJump;
		position.y -= 5;
	}
}

void Player::checkKeyboard()
{
	if (jumpKey())
		applyJump();
	if (rightKey())
		switchDirection(RIGHT_DIRECTION);
	else if (leftKey())
		switchDirection(LEFT_DIRECTION);
	else
		switchDirection(STAYING);
}

void Player::switchDirection(PlayerDirections direction)
{
	this->direction = direction;
	switch (direction)
	{
	case STAYING:
		speed.x = 0;
		break;
	case RIGHT_DIRECTION:
		break;
	case LEFT_DIRECTION:
		break;
	}
}

void Player::update(double elapsedTimeAsSeconds)
{
	checkKeyboard();

	switch (direction)
	{
	case RIGHT_DIRECTION:
		if (maxSpeed.x >= speed.x)
			speed.x += applyingAcceleration.x * elapsedTimeAsSeconds;
		break;
	case LEFT_DIRECTION:
		if (maxSpeed.x >= abs(speed.x))
			speed.x -= applyingAcceleration.x * elapsedTimeAsSeconds;
		break;
	}

	if (!onGround)
		speed.y += applyingAcceleration.y * elapsedTimeAsSeconds;

	position.x += speed.x * elapsedTimeAsSeconds;
	if (position.y + size.height >= floor)
	{
		position.y = floor - size.height;
		onGround = true;
	}
	else
	{
		position.y += speed.y * elapsedTimeAsSeconds;
		onGround = false;
	}

}

const Vector2f& Player::getPosition() const
{
	return position;
}

const Vector2f& Player::getSpeed() const
{
	return speed;
}


