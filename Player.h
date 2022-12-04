#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Weapon.h"

class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

#endif // !_PLAYER_H_
