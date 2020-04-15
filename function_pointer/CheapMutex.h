#pragma once

#include <thread>
#include <chrono>

class CheapMutex
{
public:
	CheapMutex() {}
	~CheapMutex() {}

public:
	void lock()
	{
		while (_bLocked == true)
		{
			//class 생성자만 이렇게 호출할 수 있음.
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

			if (_bLocked == false)
			{
				break;
			}
		}

		_bLocked = true;
	}

	void unlock()
	{
		if (_bLocked == true)
		{
			_bLocked = false;
		}
	}
	

private:
	bool _bLocked{};
};
