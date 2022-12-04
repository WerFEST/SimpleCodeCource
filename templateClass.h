#pragma once
#ifndef _TEMPLATECLASS_H_
#define _TEMPLATECLASS_H_


template<typename T>
class templateClass
{
public:
	templateClass(T value)
	{
		this->value = value;
	}

	void DataTypeSize()
	{
		cout << sizeof(value) << endl;
	}

protected:
	T value;
};


#endif // !_TEMPLATECLASS_H_
