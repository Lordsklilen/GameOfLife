#include "Board.h"




Board::Board(int width, int height)
{
	vector<vector<Block> > blockBoard(
		width,
		vector<Block>(height)
	);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			blockBoard[i][j].collumnNumber = i;
			blockBoard[i][j].rowNumber = j;
			blockBoard[i][j].isAlive = false;
		}
	}
	blockBoard[10][11].isAlive = true;
	blockBoard[10][12].isAlive = true;
	blockBoard[10][13].isAlive = true;
	this->blockBoard = blockBoard;
}


Board::~Board()
{
}
