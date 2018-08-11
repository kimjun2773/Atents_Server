#include "Tetromino.h"

Tetromino::Tetromino(){}
Tetromino::~Tetromino(){}

void Tetromino::Draw() {
	gotoXY(pos.x, pos.y);
}
void Tetromino::Init(int x, int y, Type t) {
	pos.x = x; pos.y = y;

	switch (t) {
	case I: {
		shape[0][0].Init(0, 0, Block::EMPTY);
		shape[0][1].Init(0, 1, Block::EMPTY);
		shape[0][2].Init(0, 2, Block::FILL);
		shape[0][3].Init(0, 3, Block::EMPTY);

		shape[1][0].Init(1, 0, Block::EMPTY);
		shape[1][1].Init(1, 1, Block::EMPTY);
		shape[1][2].Init(1, 2, Block::FILL);
		shape[1][3].Init(1, 3, Block::EMPTY);

		shape[2][0].Init(2, 0, Block::EMPTY);
		shape[2][1].Init(2, 1, Block::EMPTY);
		shape[2][2].Init(2, 2, Block::FILL);
		shape[2][3].Init(2, 3, Block::EMPTY);

		shape[3][0].Init(3, 0, Block::EMPTY);
		shape[3][1].Init(3, 1, Block::EMPTY);
		shape[3][2].Init(3, 2, Block::FILL);
		shape[3][3].Init(3, 3, Block::EMPTY); break; }
	case O: {
		shape[0][0].Init(0, 0, Block::EMPTY);
		shape[0][1].Init(0, 1, Block::EMPTY);
		shape[0][2].Init(0, 2, Block::EMPTY);
		shape[0][3].Init(0, 3, Block::EMPTY);

		shape[1][0].Init(1, 0, Block::EMPTY);
		shape[1][1].Init(1, 1, Block::EMPTY);
		shape[1][2].Init(1, 2, Block::EMPTY);
		shape[1][3].Init(1, 3, Block::EMPTY);

		shape[2][0].Init(2, 0, Block::EMPTY);
		shape[2][1].Init(2, 1, Block::FILL);
		shape[2][2].Init(2, 2, Block::FILL);
		shape[2][3].Init(2, 3, Block::EMPTY);

		shape[3][0].Init(3, 0, Block::EMPTY);
		shape[3][1].Init(3, 1, Block::FILL);
		shape[3][2].Init(3, 2, Block::FILL);
		shape[3][3].Init(3, 3, Block::EMPTY); break; }
	case T: {}
	}
}
