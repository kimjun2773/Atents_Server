#include "InputManager.h"

InputManager::InputManager() { isEmpty = true; key = 'a'; }
InputManager::~InputManager(){}

void InputManager::PushKey() {
	while (1) {
		if (kbhit() == false || isEmpty == false) continue;

		key = getch();
		isEmpty = false;
	}
}

int InputManager::PopKey() {
	if (isEmpty) return 0;
	else { isEmpty = true; return key; }
}
