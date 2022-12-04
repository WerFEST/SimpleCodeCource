#pragma once

#include <iostream>
#include "myException.h"

void exceptFoo(int value)
{
	if (value < 0)
	{
		throw std::exception("Number is negative");
	}
	if (value == 0)
	{
		throw "Number is = 0";
	}
	if (value == 1)
	{
		throw myException("myException: Number is equals 1", value);
	}

	std::cout << "Number is: " << value << std::endl;
}