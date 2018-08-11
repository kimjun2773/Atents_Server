#pragma once
#include "Util.h"
#include "Block.h"

class Tetromino {
	public: enum Type { I, O, T, J, L, S, Z };
	public: Point pos;
	public: Block shape[4][4];

	public: Tetromino();
	public: ~Tetromino();
	public: void Init(int x, int y, Type t);
	public: void Draw();

	public: void Rotate() {}
	public: void Move() {}
	public: void Down() { pos.x++; }
	public: void Left() { pos.y--; }
	public: void Right() { pos.y++; }
}; 

