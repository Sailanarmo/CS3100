#include <iostream>
#include <unistd.h>
#include <cstring>

int main()
{

	char** argv;

	argv = new char*[4];
	argv[0] = new char[3];
	argv[1] = new char[3];
	argv[2] = new char[3];
	argv[3] = NULL;

	strcpy(argv[0], "ls");
	strcpy(argv[1], "-l");
	strcpy(argv[2], "-a");

	//this is what auto replaced.
		
	//pid_t id = fork();
	if (fork())
	{	
		execvp(argv[0], argv);
	}
	else
	{	
		std::cout << "This better not show up, or I have some splanin to do!" << std::endl;
	}


	return 0;

}
