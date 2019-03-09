#pragma once
#include <cstdio>
#include <vector>
#include "../GameEngine/Block.h"
using namespace System::Drawing;
using namespace std;
class DrawingHelper
{
public:
	DrawingHelper(int _width,int _height);
	void DrawBoard(Graphics^ g, vector<vector<Block>> blockArray, int _size);
private:
	int width;
	int height;
	int size;
};

