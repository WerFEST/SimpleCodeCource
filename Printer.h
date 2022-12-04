#pragma once

#ifndef _PRINTER_H_
#define _PRINTER_H_


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
class Printer<string>
{
public:
	void Print(string value)
	{
		std::cout << ":" << value << ":" << std::endl;
	}
};

#endif // !_PRINTER_H_
