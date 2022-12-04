#pragma once
#ifndef _MYEXCEPTION_H_
#define _MYEXCEPTION_H_


#include <iostream>

class myException : public std::exception
{
public:
	myException(const char* msg, int dataState) : exception(msg)
	{
		this->dataState = dataState;
	}

	int GetDataState() { return dataState; }

private:
	int dataState;
};


#endif // !_MYEXCEPTION_H_
