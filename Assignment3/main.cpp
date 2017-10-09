#include <iostream>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>

int main()
{

	char** argv;

	std::string line;
	std::string command;
	std::vector<std::string> arguments;	
		
//	while(true)
//	{
		std::cout << "[cmd]:";

		if (std::getline(std::cin, line))
		{
			std::istringstream is(line);
			if(is >> command)
			{
				std::string word;
				while(is >> word)
				{
					arguments.push_back(word);
				}
			}
		}
	//}

	for(auto && e: arguments)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;
	std::cout << command << std::endl;
	
	argv = new char*[arguments.size() + 2];
	argv[0] = new char[command.length()];
	
	strcpy(argv[0],command.c_str());


	for(int i = 0; i < arguments.size(); ++i)
	{
		argv[i+1] = new char[arguments[i].size()];
		strcpy(argv[i+1],arguments[i].c_str());
	}

	argv[arguments.size()+1] = NULL;
/*
	argv = new char*[4];
	argv[0] = new char[3];
	argv[1] = new char[3];
	argv[2] = new char[3];
	argv[3] = NULL;

	strcpy(argv[0], "ls");
	strcpy(argv[1], "-l");
	strcpy(argv[2], "-a");
*/
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
