#pragma once
#ifndef _MYSTRING_H_
#define _MYSTRING_H_


class myString
{
private:
	char* str;
	int length;

public:
	myString();
	myString(const char* str);
	~myString();
	myString(const myString& other);            //Конструктор копирования
	myString(myString&& other);					//Конструктор перемещения
	myString& operator=(const myString& other); //Перегрузка =
	myString operator+(const myString& other);  //Перегрузка +
	bool operator==(const myString& other);		//Перегрузка ==
	bool operator!=(const myString& other);  //Перегрузка !=
	char& operator[](int index);
	void Print();
	int Length();

};


#endif // !_MYSTRING_H_