#include "EngineFacade.h"


EngineFacade::EngineFacade(){
}


EngineFacade::~EngineFacade()
{
}
Board EngineFacade::CreateBoard(int x, int y) {
	Board* b = new Board(x, y);
	return *b;
}