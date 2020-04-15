//mutual exclusion = ��ȣ���� = �������� �������� ��. ��װ� �����ϰ� ��.
#include <mutex>
//atomic �ڷ����� ���������� ó���ϰ� �ٲ���.
#include <atomic>
#include <thread>
#include <iostream>

int main()
{
	int a{}; //�Ӱ豸��(critical section) 

	//������ ������ atomic�� ȿ�������� ����.
	//std::atomic<int> a{};
	/* atomic = ����������. ���� ������ ������ �� ������ �Ͼ�� ������ �����.
	���߿� �ٸ� ��������� �� �ǵ帲.*/
	int b{ 17 };

	//mutex = mutual exclusion ��ȣ ����
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

	//�ش� �����尡 ���� ������ ��ٸ��ٴ� ���� �Լ�.
	thr_add.join();
	thr_subtract.join();

	std::cout << a;

	return 0;
}
