#pragma once
#ifndef _GUN_H_
#define _GUN_H_

#include "Weapon.h"

class Gun : public Weapon
{
public:
	void Shoot() override
	{
		std::cout << "BANG!" << std::endl;
	}
};


#endif // !_GUN_H_
