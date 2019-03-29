#pragma once
#include <stack>
#include "MementoStorage.h"
#include "../GameEngine/Board.h"

class BoardMemento
{
	stack<MementoStorage> mementoStack;
public:
	void SetState(MementoStorage memento);
	shared_ptr<MementoStorage> GetState();
	BoardMemento();
	~BoardMemento();
};

