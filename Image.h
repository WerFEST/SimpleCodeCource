#pragma once
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include "Pixel.h"

class Image
{
private:

	static const int LENGTH = 5;
	Pixel pixels[LENGTH]				//Объект Pixel в виде массива
	{
		Pixel(0,4,65),
		Pixel(4,14,10),
		Pixel(111,4,24),
		Pixel(244,244,14),
		Pixel(111,179,64),
	};

public:
	void GetImageInfo();

};


#endif // !_IMAGE_H_
