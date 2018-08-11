#include "GameManager.h"

GameManager::GameManager(int boardRow, int boardCol, float tickTime) {
	timer = new TickTimer(tickTime);
	input = new InputManager();
	board = new Board(boardRow, boardCol); board->Init();
	tetromino = new Tetromino(); tetromino->Init(2, 2, Tetromino::Type::O);
}
GameManager:: ~GameManager() {}

void GameManager::Update() {
	if (timer->check()) {
		board->Draw();

		switch (input->key) {
		//case 'a': tetromino->Left(); break;
		//case 'd': tetromino->Right(); break;
		//case 's': tetromino->Down(); break;
		}
	}
}