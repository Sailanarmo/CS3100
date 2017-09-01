#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cfenv>

/*

=====================================================================

This program implements the command line to as the user for input.
The user will have to run the executable and give 2 arguments. The
first argument will be the program they wish to run, the second 
argument will be how many iterations or digits, depending on the 
program. 

Ex) ./Assign1 -fib 10 

This will execute the program, run the fibonacci version, and execute 
the fibonacci sequence 10 times.

Options:

	Fibonacci: -fib n [0-40]
	e:         -e   n [0-30]
	Pi:        -pi  n [1-10]

The flab being the program to run, n being the number that you would
like to give.

======================================================================

*/


/*
This function will run the fibonacci sequence. It takes an integer n,
and returns the fibonacci number requested.
*/
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

/*
This function computes e to however many iterations the user requests.
It takes an integer n, and returns a double of the calculation of e.
*/

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

/*
This function computes digits of pi. It takes an integer n, and 
returns the digits of pi requested as a double.
*/

double pi(int n)
{
	double x = 0.0;
	for (int i = 0; i < n; ++i)
	{
		//This is Bailey-Borwein-Plouffe's Formula.
		x = x + (((1.0)/(std::pow(16,i)))*(((4.0)/((8.0*i)+1.0))-((2.0)/((8.0*i)+4.0))-((1.0)/((8.0*i)+5))-((1.0)/((8.0*i)+6))));
	}
	return x;
}

/*
This Menu is printed when the user does not provide enough arguments.
*/

void printMenu()
{
	std::cout << std::endl;
	std::cout << "          --- Assign 1 Help ---" << std::endl;
	std::cout << " -fib [n] : Compute the fibonacci of [n]; [0-40]" << std::endl;
	std::cout << " -e   [n] : Compute the value 'e' using [n] iterations; [1-30]" << std::endl;
	std::cout << " -pi  [n] : Compute Pi to [n] digits; [1-10]" << std::endl;
	std::cout << std::endl;
}

/*
Main must take 3 arguments and then run a specific program. If main
does not receive enough arguments, print out an error message and 
exit the program gracefully. If the user gives enough arguments, 
then it handles the program as stated.
*/

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
			std::cout << std::endl;
			std::cout << "		Invalid Range for Fibonacci!" << std::endl;
		    printMenu();
			return 1;
		}
		else if(n > 40)
		{
			std::cout << std::endl;
			std::cout << "		Invalid Range for Fibonacci!" << std::endl;
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
		if(n < 1)
		{
			std::cout << std::endl;
			std::cout << "		Invalid Range for e!" << std::endl;
			printMenu();
			return 1;
		}
		else if(n > 30)
		{
			std::cout << std::endl;
			std::cout << "		Invalid Range for e!" << std::endl;
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
			std::cout << std::endl;
			std::cout << "		Invalid Range for Pi!" << std::endl;
			printMenu();
			return 1;
		}
		else if(n > 10)
		{
			std::cout << std::endl;
			std::cout << "		Invalid Range for Pi!" << std::endl;
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
