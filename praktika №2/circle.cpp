#define _USE_MATH_DEFINES
#include "circle.h"
#include <cmath>


Circle::Circle(float r, float x, float y)
	: radius(r), x_center(x), y_center(y)
{
}

void Circle::set_circle(float r, float x, float y)
{
	radius = r;
	x_center = x;
	y_center = y;
}

float Circle::square() const 
{
	return M_PI * pow(radius, 2);
}

bool Circle::triangle_around(float a, float b, float c) const 
{
	float p = (a + b + c) / 2;
	float r = (a * b * c) / (4 * square());
	return (r <= (p - a) && r <= (p - b) && r <= (p - c));
}
bool Circle::triangle_in(float a, float b, float c) const
{
	float r = (a * b * c) / (4 * square());
	return (r <= radius);
}
bool Circle::check_circle(float r, float x_cntr, float y_cntr) const 
{
	float d = sqrt((x_cntr - x_center) * (x_cntr - x_center) + (y_cntr - y_center) * (y_cntr - y_center));
	return (d <= (r + radius));
}
