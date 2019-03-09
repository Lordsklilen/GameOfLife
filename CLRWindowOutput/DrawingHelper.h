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
	int elWidht;
	int elHeight;
};

class DrawingHelper
{
private:
	int width;
	int height;
	int heightSize;
	int widthSize;

public:
	DrawingHelper(int _width, int _height, int _heightSize, int _widthSize);
	void DrawBoard(Graphics^ _g, Brush^ _b,vector<vector<Block>> blockArray, int _size);
private:
	unique_ptr<Position> GetPos(Block block);
	void DrawBlock(Graphics^ _g, Brush^ _b,unique_ptr<Position> &pos);
	
};

