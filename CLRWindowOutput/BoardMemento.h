#pragma once
#include <stack>
#include "MementoStorage.h"
#include "../GameEngine/Board.h"

template <class T>
class BoardMemento
{
	stack<T> mementoStack;
public:

	void SetState(T memento) {
		mementoStack.push(memento);
	}

	shared_ptr<T> GetState() {

		if (!mementoStack.empty()) {
			auto val = make_shared<T>(mementoStack.top());
			mementoStack.pop();
			return val;
		}
		return nullptr;
	}
};