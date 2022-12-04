#pragma once
#ifndef _SIMPLEBICYCLE_H_
#define _SIMPLEBICYCLE_H_


#include "IBicycle.h"
#include <iostream>

class SimpleBicycle : public IBicycle
{
public:
	void Turn() override
	{
		std::cout << "Turn Simple Bicycle" << std::endl;
	}
	void Ride() override
	{
		std::cout << "Ride Simple Bicycle" << std::endl;
	}
};


#endif // !_SIMPLEBICYCLE_H_
