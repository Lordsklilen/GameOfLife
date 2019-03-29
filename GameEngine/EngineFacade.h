#pragma once
#include <cstdio>
#include <memory>
#include "Board.h"
#include "RLEHelper.h"
#include "RLEstorage.h"
#include "../CLRWindowOutput/BoardMemento.h"
#include "../CLRWindowOutput/MementoStorage.h"

namespace fs = std::experimental::filesystem;

using namespace std;
class EngineFacade
{
private:
	shared_ptr<Board> board;
	shared_ptr<RLEHelper> fileManager;
	shared_ptr<BoardMemento> mementoManager;
	shared_ptr <RLEstorage> CreateGameState(string path);
	void CreateMemento();
	void RestoreMemento();
public:
	EngineFacade();
	~EngineFacade();
	void CreateBoard(int, int);
	shared_ptr<RLEstorage> LoadFile(string path);
	shared_ptr<RLEstorage> LoadTemplate(string name);
	bool SaveFile(string path);
	void NextIteration();
	void PreviousIteration();
	vector<vector<Block>> GetBlockBoard();
	void SetBlock(int x, int y);
};

