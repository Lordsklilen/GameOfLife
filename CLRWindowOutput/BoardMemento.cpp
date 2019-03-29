#include "BoardMemento.h"



BoardMemento::BoardMemento()
{
}


BoardMemento::~BoardMemento()
{
}
void BoardMemento::SetState(MementoStorage memento) {
	mementoStack.push(memento);
}
shared_ptr<MementoStorage> BoardMemento::GetState() {

	if(!mementoStack.empty()) {
		auto val = make_shared<MementoStorage>(mementoStack.top());
		mementoStack.pop();
		return val;
	}
	return nullptr;
}