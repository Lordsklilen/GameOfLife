#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;

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

