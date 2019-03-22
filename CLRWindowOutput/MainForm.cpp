#include "MainForm.h"
#include "../GameEngine/Board.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;
using namespace System::Threading;
EngineFacade  engine;
public ref class ThreadExecute
{
public:
	static PictureBox^ pictureBox1;
	static Brush^ grayBrush;
	static Brush^ greenBrush;
	static DrawingHelper^ drawingHelper;
	static void ThreadExecute::InitThread(MainForm^ form) {
		pictureBox1 = form->pictureBox1;
		grayBrush = form->grayBrush;
		greenBrush = form->greenBrush;
		drawingHelper = form->drawingHelper;
	}
	static void ThreadExecute::ThreadProc(Object^, EventArgs^)
	{
		auto bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		auto g = Graphics::FromImage((Image^)bitmap);

		engine.NextIteration();
		drawingHelper->DrawBoard(g, grayBrush, greenBrush, engine.GetBlockBoard());
		pictureBox1->Image = (Image^)bitmap;
	}
};

void MainForm::InitProgram() {
	engine.CreateBoard(drawingHelper->heightSize, drawingHelper->widthSize);
	myTimer->Tick += gcnew EventHandler(ThreadExecute::ThreadProc);
	myTimer->Interval = 250;
	RedrawBoard();
}


void MainForm::InitVariables() {
	graphics = pictureBox1->CreateGraphics();
	greenBrush = gcnew SolidBrush(Color::Green);
	grayBrush = gcnew SolidBrush(Color::Gray);
	myTimer = gcnew System::Windows::Forms::Timer;
	drawingHelper = gcnew DrawingHelper(graphics, greenBrush, grayBrush, pictureBox1->Width, pictureBox1->Height, height, width);
	engine = EngineFacade();
}

void MainForm::SetConfig(map<string, int> ConfigData) {
	width = ConfigData["width"];
	height = ConfigData["height"];
	InitVariables();
	InitProgram();
}

void MainForm::RedrawBoard() {
	auto bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	auto g = Graphics::FromImage((Image^)bitmap);
	drawingHelper->DrawBoard(g, grayBrush, greenBrush, engine.GetBlockBoard());
	pictureBox1->Image = (Image^)bitmap;
}

System::Void MainForm::startbtn_Click(Object^  sender, EventArgs^  e) {

	ThreadExecute::InitThread(this);
	myTimer->Start();
	startbtn->Enabled = false;
	stopbtn->Enabled = true;
};

Void MainForm::stopbtn_Click(Object^  sender, EventArgs^  e) {
	myTimer->Stop();
	startbtn->Enabled = true;
	stopbtn->Enabled = false;
};

Void MainForm::pictureBox1_MouseClick(Object^  sender, MouseEventArgs^  e) {

	auto pos = drawingHelper->GetClickedBlockPos(e->Location.X, e->Location.Y);
	engine.SetBlock(pos->y, pos->x);
	RedrawBoard();
};
Void MainForm::saveGameStateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	engine.SaveFile("./");
	MessageBox::Show("Saved successfully", "Save state");
}


