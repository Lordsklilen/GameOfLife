#pragma once
#include <cstdio>
#include <vector>
#include <iostream>
#include <memory>
#include "../GameEngine/Block.h"
using namespace std;
class Board
{

public:
	vector<vector<Block>>  blockBoard;
	Board(int,int);
	~Board();
	void NextIteration();
	void ChangeBlockState(int x, int y);
private:
	int width;
	int height;
	void SetState(shared_ptr<Block> block);
	int CountNeighbours(shared_ptr<Block> block);
	vector<vector<Block>>  copyBlockBoard;
};

