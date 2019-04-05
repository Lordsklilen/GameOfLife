#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <filesystem>
#include <sstream>
#include "RLEstorage.h"
using namespace std::experimental::filesystem::v1;

using namespace std;
class RLEHelper
{

	int GetNumberOfDigits(int i);
	string CreateOutputStream(RLEstorage storage);
public:
	bool SaveFile(RLEstorage storage);
	RLEstorage LoadFile(string path);
	RLEHelper();
	~RLEHelper();
};

