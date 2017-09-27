#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main()
{

	int testValue = 10;

	std::cout << "This is a demo of the fork command..." << std::endl;
	auto childId = fork();
	std::cout << "testValue is: " << testValue << std::endl;
	std::cout << "childId is: " << childId << std::endl;

	if(childId)
	{
		testValue += 2;
		wait(NULL);
		std::cout << "This is the parent" << std::endl;
	}
	else
	{
		fork();
		wait(NULL);
		testValue = 6;
		std::cout << "This is the child" << std::endl;
	}

	std::cout << "testValue is: " << testValue << std::endl;
	std::cout << "Thanks for playing" << std::endl;

	return 0;
}
