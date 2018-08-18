#pragma once
#include <iostream>
#include "Util.h"

class Block {
	public: enum status { EMPTY, FILL, BLOCKED };	
	public: Point pos;
	private: bool isUpdated;
	private: status stat;
	
	public: Block();
	public: ~Block();

	public: void Init(int x, int y, status stat);
	public: status GetStatus();
	public: void SetStatus(status stat);
	public: void Draw();
};

