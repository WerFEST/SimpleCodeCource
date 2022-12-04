#pragma once
#ifndef _HUMAN_H_
#define _HUMAN_H_


#include <string>
#include "Apple.h"

class Human
{
private:
	//Свойства класса (поля)
	int age;
	std::string name;
	int humanID;
	static int ID;

public:
	Human();								//Конструктор по-умолчанию
	Human(int age, std::string name);		//Перегрузка конструктора
	Human(std::string name);
	Human(std::string name, int age);		//Делигирующий конструктор
	~Human();								//Деструктор
	Human(const Human& other);				//Конструктор копирования
	Human& operator= (const Human& other);	//Перегрузка оператора =
	void PrintInfo();						//Метод (функция)
	void SetAge(int valueAge);				//Сеттер
	void SetName(std::string name);
	std::string GetName();					//Геттер
	int GetAge();
	int GetID();
	//void TakeApple(Apple& apple);			//Определение методов вне класса

};


#endif // !_HUMAN_H_