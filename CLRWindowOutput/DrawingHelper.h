#pragma once
#include <cstdio>
#include <vector>
#include <memory>
#include "../GameEngine/Block.h"
using namespace System::Drawing;
using namespace std;

struct Position {
	int x;
	int y;
};

class DrawingHelper
{
private:
	int width;
	int height;
	int elHeight;
	int elWidht;
public:

	int heightSize;
	int widthSize;
	DrawingHelper(Graphics^ _g, Brush^ greenB, Brush^ grayB,int _width, int _height, int _heightSize, int _widthSize);
	void DrawBoard(Graphics^, Brush^, Brush^ ,vector<vector<Block>>);
private:
	unique_ptr<Position> GetPos(Block block);
	void DrawBlock(Graphics^ _g, Brush^ _b,unique_ptr<Position> &pos);
	
};

