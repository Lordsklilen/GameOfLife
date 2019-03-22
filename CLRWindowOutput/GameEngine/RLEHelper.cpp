#include "RLEHelper.h"

RLEHelper::RLEHelper()
{
}


RLEHelper::~RLEHelper()
{
}
void RLEHelper::SaveFile(shared_ptr <RLEstorage> storage) {
	
	ofstream outfile;
	outfile.open("C:\\Users\\Dela_\\source\\repos\\GameOfLife\\x64\\Debug\\elo.csv");
	outfile << "test";
}
