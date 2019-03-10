#pragma once
#include <cstdio>
#include <vector>
#include "../GameEngine/Block.h"
using namespace std;
class Board
{

public:
	vector<vector<Block>>  blockBoard;
	vector<vector<Block>>  copyBlockBoard;
	Board(int,int);
	~Board();
	void NextIteration();
	void ChangeBlockState(int x, int y);
private:
	int width;
	int height;
	void SetState(Block&);
	int CountNeighbours(Block&);
};

