#include "Block.h"



Block::Block(int row, int collumn)
{
	rowHeight = row;
	collumnWidth = collumn;
	isAlive = false;
}

Block::Block(){}

Block::~Block()
{
}
