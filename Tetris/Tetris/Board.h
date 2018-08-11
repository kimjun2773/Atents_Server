#pragma once
#include "Block.h"

class Board {
	public: Block ** lines;
	private: int row; int col;

	public: Board(int row, int col);
	public: ~Board();
	
	public: void Init();
	public: void Draw();
	public: bool CheckBlock(int row, int col);
};

