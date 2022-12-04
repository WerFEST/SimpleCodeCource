#pragma once
#ifndef _B_H_
#define _B_H_


#include "A.h"
#include <iostream>

class B : public A
{
public:
	B() : A("New message")
	{
	}

	void PrintMessage()
	{
		std::cout << A::msgOne << std::endl;
		std::cout << B::msgThree << std::endl;
	}
};


#endif // !_B_H_
