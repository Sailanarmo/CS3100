#ifndef SHELL_HPP
#define SHELL_HPP

#include <vector>
#include <string>
#include <chrono>

class Shell
{

public:
	
	void init();
	void parseIt(std::string user);
	double returnTime();
	void printHistory();
	void forkIt(std::string command, std::vector<std::string> &arg);
	void runProgram(std::string command);

private:
	
	std::vector<std::string> history;
	std::vector<std::string> arguments;

	std::string line;
	std::string command;
	std::chrono::duration<double> time;	
		

};


#endif
