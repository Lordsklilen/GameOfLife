#include "DrawingHelper.h"
#include "../GameEngine/Block.h"

using namespace std;

DrawingHelper::DrawingHelper(int _width, int _height, int _heightSize, int _widthSize)
{
	width = _width;
	height = _height;
	heightSize = _heightSize;
	widthSize = _widthSize;
}
void DrawingHelper::DrawBoard(Graphics^ _g, Brush^ _b,vector<vector<Block>> blockArray, int size) {
	for each (auto array in blockArray)
	{
		for each (auto element in array)
		{
			unique_ptr<Position> pos = GetPos(element);
			this->DrawBlock(_g,_b,std::move(pos));
		}
	}
}
unique_ptr<Position> DrawingHelper::GetPos(Block block){
	unique_ptr<Position> pos = std::make_unique<Position>();
	pos->elHeight = (height - heightSize) / heightSize;
	pos->elWidht = (width - widthSize) / widthSize;
	pos->x = (block.rowNumber * pos->elWidht) + block.rowNumber;
	pos->y = (block.collumnNumber * pos->elHeight) + block.collumnNumber;
	return pos;
}
void DrawingHelper::DrawBlock(Graphics^ _g, Brush^ _b,unique_ptr<Position> &pos) {
	_g->FillRectangle(
		_b,
		pos->x,
		pos->y,
		pos->elWidht,
		pos->elHeight
		);
}