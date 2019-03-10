#pragma once
#include "Board.h"
#include <cstdio>
#include <memory>
using namespace std;
class EngineFacade
{
private:
	Board* board;
public:
	EngineFacade();
	~EngineFacade();
	Board CreateBoard(int,int);
	Board NextIteration();
	vector<vector<Block>> GetBlockBoard();
	void SetBlock(int x, int y);
};

