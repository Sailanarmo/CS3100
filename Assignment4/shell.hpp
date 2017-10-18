#ifndef SHELL_HPP
#define SHELL_HPP

#include "pipe.hpp"

#include <vector>
#include <string>
#include <chrono>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

class Shell
{

public:
	
	void init();
	void parseIt(std::string user);
	void printHistory();
	void forkIt(std::string command, std::vector<std::string> &arg);
	void runProgram(std::string command);

	double returnTime();

private:
	
	Pipe pipe;
	
	int ret;
	bool runOther = false;

	std::vector<std::string> history;
	std::vector<std::string> arguments;

	std::string line;
	std::string command;
	std::chrono::duration<double> time;	
	
	};


#endif
