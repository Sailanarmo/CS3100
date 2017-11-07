#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include <future>
#include <utility>
#include <unordered_map>

#include "compPi.hpp"

void hashPi(std::unordered_map<int,int> &pi,int pos, int piDig,std::mutex &mutex2)
{
	std::lock_guard<std::mutex> lock2(mutex2);
	pi[pos] = piDig;	
}

void threadQueue(int pos, int piDig, CompPi a, std::queue<int> &queue, std::unordered_map<int,int> &pi, std::mutex &mutex1,std::mutex &mutex2)
{
	while(!queue.empty())
	{
		{
			std::lock_guard<std::mutex> lock1(mutex1);
			pos = queue.front();
			queue.pop();
		}
		piDig = a.computePi(pos);
		std::cout << ".";
		std::cout.flush();
		hashPi(pi,pos,piDig,mutex2);	
	}
}

int main()
{
	
	CompPi a;
	int pos;
	int piDig;
	std::queue<int> queue;
	std::mutex mutex1;
	std::mutex mutex2;
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
		threadCount.emplace_back(threadQueue,pos,piDig,a,std::ref(queue),std::ref(pi),std::ref(mutex1),std::ref(mutex2));
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
