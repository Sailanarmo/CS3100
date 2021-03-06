#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <chrono>
#include <unordered_map>

int main()
{
	std::srand(time(NULL));
	int n, pos, oldFaults;
	int faults = 0;
	int anom = 0;
	unsigned int iter = 0;
	std::deque<int> fifo;
	std::array<std::array<int,1000>,100> cont;
	std::chrono::duration<double> time;
	std::array<bool,250> hash;
	
	auto start = std::chrono::high_resolution_clock::now();	
	
	for (int i = 0; i < 100; ++i)
	{
		for(int j = 0; j < 1000; ++j)
		{
			cont[i][j] = std::rand()%250;
		}
	}

	
	for(int seq = 0; seq < 100; ++seq)
	{
		for(unsigned int i = 0; i < 100; ++i)
		{	
			while(iter < cont[seq].size())
			{
				n = cont[seq][iter];
				if (hash[n] == 0)
				{
					if (fifo.size() >= i+1)
					{
						pos = fifo.front();
						hash[pos] = 0;
						fifo.pop_front();
					}
					hash[n] = 1;
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
			for (int i = 0; i < 250; ++i)
			{
				hash[i] = false;
			}

			fifo.clear();
			iter = 0;
		}
		oldFaults = 0;	
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	
	std::cout << "Anomaly detected " << anom << " times." << std::endl;	
		
	std::cout << "Computation took: " << time.count() << "s." << std::endl;	
}

