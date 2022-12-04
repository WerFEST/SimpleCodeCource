#include "ShowArray.h"
#include <iostream>

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}
