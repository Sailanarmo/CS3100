#include "interleave.hpp"

int main(int argc, char* argv[])
{

	Interleave myTest;

	if(argc == 1)
	{
		myTest.producer();
	}
	else
	{
		myTest.consumer();
	}

	return 0;

}
