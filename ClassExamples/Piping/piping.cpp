#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/wait.h>


const int PIPE_COUNT = 2;
const int PIPE_READ_END = 0;
const int PIPE_WRITE_END = 1;

const int STDIN = 0;
const int STDOUT = 1;

int main()
{
	
	int pids[PIPE_COUNT];
	pipe(pids);

	int savedStdOut = dup(STDOUT);
	int savedStdIn = dup(STDIN);

	pid_t pid = fork();
	if(pid == 0)
	{
		dup2(pids[PIPE_WRITE_END], STDOUT);

		char** argv = new char*[3];
		argv[0] = new char[4];
		strcpy(argv[0], "cat");
		argv[1] = new char[13];
		strcpy(argv[1], "piping.cpp");
		argv[2] = NULL;

		execvp(argv[0], argv);
	}

	pid_t pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pids[PIPE_READ_END], STDIN);
		close(pids[PIPE_WRITE_END]);

		char** argv = new char*[2];
		argv[0] = new char[5];
		strcpy(argv[0], "more");
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

	return 0;

}

