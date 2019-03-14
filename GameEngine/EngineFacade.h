#pragma once
#include "Board.h"
#include <cstdio>
#include <memory>
using namespace std;
class EngineFacade
{
private:
	shared_ptr<Board> board;
public:
	EngineFacade();
	~EngineFacade();
	void CreateBoard(int,int);
	void NextIteration();
	vector<vector<Block>> GetBlockBoard();
	void SetBlock(int x, int y);
};

