//#include <mutex>
#include "CheapMutex.h"
#include <thread>

int gValue{};

CheapMutex CheapMut{};
//std::mutex mut{};

void plus()
{

	//CheapMut.lock();
	
	for (int i = 0; i < 5'000'000; ++i)
	{
		++gValue;
	}
	//CheapMut.unlock();
	
}

int main()
{
	std::thread thread1{ plus };

	plus();

	thread1.join();

	printf("%d", gValue);

	return 0;
}