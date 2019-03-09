#include "DrawingHelper.h"
#include "../GameEngine/Block.h"

using namespace std;

DrawingHelper::DrawingHelper(Graphics^ _g, Brush^ greenB, Brush^ grayB, int _width, int _height, int _heightSize, int _widthSize)
{
	width = _width;
	height = _height;
	heightSize = _heightSize;
	widthSize = _widthSize;
	elHeight = 0;
	elWidht = 0;
	g = &_g;
}
void DrawingHelper::DrawBoard(Graphics^ _g, Brush^ _gray, Brush^ _green,vector<vector<Block>> blockArray) {
	elHeight = (height - heightSize) / heightSize;
	elWidht = (width - widthSize) / widthSize;
	for each (auto array in blockArray)
	{
		for each (auto element in array)
		{
			if(element.isAlive)
				this->DrawBlock(_g,_green, GetPos(element));
			else
				this->DrawBlock(_g, _gray, GetPos(element));
		}
	}
}
unique_ptr<Position> DrawingHelper::GetPos(Block block){
	unique_ptr<Position> pos = std::make_unique<Position>();
	pos->x = (block.rowNumber * elWidht) + block.rowNumber;
	pos->y = (block.collumnNumber * elHeight) + block.collumnNumber;
	return pos;
}
void DrawingHelper::DrawBlock(Graphics^ _g, Brush^ _b,unique_ptr<Position> &pos) {
	_g->FillRectangle(
		_b,
		pos->x,
		pos->y,
		elWidht,
		elHeight
		);
}