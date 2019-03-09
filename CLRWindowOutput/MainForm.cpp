#include "MainForm.h"
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
	vector<vector<Block> > vec(
		10,
		vector<Block>(10)
	);
	for(int i =0 ;i< 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			vec[i][j].collumnNumber = i;
			vec[i][j].rowNumber = j;
		}
	}
	drawingHelper->DrawBoard(graphics, greenBrush, vec, 10);

};