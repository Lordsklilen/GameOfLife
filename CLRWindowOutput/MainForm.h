#pragma once
#include "DrawingHelper.h"
#include "../GameEngine/EngineFacade.h"
#include "main.h"
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
		void InitProgram();
		void InitVariables();
		void RedrawBoard();
		void SetConfig(map<string,int>);
		string ChooseSaveFile();
		string ChooseLoadFile();
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveGameStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadGameStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mapTemplatesToolStripMenuItem;

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->mapTemplatesToolStripMenuItem
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
			this->saveGameStateToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveGameStateToolStripMenuItem->Text = L"Save game state";
			this->saveGameStateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveGameStateToolStripMenuItem_Click);
			// 
			// loadGameStateToolStripMenuItem
			// 
			this->loadGameStateToolStripMenuItem->Name = L"loadGameStateToolStripMenuItem";
			this->loadGameStateToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->loadGameStateToolStripMenuItem->Text = L"Load game state";
			this->loadGameStateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::loadGameStateToolStripMenuItem_Click);
			// 
			// mapTemplatesToolStripMenuItem
			// 
			this->mapTemplatesToolStripMenuItem->Name = L"mapTemplatesToolStripMenuItem";
			this->mapTemplatesToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->mapTemplatesToolStripMenuItem->Text = L"Map templates";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1073, 582);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


};
}

