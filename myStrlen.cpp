#include "myStrlen.h"
#include <iostream>

void myStrlen(const char* str)
{
	std::cout << strlen(str) << std::endl;
	int counter = 0;

	while (str[counter] != '\0')
	{
		counter++;
	}

	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
		{
			std::cout << i << std::endl;
			break;
		}
	}

	for (; str[counter] != '\0'; counter++)
	{
	}

	std::cout << counter << std::endl;;
}
