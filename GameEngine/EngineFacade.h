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
	shared_ptr <RLEstorage> CreateGameState(string path);
public:
	EngineFacade();
	~EngineFacade();
	void CreateBoard(int, int);
	shared_ptr<RLEstorage> LoadFile(string path);
	bool SaveFile(string path);
	void NextIteration();
	vector<vector<Block>> GetBlockBoard();
	void SetBlock(int x, int y);
};

