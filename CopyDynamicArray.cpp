#include "CopyDynamicArray.h"
#include "FillArray.h"
#include "ShowArray.h"
#include <iostream>

void CopyDynamicArray()
{
	int size1Arr = 10;
	int size2Arr = 8;

	int* firstArr = new int[size1Arr];      // Выделяем память под первый массив
	int* secondArr = new int[size2Arr];     // Выделяем память под второй массив
	FillArray(firstArr, size1Arr);
	FillArray(secondArr, size2Arr);

	std::cout << "First Array: " << std::endl;
	ShowArray(firstArr, size1Arr);
	std::cout << "Second Array: " << std::endl;
	ShowArray(secondArr, size2Arr);

	delete[] firstArr;                      // Очищаем первый массив
	firstArr = new int[size2Arr];           // Выделяем заново под него память с size как у второго массива
	for (int i = 0; i < size2Arr; i++)
	{
		firstArr[i] = secondArr[i];         // Переписываем данные из второго массива в первый
	}

	std::cout << "First Array: " << std::endl;
	ShowArray(firstArr, size1Arr);
	std::cout << "Second Array: " << std::endl;
	ShowArray(secondArr, size2Arr);

	delete[] secondArr;
	delete[] firstArr;
}
