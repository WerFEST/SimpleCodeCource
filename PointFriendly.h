#pragma once

#include "Point.h"

inline void ChangeX(Point& value)
{
	value.x = 0;
}

inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << point.x << " " << point.y;
	return os;
}

inline std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point.x >> point.y;
	return is;
}
