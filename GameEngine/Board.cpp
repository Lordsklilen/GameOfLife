#include "Board.h"




Board::Board(int width, int height)
{
	this->width = width;
	this->height = height;
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
	blockBoard[1][2].isAlive = true;
	blockBoard[2][2].isAlive = true;
	blockBoard[3][2].isAlive = true;
	this->blockBoard = blockBoard;
}
void Board::NextIteration() {
	copyBlockBoard = this->blockBoard;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			SetState(copyBlockBoard[i][j]);
		}
	}
}
void Board::SetState(Block& block) {
	int neighbours = CountNeighbours(block);
	if (block.isAlive) {
		if (neighbours == 2 || neighbours == 3)
			blockBoard[block.collumnWidth][block.rowHeight].isAlive = true;
		else 
			blockBoard[block.collumnWidth][block.rowHeight].isAlive = false;
	}
	else {
		if (neighbours == 3)
			blockBoard[block.collumnWidth][block.rowHeight].isAlive = true;
		else
			blockBoard[block.collumnWidth][block.rowHeight].isAlive = false;
	}
}

int Board::CountNeighbours(Block& block) {

	int counter = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i + block.collumnWidth >= width || j + block.rowHeight >= height || i + block.collumnWidth < 0 || j + block.rowHeight < 0)
				continue;
			if (copyBlockBoard[i + block.collumnWidth][j + block.rowHeight].isAlive && !(i==0 && j==0))
				counter++;
		}
	}
	return counter;
}
Board::~Board()
{
}
