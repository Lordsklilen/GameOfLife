#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;
[STAThreadAttribute]
int Main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CLRWindowOutput::MainForm mainForm;
	Application::Run(%mainForm);
	return 0;
}
System::Void MainForm::startbtn_Click(System::Object^  sender, System::EventArgs^  e) {
	graphics->FillRectangle(greenBrush, 0, 100, 200, 300);
};