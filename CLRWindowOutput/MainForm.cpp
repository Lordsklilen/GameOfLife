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

public ref class ThreadExecute
{
public:
	static PictureBox^ pictureBox1;
	static Brush^ grayBrush;
	static Brush^ greenBrush;
	static DrawingHelper *drawingHelper;
	static EngineFacade *engine;
	static void ThreadExecute::InitThreads(MainForm^ form) {
		pictureBox1 = form->pictureBox1;
		grayBrush = form->grayBrush;
		greenBrush = form->greenBrush;
		drawingHelper = form->drawingHelper;
		engine = form->engine;
	}
	static void ThreadExecute::ThreadProc(Object^ /*myObject*/, EventArgs^ /*myEventArgs*/)
	{
		auto bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		auto g = Graphics::FromImage((Image^)bitmap);

		engine->NextIteration();
		drawingHelper->DrawBoard(g, grayBrush, greenBrush, engine->GetBlockBoard());
		pictureBox1->Image = (Image^)bitmap;
	}
};


System::Void MainForm::startbtn_Click(System::Object^  sender, System::EventArgs^  e) {

	ThreadExecute::InitThreads(this);

	System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer;
	myTimer->Tick += gcnew EventHandler(ThreadExecute::ThreadProc);
	myTimer->Interval = 500;
	myTimer->Start();
};