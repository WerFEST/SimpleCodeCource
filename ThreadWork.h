#pragma once
#ifndef _THREADWORK_H_
#define _THREADWORK_H_


#include <thread>
#include <chrono>
#include <iostream>

void ThreadWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID thread = " << std::this_thread::get_id() << "\t ThreadWork\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}


#endif // !_THREADWORK_H_
