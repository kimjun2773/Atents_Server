#include <Windows.h>
#include <iostream>

#include "GameManager.h"

using namespace std;

int main() {
	GameManager gameMgr(20, 15, 0.2f);

	std::thread t1(&TickTimer::Run, gameMgr.timer);
	std::thread t2(&InputManager::GetKey, gameMgr.input);

	while (1) { gameMgr.Update(); }
	
	return 0;
}