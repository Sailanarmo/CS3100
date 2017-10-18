#include "shell.hpp"
#include <signal.h>



int main()
{
	Shell a;

	signal(SIGINT, SIG_IGN);

	a.init();

	
	
	return 0;

}
