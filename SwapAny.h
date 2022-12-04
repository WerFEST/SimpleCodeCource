#pragma once
#ifndef _SWAPANY_H_
#define _SWAPANY_H_


template <class T>
T SwapAny(T& a, T& b);

template<class T>
inline T SwapAny(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}


#endif // !_SWAPANY_H_
