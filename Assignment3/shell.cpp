#include "shell.hpp"

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sstream>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void Shell::parseIt(std::string user)
{
	line = user;

	std::istringstream is(line);
	if(is >> command)
	{
		std::string word;
		while(is >> word)
		{
			arguments.push_back(word);
		}
	}
	//save a copy of 

	runProgram(command);
	history.push_back(line);
	arguments.clear();
}

void Shell::init()
{
	while(true)
	{
		std::cout << "[cmd]: ";
		std::string user;
		std::getline(std::cin,user);	
		parseIt(user);
		
	}
}

double Shell::returnTime()
{
	std::cout << "The time spent in the child is: " << time.count() << "s." << std::endl;
}

void Shell::printHistory()
{
    for (int i = 0; i < history.size(); ++i)
	{
		std::cout << i+1 << ". "<< history[i] << std::endl;
	}
	std::cout << std::endl;
}

void Shell::forkIt(std::string input, std::vector<std::string> &arg)
{
	char** argv;

	argv = new char*[arg.size() + 2];
	argv[0] = new char[input.length()];
	
	strcpy(argv[0],input.c_str());


	for(int i = 0; i < arg.size(); ++i)
	{
		argv[i+1] = new char[arg[i].size()];
		strcpy(argv[i+1],arg[i].c_str());
	}

	argv[arg.size()+1] = NULL;

	pid_t child = fork();	
	
	if (child > 0)
	{
		//parent

		int status;
		//start clock
		std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
		waitpid(child,&status,0);
		//stop clock
		std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
		time += time + (end - start);
		if(status != EXIT_SUCCESS)
		{
			std::cout << "Failure to Execute!" << std::endl;
		}
	}
	else if(child == 0)
	{	
		//child
		execvp(argv[0], argv);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
}

void Shell::runProgram(std::string input)
{
	if(input == "ptime")
	{
		returnTime();
	}
	else if(input == "history")
	{
		if(history.empty())
		{
			std::cout << "No history to print out!" << std::endl;
		}
		else
		{
			std::cout << "History" << std::endl;
			std::cout << std::endl;
			std::cout << "================" << std::endl;
			printHistory();
		}
	}
	else if(input == "^")
	{
		if(history.size() == 0)
		{
			std::cout << "No programs in history to execute." << std::endl;
			arguments.clear();
		}
		else
		{
			int n = std::stoi(arguments[0]);
			std::string hist = history[n-1];
			arguments.clear();
			parseIt(hist);
		}
	}
	else if(input == "exit")
	{
		return exit(EXIT_SUCCESS);
	}
	else
	{
		forkIt(input, arguments);
	}
}
