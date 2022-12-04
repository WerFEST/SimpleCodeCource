#include "Fact.h"

int Fact(int N)
{
	if (N == 0) return 0;
	if (N == 1) return 1;

	return N * Fact(N - 1);
}
