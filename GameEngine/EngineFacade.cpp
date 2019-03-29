#include "EngineFacade.h"



using namespace std;
EngineFacade::EngineFacade() {
	this->fileManager = make_shared<RLEHelper>();
	this->mementoManager = make_shared<BoardMemento>();
}
EngineFacade::~EngineFacade() {}

void EngineFacade::CreateBoard(int x, int y) {
	this->board = make_shared<Board>(x, y);
	CreateMemento();
}

void EngineFacade::NextIteration() {
	CreateMemento();
	board->NextIteration();
}

void EngineFacade::PreviousIteration() {
	RestoreMemento();
}

vector<vector<Block>> EngineFacade::GetBlockBoard() {
	return board->blockBoard;
}

void EngineFacade::SetBlock(int x, int y) {
	CreateMemento();
	board->ChangeBlockState(x, y);
};

shared_ptr<RLEstorage> EngineFacade::LoadFile(string path) {
	CreateMemento();
	auto storage = fileManager->LoadFile(path);
	this->board->blockBoard = storage->blockBoard;
	this->board->x = storage->x;
	this->board->y = storage->y;
	return storage;
}

shared_ptr<RLEstorage> EngineFacade::LoadTemplate(string name) {
	CreateMemento();
	fs::path pathToShow("../Templates/" + name + ".rle");
	auto storage = fileManager->LoadFile(fs::absolute(pathToShow).string());
	this->board->blockBoard = storage->blockBoard;
	this->board->x = storage->x;
	this->board->y = storage->y;
	return storage;
}

bool EngineFacade::SaveFile(string path) {
	auto state = CreateGameState(path);
	return fileManager->SaveFile(state);
}

shared_ptr<RLEstorage> EngineFacade::CreateGameState(string path) {
	CreateMemento();
	shared_ptr<RLEstorage> state = make_shared<RLEstorage>();
	state->blockBoard = this->board->blockBoard;
	state->path = path;
	state->x = this->board->x;
	state->y = this->board->y;
	return state;
}

void EngineFacade::CreateMemento() {
	MementoStorage mem;
	mem.blockBoard = GetBlockBoard();
	mementoManager->SetState(mem);
}

void EngineFacade::RestoreMemento() {
	auto mem = mementoManager->GetState();
	if(mem != nullptr)
		board->blockBoard = mem->blockBoard;
}