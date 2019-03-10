#include "Block.h"



Block::Block(int row, int collumn)
{
	rowHeight = row;
	collumnWidth = collumn;
	isAlive = false;
}
void Block::ChangeState() {
	isAlive = !isAlive;
}

Block::Block(){}

Block::~Block()
{
}
