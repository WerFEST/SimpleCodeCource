#pragma once
#ifndef _SUBMACHINEGUN_H_
#define _SUBMACHINEGUN_H_


#include "Gun.h"

class SubmachineGun : public Gun
{
public:
	void Shoot() override						//Переопределенный виртуальный метод класса Gun
	{
		std::cout << "TRA-TA-TA" << std::endl;
	}
};


#endif // !_SUBMACHINEGUN_H_
