#ifndef INTERLEAVE_HPP
#define INTERLEAVE_HPP

class Interleave
{

public:

	void producer();
	void consumer();

private:
	int m_sharedId;
	volatile long* m_counter; 

	const int SIZE = 64;
	const int SHARED_KEY = 1234;
};

#endif
