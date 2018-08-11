#pragma once
#include <iostream>
#include "Util.h"

class Block {
	public: enum status { EMPTY, FILL, BLOCKED };
	public: status stat;
	public: Point pos;
	
	public: Block();
	public: ~Block();

	public: void Init(int x, int y, status stat);
	public: void SetBlock(status stat);
	public: void Draw();
};

