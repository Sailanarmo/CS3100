#include "compute-pi.hpp"
#include <cmath>

double Pi::computePi(int n)
{
	for (int i = 0; i < n; ++i)
	{
		//This is Bailey-Borwein-Plouffe's Formula.
		x = x + (((1.0)/(std::pow(16,i)))*(((4.0)/((8.0*i)+1.0))-((2.0)/((8.0*i)+4.0))-((1.0)/((8.0*i)+5))-((1.0)/((8.0*i)+6))));
	}
	return x;
}

