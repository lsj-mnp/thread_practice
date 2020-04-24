//#include <mutex>
#include "CheapMutex.h"
#include <thread>

int gValue{};

CheapMutex CheapMut{};
//std::mutex mut{};

void plus()
{

	CheapMut.lock();
	
	for (int i = 0; i < 5'000'000; ++i)
	{
		++gValue;
	}

	CheapMut.unlock();
	
}

int main()
{
	//쓰레드는 하나의 함수만 받을 수 있다. 
	//따라서 여러개의 함수를 넣으려면 하나의 함수에 여러 함수를 호출해야 한다.
	std::thread thread1{ plus };

	plus();

	thread1.join();

	printf("%d", gValue);

	return 0;
}