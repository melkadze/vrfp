//melkadze
#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "functions.h"
using namespace std;

namespace visualrandomfilepicker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::Label^  label1;
	private:


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(124, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(43, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(85, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"How many files to open\?";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(108, 72);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(77, 101);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Regenerate Database";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"vRFP";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		long long int howmany = 0;

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		/* this strange code is because of how visual c++ forms handle variables
		   the function converts the inputted number into a c++ variable         */
		String ^ howmany_m = textBox1->Text;
		string howmany_u = msclr::interop::marshal_as<string>(howmany_m);
		howmany = stoi(howmany_u.c_str());
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//generates a seed for the random number generator, checks for the file's existance, and opens the selected files
		srand(time(NULL));
		fileCheck();
		randomLine(howmany);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		system("dir *.jpg,*.png,*.gif,*.jpeg /b /s > $randomselector.txt");
		/* change this line to modify the files this program will open
		   NOTE: you must change this line in functions.h as well!     */
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}

