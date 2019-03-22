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
	ostringstream CreateOutputStream(shared_ptr <RLEstorage> storage);
public:
	void SaveFile(shared_ptr <RLEstorage> storage);
	shared_ptr <RLEstorage>LoadFile(string path);
	RLEHelper();
	~RLEHelper();
};

