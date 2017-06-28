#pragma once
#include "addbook.h"
#include "DeleteBook.h"
namespace Password {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ModifyBooks
	/// </summary>
	public ref class ModifyBooks : public System::Windows::Forms::Form
	{
	public:
		ModifyBooks(void)
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
		~ModifyBooks()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button3;
	protected: 

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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(63, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 56);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add New Book";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ModifyBooks::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(63, 124);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(151, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Delete Book";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ModifyBooks::button3_Click);
			// 
			// ModifyBooks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 220);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"ModifyBooks";
			this->Text = L"Modify Books";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 addbook^ obj=gcnew addbook();
				 obj->Show();
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 DeleteBook^ obj=gcnew DeleteBook();
				 obj->Show();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
