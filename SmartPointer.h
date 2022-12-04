#pragma once
#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_


template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}

	~SmartPointer()
	{
		delete ptr;
		cout << "Destructor" << endl;
	}

	T& operator*()
	{
		return *ptr;
	}

private:
	T* ptr;
};


#endif // !_SMARTPOINTER_H_
