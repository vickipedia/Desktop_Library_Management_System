#pragma once
#include "LoginChange.h"
#include "ModifyBooks.h"
#include "log.h"
namespace Password {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm12 : public System::Windows::Forms::Form
	{
	public:
		MyForm12(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm12()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;


	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(113, 131);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Change Login Credentials";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm12::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(113, 59);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(163, 29);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Modify Book Stock";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm12::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(113, 94);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(163, 31);
			this->button4->TabIndex = 4;
			this->button4->Text = L"See Client Log";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm12::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Green;
			this->label1->Location = System::Drawing::Point(120, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Successfully Logged In!";
			// 
			// MyForm12
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 174);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm12";
			this->Text = L"Admin Interface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
ModifyBooks^ fm=gcnew ModifyBooks();
fm->Show();			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 LoginChange^ frm=gcnew LoginChange();
			 frm->Show();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 log^ frm=gcnew log();
			 frm->Show();
		 }
};
}
