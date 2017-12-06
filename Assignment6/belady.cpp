#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>

int randNum()
{
	int rand = 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> unif(1,250);

	rand = unif(mt);

	return rand;
}


int main()
{
	int n, pos, oldFaults;
	int faults = 0;
	int anom = 0;
	unsigned int iter = 0;
	std::deque<int> fifo;
	std::array<std::array<int,1000>,100> cont;
	std::unordered_map<int,int> hash;
	std::chrono::duration<double> time;
	//std::vector<std::vector<int>> cont;

	for (int i = 0; i < 100; ++i)
	{
		std::vector<int> temp;
		for(int j = 0; j < 1000; ++j)
		{
			//temp.emplace_back(randNum());
			cont[i][j] = randNum();
		}
//		cont.emplace_back(temp);
	}
	
	auto start = std::chrono::high_resolution_clock::now();	
	for(int seq = 0; seq < 100; ++seq)
	{
		for(unsigned int i = 0; i < 100; ++i)
		{	
			while(iter < cont[seq].size())
			{
				n = cont[seq][iter];
				if (hash.count(n) == 0)
				{
					if (fifo.size() >= i+1)
					{
						pos = fifo.front();
						hash.erase(pos);
						fifo.pop_front();
					}
					hash[n] = iter;
					fifo.emplace_back(n);
					faults++;
				}
				iter++;	
			}
			if(faults > oldFaults && oldFaults !=0)
			{
				std::cout << "Anomoly detected!" << std::endl;
				std::cout << "    Sequence: " << seq+1 << std::endl;
				std::cout << "    Page Faults: " << oldFaults << " @ Frame Size: " << i-1 << std::endl;
				std::cout << "    Page Faults: " << faults << " @ Frame Size: " << i << std::endl;
				anom++;
			}
			oldFaults = faults;
			faults = 0;
			hash.clear();
			fifo.clear();
//			std::queue<int> empty;
//			std::swap(empty, fifo);
			iter = 0;
		}
		oldFaults = 0;	
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	
	std::cout << "Anomaly detected " << anom << " times." << std::endl;	
		
	std::cout << "Computation took: " << time.count() << "s." << std::endl;	
}

