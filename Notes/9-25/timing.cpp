#include <iostream>
#include <chrono>
#include <cmath>


double reallyLongThing()
{
	
	double total = 0;	
	for (int angle = 0; angle < 100000; ++angle)
	{
		total += std::sin(angle);
	}

	return total;

}



int main()
{
	
	auto start = std::chrono::system_clock::now();

	double result = reallyLongThing();

	auto end = std::chrono::system_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "Time difference is: " << diff.count() << " and the result is: " << result << std::endl;


	return 0;

}
