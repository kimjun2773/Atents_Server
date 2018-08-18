#pragma once
#include "Block.h"
#include "Tetromino.h"

class Board {
	public: Block ** lines;
	private: int row; int col;

	public: Board(int row, int col);
	public: ~Board();
	
	public: void Init();
	public: void Draw();
	public: void DrawTetrominoOnBoard(Tetromino* ref);
	public: bool OkToMove(Tetromino* ref, int key);
	public: void StaticTetromino(Tetromino* ref);
	public: void CheckScore();

	private: bool CheckLine(int line);
	private: void FlushLine(int line);
};

