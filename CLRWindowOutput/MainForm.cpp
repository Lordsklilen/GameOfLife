#include "MainForm.h"
#include "../GameEngine/Board.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CLRWindowOutput;
using namespace System::Threading;
using namespace System::Diagnostics;

EngineFacade  engine;

public ref class ThreadExecute
{
	static bool done = true;
	static int fps_counter = 0;
	static int fps_per_second = 0;
	static double currentFps = 0;
	static PictureBox^ pictureBox1;
	static Brush^ grayBrush;
	static Brush^ blackBrush;
	static Brush^ greenBrush;
	static DrawingHelper^ drawingHelper;
	static Stopwatch^ stopWatch;
	static TimeSpan^ lastTimespan;
public:
	static void ThreadExecute::InitThread(MainForm^ form) {
		pictureBox1 = form->pictureBox1;
		grayBrush = form->grayBrush;
		greenBrush = form->greenBrush;
		drawingHelper = form->drawingHelper;
		blackBrush = gcnew SolidBrush(Color::Black);
		stopWatch = gcnew Stopwatch();
		stopWatch->Start();
	}

	static void ThreadExecute::ThreadProc(Object^, EventArgs^)
	{
		if (done) {
			done = false;
			auto bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			auto g = Graphics::FromImage((Image^)bitmap);

			engine.NextIteration();
			drawingHelper->DrawBoard(g, grayBrush, greenBrush, engine.GetBlockBoard());

			drawingHelper->DrawCounter(g, blackBrush, CountFps());
			pictureBox1->Image = (Image^)bitmap;
			done = true;
		}
	}

	static int CountFps() {
		auto currenttime = stopWatch->ElapsedMilliseconds;
		if (currenttime > 1000) {
			fps_counter++;
			stopWatch->Stop();
			currentFps = fps_counter+1;
			stopWatch->Reset();
			fps_counter = 0;
			stopWatch->Start();
		}
		else
			fps_counter++;
		return currentFps;
	}
};

void MainForm::InitProgram() {
	engine.CreateBoard(drawingHelper->heightSize, drawingHelper->widthSize);
	myTimer->Tick += gcnew EventHandler(ThreadExecute::ThreadProc);
	myTimer->Interval = 5;
	RedrawBoard();
}

void MainForm::InitVariables() {
	graphics = pictureBox1->CreateGraphics();
	greenBrush = gcnew SolidBrush(Color::Green);
	grayBrush = gcnew SolidBrush(Color::Gray);
	myTimer = gcnew System::Windows::Forms::Timer;
	drawingHelper = gcnew DrawingHelper(pictureBox1->Width, pictureBox1->Height, height, width);
	engine = EngineFacade();
	ThreadExecute::InitThread(this);
}

void MainForm::SetConfig(shared_ptr<RLEstorage> storage) {
	width = storage==nullptr? 50: storage->y;
	height = storage == nullptr? 25 : storage->x;
	InitVariables();
	InitProgram();
}

void MainForm::RedrawBoard() {
	auto bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	auto g = Graphics::FromImage((Image^)bitmap);
	drawingHelper->DrawBoard(g, grayBrush, greenBrush, engine.GetBlockBoard());
	pictureBox1->Image = (Image^)bitmap;
}

Void MainForm::startbtn_Click(Object^  sender, EventArgs^  e) {

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

void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

Void MainForm::saveGameStateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	string path = "";
	sfd->Filter = "Pliki RLE (*.rle)|*.rle|Wszystkie pliki (*.*)|*.*";
	if (sfd->ShowDialog() == ::DialogResult::OK)
	{
		MarshalString(sfd->FileName->ToString(), path);
		if (engine.SaveFile(path)) {
			MessageBox::Show("Saved successfully", "Save state");
		}
		else {
			MessageBox::Show("Error occured", "Something went wrong");
		}
	}
}

Void MainForm::loadGameStateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog ^ sfd = gcnew OpenFileDialog();
	string path = "";
	sfd->Filter = "Pliki RLE (*.rle)|*.rle|Wszystkie pliki (*.*)|*.*";
	if (sfd->ShowDialog() == ::DialogResult::OK)
	{
		MarshalString(sfd->FileName->ToString(), path);
		auto storage = engine.LoadFile(path);
		width = storage == nullptr ? 50 : storage->y;
		height = storage == nullptr ? 25 : storage->x;
		drawingHelper->ResetState(height, width);
		RedrawBoard();
	}
}

Void MainForm::templateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	auto senderText = ((ToolStripMenuItem^)sender);
	string name;
	MarshalString(senderText->Text, name);
	auto storage = engine.LoadTemplate(name);
	width = storage == nullptr ? 50 : storage->y;
	height = storage == nullptr ? 25 : storage->x;
	drawingHelper->ResetState(height, width);
	RedrawBoard();
}

Void MainForm::NextBtn_Click(Object^  sender, EventArgs^  e) {
	ThreadExecute::ThreadProc(nullptr,nullptr);
}

Void MainForm::PrevBtn_Click(Object^  sender, EventArgs^  e) {
	engine.PreviousIteration();
	RedrawBoard();
}