#include "RLEHelper.h"

RLEHelper::RLEHelper()
{
}


RLEHelper::~RLEHelper()
{
}
void RLEHelper::SaveFile(shared_ptr <RLEstorage> storage) {
	
	ofstream outfile;



	outfile.open("C:\\Users\\Dela_\\source\\repos\\GameOfLife\\x64\\Debug\\temp.rle");
	auto stream = CreateOutputStream(storage).str();
	outfile << stream;
	outfile.close();
}

ostringstream RLEHelper::CreateOutputStream(shared_ptr <RLEstorage> storage) {

	std::ostringstream ss;
	ss << "x = " << storage->x << ", y = " << storage->y << "\n";
	char dead = 'b';
	char alive = 'o';
	for each (auto row in storage->blockBoard)
	{
		char currentChar = 'n'; 
		int counter= 0;
		for each (auto cell in row)
		{
			counter++;
			if (currentChar=='n') {
				if (cell.isAlive)
					currentChar = alive;
				else
					currentChar = dead;
			}
			
			if (cell.isAlive && currentChar == 'b') {
				ss << dead << counter;
				currentChar = alive;
				counter = 0;
			}
			else if (!cell.isAlive && currentChar == 'o') {
				ss << alive << counter;
				currentChar = dead;
				counter = 0;
			}
		}
		ss << currentChar << counter;
		ss << "$\n";
	}
	return ss;
}
