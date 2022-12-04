#pragma once
#ifndef _A_H_
#define _A_H_
#include <string>

class A
{
public:
	A();

	A(std::string msg);

	void PrintMsg();


	std::string msgOne = "First Message";

private:
	std::string msgTwo = "Second Message";

protected:
	std::string msgThree = "Third Message";

};


#endif // !_A_H_

