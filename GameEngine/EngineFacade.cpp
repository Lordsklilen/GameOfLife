#include "EngineFacade.h"


EngineFacade::EngineFacade(){
}


EngineFacade::~EngineFacade()
{
}
Board EngineFacade::CreateBoard(int x, int y) {
	this->board = new Board(x, y);
	return *board;
}
Board EngineFacade::NextIteration() {
	board->NextIteration();
	return *board;
}
vector<vector<Block>> EngineFacade::GetBlockBoard() {
	return board->blockBoard;
}

void EngineFacade::SetBlock(int x, int y) {
	board->ChangeBlockState(x, y);
};