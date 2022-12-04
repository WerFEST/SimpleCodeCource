#include "Human.h"
#include <iostream>

int Human::ID = 0;		//Объявление статической переменной

Human::Human()
{
	age = 0;
	name = "No Name";
	ID++;
	humanID = ID;
}

Human::Human(int age, std::string name)
{
	this->age = age;
	this->name = name;
	ID++;
	this->humanID = ID;
	std::cout << this << std::endl;
}

Human::Human(std::string name)
{
	this->name = name;
	this->age = 0;
}

Human::Human(std::string name, int age)
{
	this->age = age;		//Name берётся из констуктора Human(name);
}

Human::~Human()
{
	std::cout << "Destructor" << this << std::endl;
}

Human::Human(const Human& other)
{
	this->name = other.name;
	this->age = other.age;
	std::cout << "Copy Constructor" << this << std::endl;
}

Human& Human::operator=(const Human& other)
{
	this->name = other.name;
	this->age = other.age;
	std::cout << "Operator =" << this << std::endl;
	
	return *this;
}

void Human::PrintInfo()
{
	std::cout << "Name: " << name << "\tAge: " << age << std::endl;
}

void Human::SetAge(int valueAge)
{
	age = valueAge;
}

void Human::SetName(std::string name)
{
	this->name = name;
}

std::string Human::GetName()
{
	return name;
}

int Human::GetAge()
{
	return age;
}

int Human::GetID()
{
	return humanID;
}

//void Human::TakeApple(Apple& apple)
//{
//	std::cout << "Take Apple " << std::endl << "Weight: " << apple.weight << "\tColor: " << apple.color << std::endl;
//}
