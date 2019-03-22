#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <filesystem>
#include "RLEstorage.h"
using namespace std::experimental::filesystem::v1;

using namespace std;
class RLEHelper
{
public:
	void SaveFile(RLEstorage storage);
	RLEstorage LoadFile(string path);
	RLEHelper();
	~RLEHelper();
};

