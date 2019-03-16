#include "main.h"
#include "MainForm.h"
#include "../GameEngine/Board.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <map>

using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;
using namespace System::Threading;
using namespace std;

map<string, int> ReadConfig();
const string CONFIGPATH = "C:\\Users\\Dela_\\source\\repos\\GameOfLife\\x64\\Debug\\Config.csv";

[STAThreadAttribute]
int Main()
{
	


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm mainForm;
	mainForm.SetConfig(ReadConfig());
	Application::Run(%mainForm);
	return 0;
}

map<string, int> ReadConfig() {
	typedef std::pair<string, int> conf;
	ifstream file(CONFIGPATH);
	string value;
	string key;
	map<string, int> ConfigData;
	if (file.good())
	{
		while (getline(file, key, ':')) {
			if (getline(file, value, ';'))
				ConfigData[key] = stoi(value, nullptr);
		}
	}
	return ConfigData;
}

