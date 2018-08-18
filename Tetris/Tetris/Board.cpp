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
bool Board::OkToMove(Tetromino* ref, int key) {
	Tetromino copy = *ref;

	switch (key){
		case 'a': copy.Left(); break;
		case 's': copy.Down(); break;
		case 'd': copy.Right(); break;
	}

	for (int i=0 ; i<4 ; ++i) {
		for (int j=0 ; j<4 ; ++j) {
			Block::status tetroStat = copy.shape[i][j].GetStatus();
			Block::status boardStat = lines[copy.pos.x + i][copy.pos.y + j].GetStatus();
			
			if (boardStat == Block::BLOCKED && tetroStat != Block::EMPTY) { return false; }
		}
	}
	return true;
}
void Board::DrawTetrominoOnBoard(Tetromino* ref) {
	Tetromino copy = *ref;

	for (int i=0 ; i<4 ; ++i) {
		for (int j=0 ; j<4 ; ++j) {
			Block::status tetroStat = copy.shape[i][j].GetStatus();
			Block::status boardStat = lines[copy.pos.x + i][copy.pos.y + j].GetStatus();

			if (tetroStat == Block::EMPTY && boardStat == Block::FILL) {
				lines[copy.pos.x + i][copy.pos.y + j].SetStatus(Block::EMPTY);
			}
			else if (tetroStat == Block::FILL && boardStat == Block::EMPTY) {
				lines[copy.pos.x + i][copy.pos.y + j].SetStatus(Block::FILL);
			}
		}
	}
}
void Board::StaticTetromino(Tetromino* ref) {
	Tetromino copy = *ref;

	for (int i = 0; i<4; ++i) {
		for (int j = 0; j<4; ++j) {
			Block::status tetroStat = copy.shape[i][j].GetStatus();

			if (tetroStat == Block::FILL) {
				lines[copy.pos.x + i][copy.pos.y + j].SetStatus(Block::BLOCKED);
			}
		}
	}
}
void Board::CheckScore() {
	for (int i=1 ; i<row-1 ; ++i) {
		if (CheckLine(i) == true) {
			FlushLine(i);
		}
	}
}
bool Board::CheckLine(int line) {
	for (int i=1 ; i<col-1 ; ++i) {
		if (lines[line][i].GetStatus() != Block::BLOCKED) return false;
	}

	return true;
}

void Board::FlushLine(int line) {
	for (int i=1 ; i<col-1 ; ++i)
		lines[line][i].SetStatus(Block::EMPTY);
}
