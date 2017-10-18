#include "shell.hpp"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>



void Shell::parseIt(std::string user)
{
	line = user;

	std::istringstream is(line);
	if(is >> command)
	{
		std::string word;
		while(is >> word)
		{
			if(word == "|")
			{
				runOther = true;
			}
			arguments.push_back(word);
		}
	}
	if(runOther == true)
	{
		for(unsigned int i = 0; i < arguments.size(); ++i)
		{
			if(arguments[i] == "|")
			{
				history.push_back(line);
				pipe.modifyArguments(command, arguments);
			}

		}
		runOther = false;
	}
	else
	{
		runProgram(command);

		if(command != "^")
		{
			history.push_back(line);
		}
	}
	arguments.clear();
}

void Shell::init()
{
	while(true)
	{
		char *curDir=(char *)get_current_dir_name();	
		std::cout << "[" << curDir << "]: ";
		std::string user;
		std::getline(std::cin,user);	
		
		if(user == "")
		{
			continue;
		}

		parseIt(user);
		
	}
}

double Shell::returnTime()
{
	std::cout << "The time spent in the child is: " << time.count() << "s." << std::endl;
}

void Shell::printHistory()
{
    for (unsigned int i = 0; i < history.size(); ++i)
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


	for(unsigned int i = 0; i < arg.size(); ++i)
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
		auto start = std::chrono::high_resolution_clock::now();
		waitpid(child,&status,0);
		auto end = std::chrono::high_resolution_clock::now();
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
			history.clear();
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
			return;
		}
		else if(std::stoi(arguments[0]) > history.size())
		{
			std::cout << "Input size greater than history, aborting." << std::endl;
			arguments.clear();
			history.pop_back();
			return;
		}
		else
		{
			int n = std::stoi(arguments[0]);
			std::string hist = history[n-1];	
			arguments.clear();
			parseIt(hist);
			history.pop_back();
		}
	}
	else if(input == "exit")
	{
		return exit(EXIT_SUCCESS);
	}
	else if(input == "cd")
	{
		std::string extract = arguments[0];
		const char *directory = extract.c_str();
		ret = chdir(directory);
		arguments.clear();		
	}
	else
	{
		forkIt(input, arguments);
	}
}
