#include <Windows.h>
#include <iostream>
#include <thread>

#include "GameManager.h"

using namespace std;

int main() {
	//thread timerThread;
	//thread inputThread;
	GameManager gameMgr(20, 15, 0.2f);

	//timerThread = thread(&TickTimer::Run, gameMgr.timer);
	//inputThread = thread(&InputManager::PushKey, gameMgr.input);
	while (1) { gameMgr.Update(); }
	//timerThread.join();
	//inputThread.join();
	return 0;
}