#include "interleave.hpp"

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void Interleave::producer()
{
	m_sharedId = shmget(SHARED_KEY, SIZE, 0666 | IPC_CREAT);
	m_counter = static_cast<long*>(shmat(m_sharedId, 0, 0)); // this will give us back a void pointer void* ptr

	*m_counter = 0;

	while (true)
	{
		long before = *m_counter;
		(*m_counter)++;
		long after = *m_counter;
		if (after != (before+1))
		{
			std::cout << "Expected " << before + 1 << " have " << after << std::endl;
		}
		if (*m_counter % 1000000 == 0)
		{
			std::cout << "Current value is: " << *m_counter << std::endl;
		}

	}
			
}

void Interleave::consumer()
{
	m_sharedId = shmget(SHARED_KEY, SIZE, 0666);
	m_counter = static_cast<long*>(shmat(m_sharedId, 0, 0));

	while(true)
	{
		long before = *m_counter;
		(*m_counter)--;
		long after = *m_counter;

		if (after != (before - 1))
		{
			std::cout << "Expected " << before - 1 << " have " << after << std::endl;
		}
	}
}
