#include "Image.h"

void Image::GetImageInfo()
{
	for (int i = 0; i < LENGTH; i++)
	{
		//Обращаемся к каждому объекту массива объектов
		std::cout << pixels[i].GetInfo() << std::endl;
	}
}
