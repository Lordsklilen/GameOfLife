#include "EngineFacade.h"



using namespace std;
EngineFacade::EngineFacade() {
	this->GetConfigFile();
	this->fileManager = make_shared<RLEHelper>();
}


EngineFacade::~EngineFacade()
{
}
void EngineFacade::CreateBoard(int x, int y) {
	this->board = make_shared<Board>(x, y);
}
void EngineFacade::NextIteration() {
	board->NextIteration();
}
vector<vector<Block>> EngineFacade::GetBlockBoard() {
	return board->blockBoard;
}

void EngineFacade::SetBlock(int x, int y) {
	board->ChangeBlockState(x, y);
};

void EngineFacade::GetConfigFile() {

}


bool EngineFacade::LoadFile(string path) {
	auto storage = fileManager->LoadFile(path);
	return true;
}
bool EngineFacade::SaveFile(string path) {
	auto state = CreateGameState(path);
	return fileManager->SaveFile(state);
}
shared_ptr<RLEstorage> EngineFacade::CreateGameState(string path) {
	shared_ptr<RLEstorage> state = make_shared<RLEstorage>();
	state->blockBoard = this->board->blockBoard;
	state->path = path;
	state->x = this->board->x;
	state->y = this->board->y;
	return state;

}