#include "RLEHelper.h"
#include <string>  

RLEHelper::RLEHelper()
{
}


RLEHelper::~RLEHelper()
{
}

int RLEHelper::GetNumberOfDigits(int i)
{
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}
RLEstorage RLEHelper::LoadFile(string path) {

	RLEstorage storage = RLEstorage();
	ifstream file;
	file.open(path);
	string line;
	getline(file, line, '=');
	file >> line;
	storage.x = stoi(line);
	getline(file, line, '=');
	file >> line;
	storage.y = stoi(line);
	getline(file, line);
	char typ;
	int i = 0;
	while (getline(file, line))
	{
		storage.blockBoard.push_back(vector<Block>());
		int j = 0;
		typ = line[0];
		while (typ != '$') {
			int counter = stoi(line);
			line.erase(0, GetNumberOfDigits(counter));
			typ = line[0];
			for (int tmp = 0; tmp < counter; tmp++) {
				if (typ == 'o')
					storage.blockBoard[i].push_back(Block(j + tmp, i, true));
				else
					storage.blockBoard[i].push_back(Block(j + tmp, i, false));
			}
			line.erase(0, 1);
			j += counter;
			typ = line[0];
		}
		i++;
	}
	file.close();

	return storage;
}




bool RLEHelper::SaveFile(RLEstorage storage) {

	ofstream outfile;
	try {
		outfile.open(storage.path);
		auto stream = CreateOutputStream(move(storage));
		outfile << stream;
		outfile.close();
	}
	catch (exception& e)
	{
		return false;
	}
	return true;
}

string RLEHelper::CreateOutputStream(RLEstorage storage) {

	std::ostringstream ss;
	ss << "x = " << storage.x << ", y = " << storage.y << "\n";
	char dead = 'b';
	char alive = 'o';
	for each (auto row in storage.blockBoard)
	{
		char currentChar = 'n';
		int counter = 0;
		for each (auto cell in row)
		{
			counter++;
			if (currentChar == 'n') {
				if (cell.isAlive)
					currentChar = alive;
				else
					currentChar = dead;
			}

			if (cell.isAlive && currentChar == 'b') {
				ss << counter << dead;
				currentChar = alive;
				counter = 0;
			}
			else if (!cell.isAlive && currentChar == 'o') {
				ss << counter << alive;
				currentChar = dead;
				counter = 0;
			}
		}
		ss << counter << currentChar;
		ss << "$\n";
	}
	return ss.str();
}
