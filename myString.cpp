#include "myString.h"
#include <cstring>
#include <iostream>

myString::myString()
{
	str = nullptr;
	length = 0;
}

myString::myString(const char* str)
{
	length = strlen(str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = '\0';
}

myString::~myString()
{
	delete[] this->str;
}

myString::myString(const myString& other)             //Конструктор копирования
{
	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';
}

myString::myString(myString&& other)             //Конструктор перемещения
{
	this->length = other.length;
	this->str = other.str;

	other.str = nullptr;
}

myString& myString::operator=(const myString& other)  //Перегрузка =
{
	if (this->str != nullptr)
	{
		delete[] str;
	}

	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';

	return *this;
}

myString myString::operator+(const myString& other)  //Перегрузка +
{
	myString newStr;

	int thisLenght = strlen(this->str);
	int otherLength = strlen(other.str);

	newStr.length = thisLenght + otherLength;
	newStr.str = new char[thisLenght + otherLength + 1];

	int i = 0;
	for (; i < thisLenght; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[thisLenght + otherLength] = '\0';

	return newStr;
}

bool myString::operator==(const myString& other)  //Перегрузка ==
{
if (this->length != other.length)
{
	return false;
}

for (int i = 0; i < this->length; i++)
{
	if (this->str[i] != other.str[i])
	{
		return false;
	}
}
return true;
}

bool myString::operator!=(const myString& other)  //Перегрузка !=
{
	return !(this->operator==(other));
}

char& myString::operator[](int index)
{
	return this->str[index];
}

int myString::Length()
{
	return length;
}

void myString::Print()
{
	std::cout << str << std::endl;
}
