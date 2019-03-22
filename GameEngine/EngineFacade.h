#pragma once
#include <cstdio>
#include <memory>
#include "Board.h"
#include "RLEHelper.h"
#include "RLEstorage.h"

using namespace std;
class EngineFacade
{
private:
	shared_ptr<Board> board;
	shared_ptr<RLEHelper> fileManager;
	void GetConfigFile();
public:
	EngineFacade();
	~EngineFacade();
	void CreateBoard(int, int);
	void LoadFile(string path);
	void SaveFile(string path);
	void NextIteration();
	vector<vector<Block>> GetBlockBoard();
	void SetBlock(int x, int y);
};

