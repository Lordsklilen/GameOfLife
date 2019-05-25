#pragma once
#include <omp.h>
class Block
{
public:
	int rowHeight;
	int collumnWidth;
	bool isAlive;
public:
	Block(int row, int collumn);
	Block(int row, int collumn,bool alive);
	Block();
	~Block();
	void ChangeState();

};

