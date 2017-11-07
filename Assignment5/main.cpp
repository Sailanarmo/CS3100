#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include <unordered_map>

#include "compPi.hpp"

void hashPi(std::unordered_map<int,int> &pi,int pos, int piDig)
{
	pi[pos] = piDig;	
}

void threadQueue(int pos, int piDig, CompPi a, std::queue<int> &queue, std::unordered_map<int,int> &pi, std::mutex &mutex)
{
	std::lock_guard<std::mutex> lock(mutex);
	while(!queue.empty())
	{
		pos = queue.front();
		piDig = a.computePi(pos);
		std::cout << ".";
		std::cout.flush();
		hashPi(pi,pos,piDig);	
		queue.pop();
	}
}

int main()
{
	
	CompPi a;
	int pos;
	int piDig;
	std::queue<int> queue;
	std::mutex mutex;
	std::unordered_map<int,int> pi;
		
	std::chrono::duration<double> time;

	for (int i = 1; i <= 1000; ++i)
	{
		queue.emplace(i);
	}
	std::vector<std::thread> threadCount;
	auto start = std::chrono::high_resolution_clock::now();			
	for(unsigned int i = 1; i <= std::thread::hardware_concurrency(); ++i)
	{
		threadCount.emplace_back(std::thread(threadQueue,pos,piDig,a,std::ref(queue),std::ref(pi),std::ref(mutex)));
	}
		for(auto && e : threadCount)
	{
		e.join();
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	time = end - start;
	std::cout << std::endl;	
	std::cout << std::endl;	
	std::cout << std::endl;	

	std::cout << "3.";
	for(unsigned int i = 0; i < pi.bucket_count(); ++i)
	{
		for(auto it = pi.begin(i); it != pi.end(i); ++it)
		{
			std::cout << it->second;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl << "Computation took: " << time.count() << "s." << std::endl;
	return 0;
	
}
