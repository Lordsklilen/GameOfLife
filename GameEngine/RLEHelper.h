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
	string CreateOutputStream(shared_ptr <RLEstorage> storage);
public:
	bool SaveFile(shared_ptr <RLEstorage> storage);
	shared_ptr <RLEstorage>LoadFile(string path);
	RLEHelper();
	~RLEHelper();
};

