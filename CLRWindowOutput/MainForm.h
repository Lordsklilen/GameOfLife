#pragma once
#include "DrawingHelper.h"
#include "../GameEngine/EngineFacade.h"
#include <string>
#include <map>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace CLRWindowOutput {

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm()
		{
			InitializeComponent();
		}
		Void startbtn_Click(Object^  sender, EventArgs^  e);
		Void stopbtn_Click(Object^  sender, EventArgs^  e);
		Void pictureBox1_MouseClick(Object^  sender, MouseEventArgs^  e);
		Void saveGameStateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
		Void loadGameStateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void templateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void clear_btn_Click(System::Object^  sender, System::EventArgs^  e);
		Void NextBtn_Click(System::Object^  sender, System::EventArgs^  e);
		Void PrevBtn_Click(System::Object^  sender, System::EventArgs^  e);
		Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		Void newGame_btn_Click(System::Object^  sender, System::EventArgs^  e);
		void InitProgram();
		void InitVariables();
		void RedrawBoard();
		void MainForm::ClearForm(bool memento);
		void SetConfig(shared_ptr<RLEstorage> storage);

	private: System::Windows::Forms::ToolStripMenuItem^  gosperGliderGunToolStripMenuItem;
	public: System::Windows::Forms::Button^  newGame_btn;
	private:
	private: System::Windows::Forms::NumericUpDown^  X_numericUpDown2;
	public:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  Y_numericUpDown2;
	public:
		int Maxmilisecond;
	protected:

		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		int width;
		int height;
		PictureBox^  pictureBox1;
		Button^  startbtn;
		System::ComponentModel::Container ^components;
		Graphics^ graphics;
		Brush^ greenBrush;
		Brush^ grayBrush;
		DrawingHelper^ drawingHelper;
		Button^  stopbtn;
		Label^  FPS_number;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveGameStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadGameStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mapTemplatesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  acornToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blinkerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copperheadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  diehardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gliderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearWindowToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  queenBeeShuttleToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	//private: System::Windows::Forms::Label^  FPS_number;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;

	public:
		System::Windows::Forms::Timer^ myTimer;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->startbtn = (gcnew System::Windows::Forms::Button());
			this->stopbtn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveGameStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadGameStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mapTemplatesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acornToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blinkerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copperheadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diehardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gliderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->queenBeeShuttleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gosperGliderGunToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearWindowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->newGame_btn = (gcnew System::Windows::Forms::Button());
			this->X_numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Y_numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->FPS_number = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X_numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Y_numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 56);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1042, 512);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseClick);
			// 
			// startbtn
			// 
			this->startbtn->Location = System::Drawing::Point(12, 27);
			this->startbtn->Name = L"startbtn";
			this->startbtn->Size = System::Drawing::Size(75, 23);
			this->startbtn->TabIndex = 1;
			this->startbtn->Text = L"Start";
			this->startbtn->UseVisualStyleBackColor = true;
			this->startbtn->Click += gcnew System::EventHandler(this, &MainForm::startbtn_Click);
			// 
			// stopbtn
			// 
			this->stopbtn->Enabled = false;
			this->stopbtn->Location = System::Drawing::Point(93, 27);
			this->stopbtn->Name = L"stopbtn";
			this->stopbtn->Size = System::Drawing::Size(75, 23);
			this->stopbtn->TabIndex = 2;
			this->stopbtn->Text = L"Stop";
			this->stopbtn->UseVisualStyleBackColor = true;
			this->stopbtn->Click += gcnew System::EventHandler(this, &MainForm::stopbtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->mapTemplatesToolStripMenuItem, this->clearWindowToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1073, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveGameStateToolStripMenuItem,
					this->loadGameStateToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveGameStateToolStripMenuItem
			// 
			this->saveGameStateToolStripMenuItem->Name = L"saveGameStateToolStripMenuItem";
			this->saveGameStateToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->saveGameStateToolStripMenuItem->Text = L"Save game state";
			this->saveGameStateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveGameStateToolStripMenuItem_Click);
			// 
			// loadGameStateToolStripMenuItem
			// 
			this->loadGameStateToolStripMenuItem->Name = L"loadGameStateToolStripMenuItem";
			this->loadGameStateToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->loadGameStateToolStripMenuItem->Text = L"Load game state";
			this->loadGameStateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::loadGameStateToolStripMenuItem_Click);
			// 
			// mapTemplatesToolStripMenuItem
			// 
			this->mapTemplatesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->acornToolStripMenuItem,
					this->blinkerToolStripMenuItem, this->copperheadToolStripMenuItem, this->diehardToolStripMenuItem, this->gliderToolStripMenuItem,
					this->queenBeeShuttleToolStripMenuItem, this->gosperGliderGunToolStripMenuItem
			});
			this->mapTemplatesToolStripMenuItem->Name = L"mapTemplatesToolStripMenuItem";
			this->mapTemplatesToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->mapTemplatesToolStripMenuItem->Text = L"Map templates";
			// 
			// acornToolStripMenuItem
			// 
			this->acornToolStripMenuItem->Name = L"acornToolStripMenuItem";
			this->acornToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->acornToolStripMenuItem->Text = L"Acorn";
			this->acornToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// blinkerToolStripMenuItem
			// 
			this->blinkerToolStripMenuItem->Name = L"blinkerToolStripMenuItem";
			this->blinkerToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->blinkerToolStripMenuItem->Text = L"Blinker";
			this->blinkerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// copperheadToolStripMenuItem
			// 
			this->copperheadToolStripMenuItem->Name = L"copperheadToolStripMenuItem";
			this->copperheadToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->copperheadToolStripMenuItem->Text = L"Copperhead";
			this->copperheadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// diehardToolStripMenuItem
			// 
			this->diehardToolStripMenuItem->Name = L"diehardToolStripMenuItem";
			this->diehardToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->diehardToolStripMenuItem->Text = L"Diehard";
			this->diehardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// gliderToolStripMenuItem
			// 
			this->gliderToolStripMenuItem->Name = L"gliderToolStripMenuItem";
			this->gliderToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->gliderToolStripMenuItem->Text = L"Glider";
			this->gliderToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// queenBeeShuttleToolStripMenuItem
			// 
			this->queenBeeShuttleToolStripMenuItem->Name = L"queenBeeShuttleToolStripMenuItem";
			this->queenBeeShuttleToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->queenBeeShuttleToolStripMenuItem->Text = L"Queen bee shuttle";
			this->queenBeeShuttleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// gosperGliderGunToolStripMenuItem
			// 
			this->gosperGliderGunToolStripMenuItem->Name = L"gosperGliderGunToolStripMenuItem";
			this->gosperGliderGunToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->gosperGliderGunToolStripMenuItem->Text = L"Gosper Glider Gun";
			this->gosperGliderGunToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::templateToolStripMenuItem_Click);
			// 
			// clearWindowToolStripMenuItem
			// 
			this->clearWindowToolStripMenuItem->Name = L"clearWindowToolStripMenuItem";
			this->clearWindowToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->clearWindowToolStripMenuItem->Text = L"Clear";
			this->clearWindowToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::clear_btn_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(174, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Next iteration";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::NextBtn_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(298, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Previous iteration";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::PrevBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(767, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Set number of FPS:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(872, 27);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(49, 20);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown1_ValueChanged);
			// 
			// newGame_btn
			// 
			this->newGame_btn->Location = System::Drawing::Point(444, 27);
			this->newGame_btn->Name = L"newGame_btn";
			this->newGame_btn->Size = System::Drawing::Size(75, 23);
			this->newGame_btn->TabIndex = 9;
			this->newGame_btn->Text = L"New Game";
			this->newGame_btn->UseVisualStyleBackColor = true;
			this->newGame_btn->Click += gcnew System::EventHandler(this, &MainForm::newGame_btn_Click);
			// 
			// X_numericUpDown2
			// 
			this->X_numericUpDown2->Location = System::Drawing::Point(548, 30);
			this->X_numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->X_numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->X_numericUpDown2->Name = L"X_numericUpDown2";
			this->X_numericUpDown2->Size = System::Drawing::Size(53, 20);
			this->X_numericUpDown2->TabIndex = 10;
			this->X_numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(525, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"X:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(610, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Y:";
			// 
			// Y_numericUpDown2
			// 
			this->Y_numericUpDown2->Location = System::Drawing::Point(633, 30);
			this->Y_numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Y_numericUpDown2->Name = L"Y_numericUpDown2";
			this->Y_numericUpDown2->Size = System::Drawing::Size(53, 20);
			this->Y_numericUpDown2->TabIndex = 13;
			this->Y_numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			// 
			// FPS_number
			// 
			this->FPS_number->AutoSize = true;
			this->FPS_number->Location = System::Drawing::Point(1003, 29);
			this->FPS_number->Name = L"FPS_number";
			this->FPS_number->Size = System::Drawing::Size(39, 13);
			this->FPS_number->TabIndex = 15;
			this->FPS_number->Text = L"FPS: 0";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1073, 582);
			this->Controls->Add(this->FPS_number);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Y_numericUpDown2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->X_numericUpDown2);
			this->Controls->Add(this->newGame_btn);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->stopbtn);
			this->Controls->Add(this->startbtn);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Game of Life";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X_numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Y_numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



};
}

