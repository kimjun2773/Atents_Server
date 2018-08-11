#include "TickTimer.h"

TickTimer::	TickTimer(float tickTime) {
	this->tickTime = tickTime;
	elapsedTime = 0.0f;
	curr = clock();
	prev = curr;
	isUpdated = true;
}
TickTimer::~TickTimer(){}

void TickTimer:: Run() {
	while (1) {
		curr = clock();
		elapsedTime += (curr - prev) / (float)CLOCKS_PER_SEC;
		prev = curr;

		if (elapsedTime > tickTime) {
			isUpdated = true;
			elapsedTime = 0.0f;
		}
	}
}

bool TickTimer::check() {
	if (isUpdated) {
		isUpdated = false;
		return true;
	}
	return false;
}