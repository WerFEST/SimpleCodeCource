#include "Apple.h"

int Apple::count = 0;       //Объявление статической переменной

Apple::Apple(int weight, std::string color)
{
	this->weight = weight;
	this->color = color;
	count++;
}

int Apple::GetCount()
{
	return count;
}

void Apple::ChangeColor(Apple& apple, std::string color)
{
	apple.color = color;
}

void Apple::ChangeColorNoStatic(std::string color)
{
	this->color = color;
}


