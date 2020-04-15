//mutual exclusion = 상호배제 = 점유권을 가져가게 함. 잠그고 해제하고 함.
#include <mutex>
//atomic 자료형을 원자적으로 처리하게 바꿔줌.
#include <atomic>
#include <thread>
#include <iostream>

int main()
{
	int a{}; //임계구역(critical section) 
	//변수가 적으면 atomic이 효율적으로 보임.
	//std::atomic<int> a{};
	/* atomic = 원자적으로. 여러 연산을 연산을 한 번만에 일어나는 것으로 취급함.
	도중에 다른 쓰레드들이 못 건드림.*/
	int b{ 17 };

	//mutex = mutual exclusion 상호 배제
	std::mutex mut{};

	std::thread thr_add
	{
		[&]
		{ 
			for(int i = 0; i < 1000000; ++i)
			{
				mut.lock();
				++a;
				mut.unlock();
			}
		}
	};

	std::thread thr_subtract
	{
		[&]
		{
			for (int i = 0; i < 1000000; ++i)
			{
				mut.lock();
				--a;
				mut.unlock();
			}
		}
	};

	//해당 쓰레드가 끝날 때까지 기다린다는 뜻의 함수.
	thr_add.join();
	thr_subtract.join();

	std::cout << a;

	return 0;
}
