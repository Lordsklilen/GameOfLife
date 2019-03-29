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

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm mainForm;
	mainForm.SetConfig(nullptr);
	Application::Run(%mainForm);
	return 0;
}

