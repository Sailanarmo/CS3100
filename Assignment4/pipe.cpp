#include "pipe.hpp"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

void Pipe::modifyArguments(std::string command, std::vector<std::string> &arguments)
{
	prog1 = command;
	arg = arguments;

	for(unsigned int i = 0; i < arg.size(); ++i)
	{
		if(arg[i] == "|")
		{
			prog2 = arg[i+1];
			arg.erase(arg.begin() + i);
			arg.erase(arg.begin() + (i+1));
		}
	}
/*	std::cout << prog2 << std::endl;

	for(auto && e : arg)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	*/
	pipeIt();
}

void Pipe::pipeIt()
{

	int pids[PIPE_COUNT];
	pipe(pids);

	int savedStdOut = dup(STDOUT);
	int savedStdIn = dup(STDIN);

	pid_t pid = fork();
	if(pid == 0)
	{
		dup2(pids[PIPE_WRITE_END], STDOUT);
		
		char** argv = new char*[arg.size() + 2];
		argv[0] = new char[prog1.length()];

		strcpy(argv[0],prog1.c_str());

		for(unsigned int i = 0; i < arg.size(); ++i)
		{
			argv[i+1] = new char[arg[i].size()];
			strcpy(argv[i+1],arg[i].c_str());
		}

		argv[arg.size() + 1] = NULL;
		
		execvp(argv[0],argv);
	}

	pid_t pid2 = fork();
	if(pid2 == 0)
	{
		dup2(pids[PIPE_READ_END], STDIN);
		close(pids[PIPE_WRITE_END]);

		char** argv = new char*[2];
		argv[0] = new char[prog2.length()];
		strcpy(argv[0], prog2.c_str());
		argv[1] = NULL;
		
		execvp(argv[0], argv);		
	}


	int status;
	waitpid(pid, &status, 0);
	
	close(pids[PIPE_WRITE_END]);
	close(pids[PIPE_READ_END]);

	waitpid(pid2, &status, 0);

	dup2(savedStdOut, STDOUT);
	dup2(savedStdIn, STDIN);
	
	arg.clear();	
}
