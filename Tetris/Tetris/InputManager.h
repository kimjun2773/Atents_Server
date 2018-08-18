#pragma once
#include <conio.h>
#include <atomic>

class InputManager {
	private: std::atomic<int> key;
	private: bool isEmpty;

	public: InputManager();
	public: ~InputManager();

	public: void PushKey();
	public: int PopKey();
};

