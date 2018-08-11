#pragma once
#include <time.h>
#include <atomic>

class TickTimer {
	public: float tickTime;
	
	private: float elapsedTime;
	private: clock_t curr;
	private: clock_t prev;
	private: std::atomic<bool> isUpdated;

	public: TickTimer(float tickTime);
	public: ~TickTimer();

	public: void Run();
	public: bool check();
};

