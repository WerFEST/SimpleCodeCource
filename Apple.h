#pragma once
#include <string>
#include "Human.h"

class Apple
{
private:
	int weight;
	std::string color;
	static int count;											//Статическое поле класса
	friend class Human;

public:
	Apple(int weight, std::string color);
	static int GetCount();
	static void ChangeColor(Apple& apple, std::string color);	//Статический метод класса
	void ChangeColorNoStatic(std::string color);				//Нестатический метод класса
	//friend void Human::TakeApple(Apple& apple);					//Дружественный метод класса

};