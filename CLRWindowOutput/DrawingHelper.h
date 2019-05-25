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

ref class DrawingHelper
{
private:
	int width;
	int height;
	int elHeight;
	int elWidht;
	int fpsCount;
	Font^ font;
	StringFormat^ drawFormat;
public:

	int heightSize;
	int widthSize;
	void ResetState(int _width, int _height, int _heightSize, int _widthSize);
	void ResetState(int _heightSize, int _widthSize);
	DrawingHelper(int _width, int _height, int _heightSize, int _widthSize);
	void DrawBoard(Graphics^, Brush^, Brush^ ,vector<vector<Block>>);
	void DrawBoardOptymalized(Graphics^, Brush^, Brush^, vector<vector<Block>>, vector<vector<Block>>);
	void DrawCounter(Graphics^ _g, Brush^ brush, int number);
	unique_ptr<Position> GetClickedBlockPos(int, int);
private:
	unique_ptr<Position> GetPos(Block block);
	void DrawBlock(Graphics^ _g, Brush^ _b,unique_ptr<Position> &pos);
	
};

