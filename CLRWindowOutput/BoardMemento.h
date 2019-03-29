#pragma once
#include <stack>
#include "HistoryMemento.h"
#include "../GameEngine/Board.h"

class BoardMemento
{
	stack<HistoryMemento> stack;
public:
	void SetState(HistoryMemento board);
	shared_ptr<Board> GetState();
	BoardMemento();
	~BoardMemento();
};

