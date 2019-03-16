#pragma once
#include "DrawingHelper.h"
#include "../GameEngine/EngineFacade.h"
#include "main.h"

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
		MainForm(void)
		{
			InitializeComponent();
			InitVariables();
			InitProgram();
		}
		Void startbtn_Click(Object^  sender, EventArgs^  e);
		Void stopbtn_Click(Object^  sender, EventArgs^  e);
		Void pictureBox1_MouseClick(Object^  sender, MouseEventArgs^  e);
		void InitProgram();
		void InitVariables();
		void RedrawBoard();
	protected:

		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		PictureBox^  pictureBox1;
		Button^  startbtn;
		System::ComponentModel::Container ^components;
		Graphics^ graphics;
		Brush^ greenBrush;
		Brush^ grayBrush;
		DrawingHelper^ drawingHelper;
		Button^  stopbtn;
		Label^  label1;
	public:
		System::Windows::Forms::Timer^ myTimer;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->startbtn = (gcnew System::Windows::Forms::Button());
			this->stopbtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1042, 512);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_MouseClick);
			// 
			// startbtn
			// 
			this->startbtn->Location = System::Drawing::Point(13, 13);
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
			this->stopbtn->Location = System::Drawing::Point(94, 12);
			this->stopbtn->Name = L"stopbtn";
			this->stopbtn->Size = System::Drawing::Size(75, 23);
			this->stopbtn->TabIndex = 2;
			this->stopbtn->Text = L"Stop";
			this->stopbtn->UseVisualStyleBackColor = true;
			this->stopbtn->Click += gcnew System::EventHandler(this, &MainForm::stopbtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(942, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Made by Micha� Dela";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1067, 571);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->stopbtn);
			this->Controls->Add(this->startbtn);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainForm";
			this->Text = L"Game of Life";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}

