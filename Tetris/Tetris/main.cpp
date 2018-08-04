#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;

void gotoXY(int x, int y) {
	COORD pos = { y*2, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct Point { public: int x; int y; };
class Block {
	public: enum status { EMPTY, FILL, BLOCKED };
	public: status stat;
	public: Point pos;

	private: bool isUpdated;

	public: void Init(int x, int y, status stat) 
	{ pos.x = x; pos.y = y; this->stat = stat; isUpdated = true; }

	public: void Draw() {
		if (!isUpdated) return;

		gotoXY(pos.x, pos.y);
		switch (stat) {
			case EMPTY: cout << "□"; break;
			case FILL: cout << "▣"; break;
			case BLOCKED: cout << "■"; break;
		}
		isUpdated = false;
	}

	public: void SetBlock(status stat) {
		this->stat = stat;
		isUpdated = true;
	}
};

class Board {
	public: Block** lines;

	private: int row; int col;

	public: Board(int row, int col): row(row), col(col) {
		lines = new Block* [col];
		for (int i=0 ; i<row ; ++i) { lines[i] = new Block[col]; }
	}

	public: void Init() {
		for (int i=0 ; i<col ; ++i) { lines[0][i].Init(0, i, Block::BLOCKED); }
		for (int i=0 ; i<col ; ++i) { lines[row-1][i].Init(row-1, i, Block::BLOCKED); }
		for (int i=1 ; i<row-1 ; ++i) { 
			for (int j = 0; j < col; ++j) {
				if ((j == 0) || (j == col - 1)) lines[i][j].Init(i, j, Block::BLOCKED);
				else lines[i][j].Init(i, j, Block::EMPTY);
			}
		}
	}

	public: void Draw() {
		for (int i=0 ; i<row ; ++i) 
			for (int j=0 ; j<col ; ++j)
				lines[i][j].Draw();
	}

	public: bool CheckBlock(int row, int col) {
		if (lines[row][col].stat != Block::EMPTY) return false;
		return true;
	}

	void ddd() {
		thread t1([]() {
			while(1) cout << "helloworld" << endl;
		});
	}
};

class Tetromino {
	public: Board* targetBoard;
	public: Point pos;
	public: enum Type { I, O, T, J, L, S, Z };

	public: Block shape[4][4];
	public: void Init(int x, int y, Type t, Board* targetBoard);

	public: void Rotate() {}
	public: void Move() {}
	public: void Down() {}

	public: void Draw() {
		for (int i=0 ; i<4 ; ++i) {
			for (int j=0 ; j<4 ; ++j) {
				gotoXY(pos.x + i, pos.y + j);
				if (targetBoard->lines[pos.x + i][pos.y + j].stat == Block::BLOCKED || this->shape[i][j].stat == Block::BLOCKED)
					cout << "■";
				else if(targetBoard->lines[pos.x + i][pos.y + j].stat == Block::FILL || this->shape[i][j].stat == Block::FILL)
					cout << "▣";
				else 
					cout << "□";
			}
		}
	}
};

class InputManager {
	public: int key;
	//스태틱 람다 -> 클래스 함수를 스레드로 쓰는 방법 두가지
	public: void GetKey() {
		while (1) {

		}
	}
};

int main() {
	Board board(20, 15); board.Init();
	Tetromino iTetromino;
	iTetromino.Init(1, 1, Tetromino::O, &board);
	
	//thread th([]() {board.draw()});
	//iTetromino.Draw();
	board.ddd();
	return 0;
}

void Tetromino::Init(int x, int y, Type t, Board* targetBoard) {
	this->targetBoard = targetBoard;
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
		shape[3][3].Init(3, 3, Block::EMPTY); break;}
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