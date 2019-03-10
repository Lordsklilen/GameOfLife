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
	static void ThreadExecute::InitThread(MainForm^ form) {
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

void MainForm::InitProgram() {
	engine->CreateBoard(drawingHelper->heightSize, drawingHelper->widthSize);
	myTimer->Tick += gcnew EventHandler(ThreadExecute::ThreadProc);
	myTimer->Interval = 500;

	auto bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	auto g = Graphics::FromImage((Image^)bitmap);
	drawingHelper->DrawBoard(g, grayBrush, greenBrush, engine->GetBlockBoard());
	pictureBox1->Image = (Image^)bitmap;
}


void MainForm::InitVariables() {
	graphics = pictureBox1->CreateGraphics();
	greenBrush = gcnew SolidBrush(Color::Green);
	grayBrush = gcnew SolidBrush(Color::Gray);
	myTimer = gcnew System::Windows::Forms::Timer;
	drawingHelper = new DrawingHelper(graphics, greenBrush, grayBrush, pictureBox1->Width, pictureBox1->Height, 25, 50);
	engine = new EngineFacade();
}

System::Void MainForm::startbtn_Click(Object^  sender, EventArgs^  e) {

	ThreadExecute::InitThread(this);
	startbtn->Enabled = false;
	stopbtn->Enabled = true;
	myTimer->Start();
};
Void MainForm::stopbtn_Click(Object^  sender, EventArgs^  e) {
	myTimer->Stop();
	startbtn->Enabled = true;
	stopbtn->Enabled = false;
};