#include "MyClass.h"

MyClass::MyClass(int size)
{
	this->size = size;
	this->data = new int[size];				//Выделение динамической памяти

	for (int i = 0; i < size; ++i)
	{
		data[i] = i;
	}
}

MyClass::MyClass(const MyClass& other)
{
	this->size = other.size;
	this->data = new int[other.size];
	
	for (int i = 0; i < other.size; i++)
	{
		this->data[i] = other.data[i];
	}
}

MyClass::~MyClass()
{
	delete[] data;							//Очистка динамической памяти
}

int& MyClass::operator[](int index)
{
	return arr[index];
}
