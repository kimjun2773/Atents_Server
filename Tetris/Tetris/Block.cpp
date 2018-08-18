#include "Block.h"

Block::Block(){}
Block::~Block(){}

void Block::Init(int x, int y, status stat) { pos.x = x; pos.y = y; this->stat = stat; isUpdated = true; }
Block::status Block::GetStatus() { return stat; }
void Block::SetStatus(status stat) { this->stat = stat; isUpdated = true;}

void Block::Draw() {
	if (this->isUpdated == false) return;
	
	gotoXY(pos.x, pos.y);
	switch (stat) {
		case EMPTY: std::cout << "��"; break;
		case FILL: std::cout << "��"; break;
		case BLOCKED: std::cout << "��"; break;
	}
	isUpdated = false;
}

