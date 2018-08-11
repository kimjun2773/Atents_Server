#pragma once
#include <conio.h>
#include <atomic>

class InputManager {
	public: std::atomic<int> key;

	public: InputManager();
	public: ~InputManager();

	public: void GetKey();
};

