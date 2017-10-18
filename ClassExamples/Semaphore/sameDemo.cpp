#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string>


int main(int argc)
{
	const int SEMAPHORE_KEY = 1234;
	const short ADD_KEY     = 1;
	const short WAIT_KEY    = -1;

	{
		semId = semget(SEMAPHORE_KEY, 1, 0666);
	}
	
	std::cout << "Press enter to take the key";
	std::string input;
	std::getline(std::cin, input, '\n');
	
	std::cout << "Waiting on the key...";
	std::cout.flush();
	
	sembuf buf;
	
	buf.sem_num = 0;
	buf.sem_flg = 0;
	buf.sem_op = WAIT_KEY;
	semop(semID,&buf, 1);
	
	std::cout << "We've got the key" << std::endl;	



}
