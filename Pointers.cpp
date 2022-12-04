#include "Pointers.h"
#include <iostream>

void Pointers()
{
	const int SIZE = 5;
	int arr[SIZE]{ 5,10,15,20,25 };

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << &arr[i] << std::endl;
	}

	std::cout << *(arr + 10) << std::endl;
}
