#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
	Circle(float r, float x, float y);
	void set_circle(float r, float x, float y);
	float square() const;
	bool triangle_around(float a, float b, float c) const;
	bool triangle_in(float a, float b, float c) const;
	bool check_circle(float r, float x_cntr, float y_cntr) const;

private:
	float radius;
	float x_center;
	float y_center;
}; 
#endif
