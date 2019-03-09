#pragma once
#include <cstdio>
#include <vector>
#include "../GameEngine/Block.h"
using namespace std;
class Board
{

public:
	vector<vector<Block>>  blockBoard;
	Board(int,int);
	~Board();

};

