#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::Print()
{
	std::cout << "X: " << this->x << "\t" << "Y: " << this->y << std::endl;
}

bool Point::operator==(const Point& other)
{
	/*if (this->x == other.x && this->y == other.y)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	//Choose a shortest code style:
	return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other)
{
	return !(this->x == other.x && this->y == other.y);
}

Point Point::operator+(const Point& other)
{
	Point result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;
	return result;
}

Point& Point::operator++()
{
	this->x++;
	this->y++;
	return *this;
}

Point& Point::operator++(int value)
{
	Point temp(*this);
	this->x++;
	this->y++;
	return temp;
}
