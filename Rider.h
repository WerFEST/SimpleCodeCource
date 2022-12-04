#pragma once
#ifndef _RIDER_H_
#define _RIDER_H_


#include "IBicycle.h"
#include <iostream>

class Rider
{
public:
	void RideOn(IBicycle& bicycle)
	{
		std::cout << "Ride!" << std::endl;
		bicycle.Ride();
		std::cout << "Turn!" << std::endl;
		bicycle.Turn();
	}
};


#endif // !_RIDER_H_
