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
	static int currentFps = 0;
	static PictureBox^ pictureBox1;
	static Brush^ grayBrush;
	static Brush^ blackBrush;
	static Brush^ greenBrush;
	static DrawingHelper^ drawingHelper;
	static Stopwatch^ stopWatch;
	static long lastTimespan;
	static Object^ thisLock;
	static Label ^FPS_number;

public:

	static void ThreadExecute::InitThread(MainForm^ form) {
		pictureBox1 = form->pictureBox1;
		FPS_number = form->FPS_number;
		grayBrush = form->grayBrush;
		greenBrush = form->greenBrush;
		drawingHelper = form->drawingHelper;
		blackBrush = gcnew SolidBrush(Color::Black);
		stopWatch = gcnew Stopwatch();
		thisLock = gcnew Object();
		stopWatch->Start();
	}

	static void ThreadExecute::ThreadProc(Object^, EventArgs^)
	{
		Monitor::Enter(thisLock);
		try
		{
			System::Drawing::Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Image);
			auto g = Graphics::FromImage((Image^)bitmap);
			auto previous = engine.GetBlockBoard();
			engine.NextIteration();
			drawingHelper->DrawBoardOptymalized(g, grayBrush, greenBrush, engine.GetBlockBoard(), previous);
			FPS_number->Text = "FPS: " + CountFps().ToString();
			pictureBox1->Image = (Image^)bitmap;
		}
		finally
		{
			Monitor::Exit(thisLock);
		}
	}

	static int CountFps() {
		auto currenttime = stopWatch->ElapsedMilliseconds + lastTimespan;
		if (currenttime >= 1000) {
			fps_counter++;
			stopWatch->Stop();
			lastTimespan = currenttime - 1000;
			currentFps = fps_counter;
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
	Maxmilisecond = 1000;
	myTimer->Tick += gcnew EventHandler(ThreadExecute::ThreadProc);
	ClearForm(false);
}

void MainForm::ClearForm(bool clear) {
	stopbtn_Click(nullptr, nullptr);
	engine.CreateBoard(drawingHelper->heightSize, drawingHelper->widthSize,clear);
	int fps = (int)numericUpDown1->Value;
	myTimer->Interval = Maxmilisecond / fps;
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
	int x = (int)X_numericUpDown2->Value;
	int y = (int)Y_numericUpDown2->Value;
	width = storage == nullptr ? x : storage->y;
	height = storage == nullptr ? y : storage->x;
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

	ThreadExecute::InitThread(this);
	myTimer->Start();
	startbtn->Enabled = false;
	stopbtn->Enabled = true;
	numericUpDown1->Enabled = false;
};

Void MainForm::stopbtn_Click(Object^  sender, EventArgs^  e) {
	myTimer->Stop();
	startbtn->Enabled = true;
	stopbtn->Enabled = false;
	numericUpDown1->Enabled = true;
};

Void MainForm::pictureBox1_MouseClick(Object^  sender, MouseEventArgs^  e) {

	auto pos = drawingHelper->GetClickedBlockPos(e->Location.X, e->Location.Y);
	if (pos->x >= width || pos->y >= height)
		return;
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

Void MainForm::saveGameStateToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
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

Void MainForm::loadGameStateToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
	stopbtn_Click(nullptr, nullptr);
	OpenFileDialog ^ sfd = gcnew OpenFileDialog();
	string path = "";
	sfd->Filter = "Pliki RLE (*.rle)|*.rle|Wszystkie pliki (*.*)|*.*";
	if (sfd->ShowDialog() == ::DialogResult::OK)
	{
		MarshalString(sfd->FileName->ToString(), path);
		auto storage = engine.LoadFile(path);
		width = storage == nullptr ? 50 : storage->y;
		height = storage == nullptr ? 25 : storage->x;
		if (storage != nullptr) {
			X_numericUpDown2->Value = storage->y;
			Y_numericUpDown2->Value = storage->x;
		}
		drawingHelper->ResetState(height, width);
		RedrawBoard();
	}
}

Void MainForm::templateToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
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
	ThreadExecute::ThreadProc(nullptr, nullptr);
}

Void MainForm::PrevBtn_Click(Object^  sender, EventArgs^  e) {
	engine.PreviousIteration();
	RedrawBoard();
}

Void MainForm::numericUpDown1_ValueChanged(Object^  sender, EventArgs^  e) {
	int fps = (int)numericUpDown1->Value;
	if (Maxmilisecond / fps <= 26)
		myTimer->Interval = 10;
	else
		myTimer->Interval = Maxmilisecond / fps;
}

Void MainForm::newGame_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	SetConfig(nullptr);
}
Void MainForm::clear_btn_Click(System::Object^  sender, System::EventArgs^  e) {
	ClearForm(true);
}