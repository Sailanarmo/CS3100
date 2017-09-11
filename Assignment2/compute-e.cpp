#include "compute-e.hpp"


double E::computeE(int n)
{
	for (double i = 1.0; i <= n; ++i)
	{
		x *= i;
		y = y + 1.0/x;
	}

	return y;
}
