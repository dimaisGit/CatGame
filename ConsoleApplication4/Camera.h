#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Camera : public View
{
private:
	double speed;
	double offset;
public:
	Camera(const Vector2i& windowSize);
	~Camera();
	void update(const Vector2f& playerPosition, double elapsedTimeAsSeconds);
};

