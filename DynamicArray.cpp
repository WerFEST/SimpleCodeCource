#include "DynamicArray.h"
#include <iostream>

void DynamicArray(int* rows, int* cols)
{

	int row = *rows;                // row - строки, col - колонки
	int col = *cols;                // Разыменовываем полученные значение и создаем из них локальные

	int** arr = new int* [row];     // Выделение памяти для массива указателей

	for (int i = 0; i < row; i++)   // Создание массива указателей для одномерных массивов
	{
		arr[i] = new int[col];      // Выделение памяти для одномерных массивов
	}

	for (int i = 0; i < row; i++)   // Заполнение массива и вывод на экран
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < row; i++)   // Очищение памяти и удаление массива.
	{
		delete[] arr[i];            // очищаем память сначала из всех строчек
	}
	delete[] arr;                   // а затем и сам массив в указателями на эти строчки

}
