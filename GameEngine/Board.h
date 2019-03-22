#pragma once
#include <cstdio>
#include <vector>
#include <iostream>
#include <memory>
#include "Block.h"
using namespace std;
class Board
{

public:
	vector<vector<Block>>  blockBoard;
	Board(int,int);
	~Board();
	void NextIteration();
	void ChangeBlockState(int x, int y);
	int x;
	int y;
private:
	void SetState(shared_ptr<Block> block);
	int CountNeighbours(shared_ptr<Block> block);
	vector<vector<Block>>  copyBlockBoard;
};

