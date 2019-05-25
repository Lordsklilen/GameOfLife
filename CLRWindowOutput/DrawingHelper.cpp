#include "DrawingHelper.h"
#include "../GameEngine/Block.h"

using namespace std;

DrawingHelper::DrawingHelper(int _width, int _height, int _heightSize, int _widthSize)
{
	ResetState(_width, _height, _heightSize, _widthSize);
	font = gcnew Font("Arial", 16);
	drawFormat = gcnew StringFormat();
}
void DrawingHelper::ResetState(int _width, int _height, int _heightSize, int _widthSize)
{
	width = _width;
	height = _height;
	heightSize = _heightSize;
	widthSize = _widthSize;
	elHeight = 0;
	elWidht = 0;
}

void DrawingHelper::ResetState(int _heightSize, int _widthSize)
{
	heightSize = _heightSize;
	widthSize = _widthSize;
	elHeight = 0;
	elWidht = 0;
}

void DrawingHelper::DrawBoardOptymalized(Graphics^ _g, Brush^ _gray, Brush^ _green, vector<vector<Block>> blockArray, vector<vector<Block>> previous) {
	elHeight = (height - heightSize) / heightSize;
	elWidht = (width - widthSize) / widthSize;
	for (int i = 0; i < blockArray.size(); i++) {
		for (int j = 0; j < blockArray[i].size(); j++) {
			auto element = blockArray[i][j];
			auto prevElement = previous[i][j];
			if (element.isAlive != prevElement.isAlive) {
				if (element.isAlive)
					this->DrawBlock(_g, _green, GetPos(element));
				else
					this->DrawBlock(_g, _gray, GetPos(element));
			}
		}
	}
}


void DrawingHelper::DrawBoard(Graphics^ _g, Brush^ _gray, Brush^ _green, vector<vector<Block>> blockArray) {
	elHeight = (height - heightSize) / heightSize;
	elWidht = (width - widthSize) / widthSize;
	for each (auto array in blockArray)
	{
		for each (auto element in array)
		{
			if (element.isAlive)
				this->DrawBlock(_g, _green, GetPos(element));
			else
				this->DrawBlock(_g, _gray, GetPos(element));
		}
	}
}
void DrawingHelper::DrawCounter(Graphics^ _g, Brush^ brush, int number) {
	_g->DrawString(number.ToString(), font, brush, width - 50, 0, drawFormat);
}
unique_ptr<Position> DrawingHelper::GetPos(Block block) {
	unique_ptr<Position> pos = std::make_unique<Position>();
	pos->x = (block.rowHeight * elWidht) + block.rowHeight;
	pos->y = (block.collumnWidth * elHeight) + block.collumnWidth;
	return pos;
}

void DrawingHelper::DrawBlock(Graphics^ _g, Brush^ _b, unique_ptr<Position> &pos) {
	_g->FillRectangle(
		_b,
		pos->x,
		pos->y,
		elWidht,
		elHeight
	);
}
unique_ptr<Position>  DrawingHelper::GetClickedBlockPos(int x, int y) {
	unique_ptr<Position> pos = std::make_unique<Position>();

	pos->x = x / (elWidht + 1);
	pos->y = y / (elHeight + 1);
	return pos;
};