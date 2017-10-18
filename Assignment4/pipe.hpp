#ifndef PIPE_HPP
#define PIPE_HPP

#include <string>
#include <vector>

class Pipe
{

public:
	void pipeIt();
	void modifyArguments(std::string command, std::vector<std::string> &arguments);

private:
	
	std::string prog1;	
	std::string prog2;	

	std::vector<std::string> arg;
				
	const int PIPE_COUNT     = 2;
	const int PIPE_READ_END  = 0;
	const int PIPE_WRITE_END = 1;
	const int STDIN  = 0;
	const int STDOUT = 1;


};

#endif
