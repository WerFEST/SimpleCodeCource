#pragma once
#ifndef _THREADWORKPARAM_H_
#define _THREADWORKPARAM_H_

#include <iostream>
#include <thread>
#include <chrono>

void ThreadWorkParam(int a, int b)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Thread Started" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << "A + B = " << a + b << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Thread Stopped" << std::endl;
};


#endif // !_THREADWORKPARAM_H_



