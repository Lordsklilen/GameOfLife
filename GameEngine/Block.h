#pragma once
class Block
{
public:
	int rowNumber;
	int collumnNumber;
	bool isAlive;
public:
	Block(int row, int collumn);
	Block();
	~Block();

};

