#include "Block.h"

Block::Block(){}
Block::~Block(){}

void Block::Init(int x, int y, status stat) { pos.x = x; pos.y = y; this->stat = stat; }
void Block::SetBlock(status stat) { this->stat = stat; }
void Block::Draw() {
	gotoXY(pos.x, pos.y);
	
	switch (stat) {
		case EMPTY: std::cout << "бр"; break;
		case FILL: std::cout << "в├"; break;
		case BLOCKED: std::cout << "бс"; break;
	}
}
