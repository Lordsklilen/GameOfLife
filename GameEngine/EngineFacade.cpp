#include "EngineFacade.h"



using namespace std;
EngineFacade::EngineFacade(){
	this->GetConfigFile();
	this->fileManager = make_shared<RLEHelper>();
}


EngineFacade::~EngineFacade()
{
}
void EngineFacade::CreateBoard(int x, int y) {
	this->board = make_shared<Board>(x,y);
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


void EngineFacade::LoadFile(string path) {

}
void EngineFacade::SaveFile(string path) {


}