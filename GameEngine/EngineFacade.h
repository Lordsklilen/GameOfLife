#pragma once
#include <cstdio>
#include <memory>
#include "Board.h"
#include "RLEHelper.h"
#include "RLEstorage.h"
namespace fs = std::experimental::filesystem;

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
	shared_ptr<RLEstorage> LoadTemplate(string name);
	bool SaveFile(string path);
	void NextIteration();
	//TODO 
	void PreviousIteration();
	vector<vector<Block>> GetBlockBoard();
	void SetBlock(int x, int y);
};

