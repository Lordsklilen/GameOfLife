#pragma once
#include <vector>
#include <iostream>
#include "../GameEngine/Block.h"
#include "../CLRWindowOutput/IStorage.h"
using namespace std;
public class IStorage
{
public:

	vector<vector<Block>>  blockBoard;
	IStorage();
	~IStorage();
};

