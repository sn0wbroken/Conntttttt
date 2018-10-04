#include "Vector2D.h"



Vector2D::Vector2D()
{
}


Vector2D::~Vector2D()
{
}

void Vector2D::Move(float set_x, float set_y) {
	x += set_x;
	y += set_y;
}

// ”z’u
void Vector2D::Arrange(float set_x, float set_y) {
	x = set_x;
	y = set_y;
}
