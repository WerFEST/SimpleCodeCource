#pragma once
#ifndef _POINT_H_
#define _POINT_H_


#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int x, int y);
	void Print();
	bool operator==(const Point& other);			//Перегрузка оператора ==
	bool operator!=(const Point& other);			//Перегрузка оператора !=
	Point operator+(const Point& other);			//Перегрузка оператора +
	Point& operator++();							//Перегрузка префиксного инкремента
	Point& operator++(int value);					//Перегрузка постфиксного инкремента 

	//Дружественная функция
	friend void ChangeX(Point& value);

	//Перегрузка операторов ввода-вывода (<< и >>)
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend std::istream& operator>>(std::istream& is, Point& point);

};


#endif // !_POINT_H_
