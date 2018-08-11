#include "InputManager.h"

InputManager::InputManager() { key = 'a'; }
InputManager::~InputManager(){}

void InputManager::GetKey() {
	while (1) {
		if (!kbhit()) continue;
		key = getch();
	}
}
