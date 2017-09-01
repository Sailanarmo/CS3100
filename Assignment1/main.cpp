#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cfenv>

int fibonacci(int n)
{
	int x = 1;
	int y = 1;
	int z = 1;

	if (n == 0) return 1;
	if (n == 1) return 1;

	for (int i = 2; i < n; ++i)
	{
	    z = x + y;
		x = y;
		y = z;	
	}
    return y;
}

double e(int n)
{
	double x = 1.0;
	double y = 1.0;
	for (double i = 1.0; i <= n; ++i)
	{
		x *= i;
		y = y + 1.0/x;
	}
	return y;
}

double pi(int n)
{
	double x = 0.0;
	for (int i = 0; i < n; ++i)
	{
	//	x = x + ((std::pow(-1,i))/((2*i)+1));
		x = x + (((1.0)/(std::pow(16,i)))*(((4.0)/((8.0*i)+1.0))-((2.0)/((8.0*i)+4.0))-((1.0)/((8.0*i)+5))-((1.0)/((8.0*i)+6))));
	}
	return x;
}

void printMenu()
{
	std::cout << "     --- Assign 1 Help ---" << std::endl;
	std::cout << " -fib [n] : Compute the fibonacci of [n]" << std::endl;
	std::cout << " -e   [n] : Compute the value 'e' using [n] iterations" << std::endl;
	std::cout << " -pi  [n] : Compute Pi to [n] digits" << std::endl;
}


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printMenu();
	    return 1;
	}

	std::string option = argv[1];
	int n = std::stoi(argv[2]);
	
	if(option == "-fib")
	{
		if(n < 0)
		{
		    printMenu();
			return 1;
		}
		else if(n > 40)
		{
		    printMenu();
			return 1;
		}
		else
        {
		    std::cout << "Fibonacci of " << n << " is: " << fibonacci(n) << std::endl;
		}
	}
	else if(option == "-e")
	{
		if(n < 0)
		{
			printMenu();
			return 1;
		}
		else if(n > 30)
		{
			printMenu();
			return 1;
		}
		else
		{
			std::cout << n << " iterations of e is: " << std::fixed << std::setprecision(40) <<e(n) << std::endl;
		}
	}
	else if(option == "-pi")
	{
		if(n < 1)
		{
			printMenu();
			return 1;
		}
		else if(n > 10)
		{
			printMenu();
			return 1;
		}
		else
		{
			std::fesetround(FE_DOWNWARD); //Found from Stack Overflow.
			std::cout << n << " digits of Pi is: " << std::fixed << std::setprecision(n) << pi(n) << std::endl;
		}
	}
	else
	{
		printMenu();
		return 1;
	}

	return 0;
}
