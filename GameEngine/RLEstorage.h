#pragma once
#include <vector>
#include <iostream>
#include "Block.h"
#include "../CLRWindowOutput/IStorage.h"
using namespace std;
class RLEstorage : public IStorage
{
public:
	RLEstorage();
	string path;
	int x, y;
};

