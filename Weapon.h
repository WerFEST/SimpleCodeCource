#pragma once
#ifndef _WEAPON_H_
#define _WEAPON_H_


#include <iostream>

class Weapon
{
public:
	virtual void Shoot() = 0;
	void Foo() { std::cout << "Foo()" << std::endl; }
};


#endif // !_WEAPON_H_


