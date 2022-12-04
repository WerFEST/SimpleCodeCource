#include "STL.h"

void push_back(int*& arr, int& size, const int value)
{
	int* newarr = new int[size + 1];	// Создаем новый массив с увеличенным размером

	for (int i = 0; i < size; i++)		// Переписываем данные из старого массива в новый
	{
		newarr[i] = arr[i];
	}

	newarr[size] = value;				// Добавляем значение в последний элемент массива
	size++;								// Указываем, что размер массива увеличился

	delete[] arr;
	arr = newarr;						// Присваиваем новый указатель на массив
}

void pop_back(int*& arr, int& size)
{
	size--;                         // Уменьшаем размер массива
	int* newarr = new int[size];    // Создаем новый массив

	for (int i = 0; i < size; i++)  // Переписываем данные из старого массива в новый
	{
		newarr[i] = arr[i];
	}

	delete[] arr;
	arr = newarr;                   // Присваиваем новый указатель на массив
}

void push_front(int*& arr, int& size, const int value)
{
	int* newarr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newarr[i + 1] = arr[i];
	}

	newarr[0] = value;
	size++;

	delete[] arr;
	arr = newarr;
}

void pop_front(int*& arr, int& size)
{
	size--;
	int* newarr = new int[size];

	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i + 1];
	}

	delete[] arr;
	arr = newarr;
}

void push_mid(int*& arr, int& size, const int value)
{
	int* newarr = new int[size + 1];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == 3)
		{
			newarr[i] = value;
			j--;
		}
		else {
			newarr[i] = arr[j];
		}
		j++;
	}

	delete[] arr;
	arr = newarr;
}

void pop_mid(int*& arr, int& size)
{
	size--;
	int* newarr = new int[size];
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == 3)
		{
			newarr[i] = arr[j + 1];
			j++;
		}
		else {
			newarr[i] = arr[j];
		}
		j++;
	}

	delete[] arr;
	arr = newarr;
}
