#include "MainForm.h"
#include "../GameEngine/Board.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CLRWindowOutput::MainForm mainForm;
	Application::Run(%mainForm);

	return 0;
}
System::Void MainForm::startbtn_Click(System::Object^  sender, System::EventArgs^  e) {
	
	engine->CreateBoard(drawingHelper->heightSize, drawingHelper->widthSize);
	drawingHelper->DrawBoard(graphics, grayBrush, greenBrush, engine->GetBlockBoard());
	for (int i = 0; i < 5; i++) {
		engine->NextIteration();
		System::Threading::Thread::Sleep(1000);
		drawingHelper->DrawBoard(graphics, grayBrush, greenBrush, engine->GetBlockBoard());
	}
}; 