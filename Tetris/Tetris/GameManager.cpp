#include "GameManager.h"

GameManager::GameManager(int boardRow, int boardCol, float tickTime) {
	timer = new TickTimer(tickTime);
	input = new InputManager();
	board = new Board(boardRow, boardCol); board->Init();
	tetromino = new Tetromino(); tetromino->Init(2, 5, Tetromino::Type::I);
}
GameManager:: ~GameManager() {}

void GameManager::Update() {
	if (timer->check()) {		
		int key = input->PopKey();
		if (board->OkToMove(tetromino, key)) {
			switch (key) {
				case 'a': tetromino->Left(); break;
				case 'd': tetromino->Right(); break;
				case 's': tetromino->Down(); break;
				case 0: break;
			}
		} else {
			board->StaticTetromino(tetromino);
			delete(tetromino);
			tetromino = new Tetromino(); tetromino->Init(2, 5, Tetromino::Type::I);
		}

		board->CheckScore();
		board->DrawTetrominoOnBoard(tetromino);
		board->Draw();
	}
}