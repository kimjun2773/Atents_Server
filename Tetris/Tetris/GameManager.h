#pragma once
#include "InputManager.h"
#include "TickTimer.h"
#include "Board.h"
#include "Tetromino.h"

class GameManager{
	public: TickTimer* timer;
	public: InputManager* input;
	private: Board* board;
	private: Tetromino* tetromino;

	public: GameManager(int boardRow, int boardCol, float tickTime);
	public: virtual ~GameManager();

	public: void Update();
};

