#pragma once
#ifndef _TEMPLATEINFO_H_
#define _TEMPLATEINFO_H_


template<typename T>
class templateInfo : public templateClass<T>
{
public:
	templateInfo(T value) : templateClass<T>(value)
	{
		this->value = value;
	}
	void ShowTypeName()
	{
		cout << typeid(this->value).name() << endl;
	}
};

#endif // !_TEMPLATEINFO_H_
