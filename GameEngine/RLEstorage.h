#pragma once
#include <vector>
#include <iostream>
#include "Block.h"
using namespace std;
class RLEstorage
{
public:
	RLEstorage();
	string path;
	int x, y;
	vector<vector<Block>>  blockBoard;
};

