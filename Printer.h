#pragma once

#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <string>

template<typename T>
class Printer
{
public:
	void Print(T value)
	{
		std::cout << value << std::endl;
	}
};


template<>
class Printer<std::string>
{
public:
	void Print(std::string value)
	{
		std::cout << ":" << value << ":" << std::endl;
	}
};

#endif // !_PRINTER_H_
