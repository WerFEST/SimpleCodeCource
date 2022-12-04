#pragma once
#include <iostream>

namespace FirstNamespace
{
	void Foo()
	{
		std::cout << "Visible only in this namespace" << std::endl;
	}
	
	int a;
	
	class test
	{
	public:
		void Foo()
		{
			std::cout << "Visible in namespace and class only" << std::endl;
		}
	private:
		int b;
	};
}