#include "SwapPointers.h"

void SwapPointer(int* pa, int* pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
