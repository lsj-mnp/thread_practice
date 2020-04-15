#include <thread>
#include <atomic>

//캐시 일관성 == 코어마다 가진 캐시들이 같은 메모리의 각각 다른 시점의 값을 가지고있을 수 있음.
//쓰레드 동기화. (지역변수는 동기화 할 필요가 없음.)
//== 메모리 공간에 들어가있는 변수의 값을(같은 시간대에 볼 수 있게) 맞추는 것.
//쓰레드가 보는 메모리의 값들을 가장 최근에 바뀐 상태로 최신화 함.
//동기화 == synchronization == 시간을 일치시키는 것.

//동기화 기술. mutex, atomic 등
std::atomic_int gValue{};

void plus()
{
	int a{};

	for (int i = 0; i < 10000; ++i)
	{
		a += i;
	}

	gValue += a;
}

int main()
{
	//쓰레드가 호출하는 함수는 인수로 atomic을 못 받는다.
	//쓰레드는 참조형만 못받을지도 모른다.
	std::thread wThread{ plus };

	plus();

	wThread.join();

	printf("%d", gValue.load());

	return 0;
}