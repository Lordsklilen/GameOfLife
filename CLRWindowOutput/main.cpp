#include "main.h"
#include "MainForm.h"
#include "../GameEngine/Board.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;
using namespace System::Threading;

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CLRWindowOutput::MainForm mainForm;
	Application::Run(%mainForm);

	return 0;
}
