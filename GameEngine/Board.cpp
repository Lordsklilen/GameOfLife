#include "Board.h"



Board::Board(int width, int height)
{
	this->x = width;
	this->y = height;
	vector<vector<Block> > blockBoard(
		width,
		vector<Block>(height)
	);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			blockBoard[i][j].collumnWidth = i;
			blockBoard[i][j].rowHeight = j;
			blockBoard[i][j].isAlive = false;
		}
	}
	this->blockBoard = blockBoard;
}
void Board::NextIteration() {
	copyBlockBoard = this->blockBoard;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			SetState(make_shared<Block>(copyBlockBoard[i][j]));
		}
	}
}
void Board::SetState(shared_ptr<Block> block) {
	int neighbours = CountNeighbours(block);
	if (block->isAlive) {
		if (neighbours == 2 || neighbours == 3)
			blockBoard[block->collumnWidth][block->rowHeight].isAlive = true;
		else
			blockBoard[block->collumnWidth][block->rowHeight].isAlive = false;
	}
	else {
		if (neighbours == 3)
			blockBoard[block->collumnWidth][block->rowHeight].isAlive = true;
		else
			blockBoard[block->collumnWidth][block->rowHeight].isAlive = false;
	}
}

int Board::CountNeighbours(shared_ptr<Block> block) {

	int counter = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int widthId = (i + block->collumnWidth) >= 0 ? (i + block->collumnWidth) % (x) : x-1;
			if ((j + block->rowHeight) >= y || (j + block->rowHeight) <= -1)
				break;
			int heightId = (j + block->rowHeight) >= 0 ? (j + block->rowHeight) % (y) : y-1;

			if (copyBlockBoard[widthId][heightId].isAlive && !(i == 0 && j == 0))
				counter++;
		}
	}
	return counter;
}
Board::~Board()
{}

void Board::ChangeBlockState(int x, int y) {
	blockBoard[x][y].ChangeState();
};