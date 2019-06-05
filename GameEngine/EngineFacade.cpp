#include "EngineFacade.h"

using namespace std;
EngineFacade::EngineFacade() {
	this->fileManager = make_shared<RLEHelper>();
	this->mementoManager = BoardMemento<MementoStorage>();
}

EngineFacade::~EngineFacade() {}

void EngineFacade::CreateBoard(int x, int y, bool memento) {
	if (x <= 0 || y <= 0) {
		throw new exception("error while creating Board");
	}
	if (memento)
		CreateMemento();
	this->board = make_shared<Board>(x, y);
	if (!memento)
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
	this->board->blockBoard = storage.blockBoard;
	this->board->x = storage.x;
	this->board->y = storage.y;
	return make_shared<RLEstorage>(storage);

}

shared_ptr<RLEstorage> EngineFacade::LoadTemplate(string name) {
	CreateMemento();
	fs::path pathToShow("../Templates/" + name + ".rle");
	auto storage = fileManager->LoadFile(fs::absolute(pathToShow).string());
	this->board->blockBoard = storage.blockBoard;
	this->board->x = storage.x;
	this->board->y = storage.y;
	return make_shared<RLEstorage>(storage);
}

bool EngineFacade::SaveFile(string path) {
	auto state = CreateGameState(path);
	return fileManager->SaveFile(state);
}

RLEstorage EngineFacade::CreateGameState(string path) {
	CreateMemento();
	RLEstorage state = RLEstorage();
	state.blockBoard = this->board->blockBoard;
	state.path = path;
	state.x = this->board->x;
	state.y = this->board->y;
	return move(state);
}

void EngineFacade::CreateMemento() {
	vector<vector<Block>> b = GetBlockBoard();
	if (!b.empty()) {
		MementoStorage mem;
		mem.blockBoard = b;
		mementoManager.SetState(move(mem));
	}
}

void EngineFacade::RestoreMemento() {
	auto mem = mementoManager.GetState();
	if (mem != nullptr)
		board->blockBoard = mem->blockBoard;
}