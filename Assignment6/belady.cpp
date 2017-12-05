#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <random>
#include <chrono>
#include <string>
#include <sstream>
#include <unordered_map>

int randNum()
{
	int rand = 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> unif(0,9);

	rand = unif(mt);

	return rand;
}


int main()
{
	std::string number;
	int n, pos;
	int counter = 0;
	//std::deque<int> debug(3,100);
	std::queue<int> fifo;
	std::unordered_map<int,int> hash;
/*	
	for (auto i = 0; i < 1000; ++i)
	{
		number.append(std::to_string(randNum()%10) + " ");
		//queue.emplace(randNum());
	}
*/			
	//int plz = hash[0];
	//std::cout << plz << std::endl;

	//number = "1 2 3 1 4 1 7 9";
	number = "1 2 3 4 1 2 5 1 2 3 4 5";
	std::cout << fifo.size() << std::endl;
	int iter = 0;	
	std::istringstream numbers(number);
	while(numbers >> n)	
	{
		std::cout << "Hash size: " << hash.size() << std::endl;
		std::cout << "Queue size: " << fifo.size() << std::endl;	
		std::cout << std::endl;
/*
		
		if (hash.count(n) == 0)
		{
			hash.emplace(iter, n);
			fifo.emplace(n);
			std::cout << "Inserting in Queue: " << n << std::endl;
			counter++;
		}
		else if (hash.size() > 3)
		{
			pos = fifo.front();
			std::cout << "Replacing " << pos << " with: " << n << std::endl;
			std::cout << std::endl;
			fifo.pop();
			hash[pos] = n;
			//hash.emplace(iter,n);
			fifo.emplace(n);
			counter++;
		}
*/


		if (hash.count(n) == 0)
		{
			if (hash.size() > 3 || fifo.size() > 3)
			{
				pos = fifo.front();
				std::cout << "Replacing " << pos << " with: " << n << std::endl;
				std::cout << std::endl;
				fifo.pop();
				hash.erase(pos);
				//hash[pos] = n;
				hash.emplace(iter,n);
				fifo.emplace(n);
				counter++;
				continue;
			}
			hash.emplace(iter, n);
			fifo.emplace(n);
			std::cout << "Inserting in Queue: " << n << std::endl;
			counter++;
		}
		iter++;	
	}
	std::cout << counter << std::endl;
	
	std::cout << number << std::endl;

}

