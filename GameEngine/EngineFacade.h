#pragma once
#include "Board.h"
#include <cstdio>
#include <memory>
using namespace std;
class EngineFacade
{
private:
public:
	EngineFacade();
	~EngineFacade();
	Board CreateBoard(int,int);
	//Board getBoard();
};

