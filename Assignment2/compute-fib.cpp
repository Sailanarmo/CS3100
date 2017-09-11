#include "compute-fib.hpp"


int Fibonacci::computeFib(int n)
{

	if (n == 0) return 1;
	if (n == 1) return 1;

	for (int i = 2; i < n; ++i)
	{
		z = x+y;
		x = y;
		y = z;
	}

	return y;
}
