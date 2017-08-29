#include <iostream>
#include <string>

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

int factorial(int n)
{
	int x = 1;

	for (int i = 1; i <= n; ++i)
	{
		x *= i;
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
			std::cout << n << " iterations of e is: " << factorial(n) << std::endl;
		}
	}
	else
	{
		printMenu();
		return 1;
	}
}
