#pragma once
#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class MyClass
{
private:
	int size;
	int arr[5]{ 5,10,15,20,25 };
public:
	int* data;

	MyClass(int size);					//Конструктор
	MyClass(const MyClass& other);		//Конструктор копирования
	~MyClass();							//Деструктор
	int& operator[](int index);			//Перегрузка оператора индексирования

};

#endif // !_MYCLASS_H_
