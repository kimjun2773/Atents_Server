#include "Board.h"

Board::Board(int row, int col) : row(row), col(col) {
	lines = new Block*[col];
	for (int i = 0; i<row; ++i) { lines[i] = new Block[col]; }
}
Board::~Board() {}

void Board::Init() {
	for (int i = 0; i<col; ++i) { lines[0][i].Init(0, i, Block::BLOCKED); }
	for (int i = 0; i<col; ++i) { lines[row - 1][i].Init(row - 1, i, Block::BLOCKED); }
	for (int i = 1; i<row - 1; ++i) {
		for (int j = 0; j < col; ++j) {
			if ((j == 0) || (j == col - 1)) lines[i][j].Init(i, j, Block::BLOCKED);
			else lines[i][j].Init(i, j, Block::EMPTY);
		}
	}
}

void Board::Draw() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			lines[i][j].Draw();
		}
	}
}

bool Board::CheckBlock(int row, int col) {
	if (lines[row][col].stat != Block::EMPTY) return false;
	return true;
}
