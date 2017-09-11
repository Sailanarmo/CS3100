#include <iostream>
#include <string>
#include <iomanip>
#include <cfenv>

#include "compute-fib.hpp"
#include "compute-e.hpp"
#include "compute-pi.hpp"

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
	
	Fibonacci fib;
	E e;
	Pi pi;

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
		    std::cout << "Fibonacci of " << n << " is: " << fib.computeFib(n) << std::endl;
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
			std::cout << n << " iterations of e is: " << std::fixed << std::setprecision(40) <<e.computeE(n) << std::endl;
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
			std::cout << n << " digits of Pi is: " << std::fixed << std::setprecision(n) << pi.computePi(n) << std::endl;
		}
	}
	else
	{
		printMenu();
		return 1;
	}

	return 0;
}
