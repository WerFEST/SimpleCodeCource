#pragma once
#ifndef _PIXEL_H_
#define _PIXEL_H_


#include <string>

class Pixel
{
private:
	int r;
	int g;
	int b;
public:
	Pixel(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}


	std::string GetInfo();
};


#endif // !_PIXEL_H_