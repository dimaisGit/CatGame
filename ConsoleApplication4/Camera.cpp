#include "Camera.h"

Camera::Camera(const Vector2i& windowSize)
{
	this->reset(FloatRect(0, 0, windowSize.x, windowSize.y));
	speed = 300;
	offset = 300;
}

Camera::~Camera()
{

}

void Camera::update(const Vector2f& playerPosition, double elapsedTimeAsSeconds)
{
	Vector2f position = this->getCenter();

	double speedOffset = speed * elapsedTimeAsSeconds;
	if (float(position.x) - playerPosition.x > offset)
		this->setCenter(playerPosition.x + offset, position.y);
	else if (float(position.x) - playerPosition.x < -offset)
		this->setCenter(playerPosition.x - offset, position.y);
	else
	{
		if (position.x + speedOffset < playerPosition.x)
			this->move(speedOffset, 0);
		else if (position.x - speedOffset > playerPosition.x)
			this->move(-speedOffset, 0);

	}
	if (position.y + speedOffset < playerPosition.y)
		this->move(0, speedOffset);
	else if (position.y - speedOffset > playerPosition.y)
		this->move(0, -speedOffset);
}